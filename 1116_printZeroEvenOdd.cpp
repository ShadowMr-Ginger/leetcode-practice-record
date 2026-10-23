#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Solution1116 {
public:
    Solution1116(int n) {
        this->n = n;
    }

    // zero 线程：每个数前先打印一次 0
    void zero(function<void(int)> printNumber) {
        for (int i = 1;i <= n;i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&] { return state == 0; });
            printNumber(0);
            // 1. 根据当前序号决定接下来打印奇数还是偶数
            state = (i % 2 == 1) ? 1 : 2;
            cv.notify_all();
        }
    }

    // even 线程：打印所有偶数
    void even(function<void(int)> printNumber) {
        for (int i = 2;i <= n;i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&] { return state == 2; });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }

    // odd 线程：打印所有奇数
    void odd(function<void(int)> printNumber) {
        for (int i = 1;i <= n;i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&] { return state == 1; });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }

private:
    int n;
    int state = 0; // 0 打印 0，1 打印奇数，2 打印偶数
    mutex mtx;
    condition_variable cv;
};

//int main() {
//	int n = 5;
//	Solution1116 zeo(n);
//	thread t1(&Solution1116::zero, &zeo, [](int x) { cout << x; });
//	thread t2(&Solution1116::even, &zeo, [](int x) { cout << x; });
//	thread t3(&Solution1116::odd, &zeo, [](int x) { cout << x; });
//	t1.join();
//	t2.join();
//	t3.join();
//	cout << endl; // 输出 0102030405
//	return 0;
//}
