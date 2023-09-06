#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <thread>
#include <chrono>

using namespace std;
#define OUT(a) cout << a << endl;
#define OUTD(a) cout << #a << " " << a << endl;

static int s = 0;
mutex m;
void add() {
    int c = 1000;
    while(c--) {
        // 会出问题
        m.lock();
        s++;
        m.unlock();
    }
    OUTD(s)
}

int main () {
    thread t1(add);
    thread t2(add);

    t1.join();
    t2.join();
}