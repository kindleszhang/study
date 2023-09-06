#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

std::mutex m1;
std::mutex m2;

    // m1,m2在thread1和2中加锁顺序不一样的话会造成死锁
void thread1() {

    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m2.lock();
    cout << "thread1()" << endl;  
    m1.unlock();
    m2.unlock();
}

void thread2() {
    // 这种情况会造成死锁
    // m2.lock();
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    // m1.lock();
 
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m2.lock();
    cout << "thread2()" << endl;  
    m2.unlock();
    m1.unlock();
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
    return 0;

}