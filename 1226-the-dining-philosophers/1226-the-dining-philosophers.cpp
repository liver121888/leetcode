
// only when both forks in hand then start eating
// after eating put down the forks

// each fork is a lock

// use philosopher id to find the fork ids he 
// is trying to use
// pick left and pick right
// once both picked, eat
// after eating put down left put down right
// cv notify all

// 5 cv for threads
// actually we only neeed one cv, because all ppl are waiting
// for the same wake up req
// so single cv, and a vector of bool to see if the fork is taken

#include <condition_variable>
#include <mutex>


// 同時只能有一個人吃因為我們把整個吃的流程鎖了
// class DiningPhilosophers {
// public:

//     // instead use only a cv
//     // notify all on bool
//     // ppl just fight over the fork
//     mutex mtx;
//     condition_variable cv;
//     vector<bool> forksTaken = vector<bool>(5, false);

//     DiningPhilosophers() {

//     }

//     void wantsToEat(int philosopher,
//                     function<void()> pickLeftFork,
//                     function<void()> pickRightFork,
//                     function<void()> eat,
//                     function<void()> putLeftFork,
//                     function<void()> putRightFork) {


//         unique_lock<mutex> lock(mtx);

//         int rightFork = ((philosopher - 1) + 5) % 5;
//         int leftFork = philosopher;

//         // if both not taken
//         cv.wait(lock, [=, this](){
//             return !forksTaken[rightFork] && !forksTaken[leftFork];
//         });

//         // take both forks
//         forksTaken[rightFork] = true;
//         forksTaken[leftFork] = true;

//         pickLeftFork();
//         pickRightFork();
//         eat();
//         putLeftFork();
//         putRightFork();

//         // put down both forks
//         forksTaken[rightFork] = false;
//         forksTaken[leftFork] = false;

//         // notify other ppl
//         cv.notify_all();

//     }
// };




// 正確流程應該是：
// 拿到叉子後就應該先解鎖，再吃

// 上鎖
// 等到左右叉都可用
// 把兩支叉標記成 taken
// 解鎖
// pickLeftFork / pickRightFork / eat / put...
// 再上鎖
// 把兩支叉標記成 free
// 解鎖
// notify_all

// 這樣別人才有機會同時進來吃。
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

        // 重点：这里先解锁，让别人可以并发检查/吃饭
        lock.unlock();

        // 實際pick放在後面，因為有bool保護所以沒事
        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        // 吃完再上锁，释放叉子
        lock.lock();

        // put down both forks
        forksTaken[rightFork] = false;
        forksTaken[leftFork] = false;

        lock.unlock();

        // notify other ppl
        cv.notify_all();

    }
};

