#include <mutex>
#include <atomic>

using namespace std;

class Foo {
public:

    atomic<bool> firstCalled;
    atomic<bool> secondCalled;
    Foo() {
        // mutex mtx;
        firstCalled = false;
        secondCalled = false;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstCalled = true;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while (!firstCalled) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        printSecond();
        secondCalled = true;
        
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while (!firstCalled || !secondCalled) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        printThird();
    }
};