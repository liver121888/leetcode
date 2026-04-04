
// only when both forks in hand then start eating
// after eating put down the forks

// each fork is a lock

// use philosopher id to find the fork ids he is trying to use
// pick left and pick right
// once both picked, eat
// after eating put down left put down right
// cv notify all

// 5 cv for threads

#include <condition_variable>
#include <mutex>

class DiningPhilosophers {
public:


    // instead use only a cv
    // notify all on bool
    // ppl just fight over the fork
    mutex mtx;
    condition_variable cv;
    vector<bool> forksTaken = vector<bool>(5, false);

    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {


        unique_lock<mutex> lock(mtx);

        int rightFork = ((philosopher - 1) + 5) % 5;
        int leftFork = philosopher;

        // if both not taken
        cv.wait(lock, [=, this](){
            return !forksTaken[rightFork] && !forksTaken[leftFork];
        });

        // take both forks
        forksTaken[rightFork] = true;
        forksTaken[leftFork] = true;

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        // put down both forks
        forksTaken[rightFork] = false;
        forksTaken[leftFork] = false;

        // notify other ppl
        cv.notify_all();

    }
};