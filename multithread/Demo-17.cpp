#include <iostream>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex mu;
std::condition_variable cv;
std::deque<int> buffer;

const unsigned int maxBufferSize = 20;

#define OUTPUT(a) std::cout << a << std::endl;

void producer(int val) {
    while (val)
    {
        /* code */
        std::unique_lock<std::mutex> locker(mu);
        cv.wait(locker, []() {return buffer.size() < maxBufferSize;});
        
        buffer.push_back(val);

        OUTPUT("Produced: ")
        OUTPUT(val)
        val--; 

        locker.unlock();

        cv.notify_one();
    }
    
}

void consumer() {
    while (true)
    {
        /* code */
        std::unique_lock<std::mutex> locker(mu);
        cv.wait(locker, [](){return buffer.size() > 0;});   
        int val = buffer.back();
        buffer.pop_back();
        OUTPUT("Consumed: ")
        OUTPUT(val)

        locker.unlock();

        cv.notify_one();

    }
    
}

int main() {
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

}