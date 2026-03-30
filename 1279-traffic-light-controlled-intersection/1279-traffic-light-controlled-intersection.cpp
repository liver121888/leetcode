
// Turning the light green on a road when it was already green is considered a wrong answer.
// road 1 and 2 is a pair 3 and 4 is another pair
// we need a bool to save the state
// if roadId is 1 or 2 wait till the bool
// if roadId are 3 or 4 wait till the bool
// after the car pass set the other road's light to green

// first thread needs to set green
// last thread needs to set the other road green
// do we need 2 cv?
// 

#include <iostream>
#include <mutex>
#include <condition_variable>

class TrafficLight {
public:

    bool isRoadAGreen = true;

    // sigle lock
    mutex mtx;

    // 為什麽不用condition_variable等
    // 因為題目沒有要求要batch通過
    // 所以就是車到把它設成綠燈通過就行

    TrafficLight() {
        
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {

        unique_lock<mutex> lock(mtx);

        // check for direction to know which road it should wait for green
        if (roadId == 1) {
            if (!isRoadAGreen) {
                isRoadAGreen = true;
                turnGreen();
            }
            crossCar();
        } else {
            if (isRoadAGreen) {
                isRoadAGreen = false;
                turnGreen();
            }
            crossCar();
        }
    }
};
