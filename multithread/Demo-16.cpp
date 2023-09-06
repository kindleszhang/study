#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <algorithm>


typedef long long int ull;

#define OUTPUT(a) std::cout <<  a << std::endl;
#define OUTPUT2(b) std::cout << #b << " " << b << std::endl;

ull findOdd(ull start, ull end) {
    OUTPUT2(std::this_thread::get_id())
    
    ull OddSum = 0;
    for (ull i = start; i <= end; i++) 
        OddSum += (i&1 ? 0 : i);

    return OddSum;
}


int main() {
    ull start = 0, end = 19000000;
    OUTPUT2(std::this_thread::get_id())
    
    #ifdef ASYNC
        OUTPUT("Thread created if policy is std::launch::async!!")
        std::future<ull> OddFuture = std::async(std::launch::async, findOdd, start, end);
    #else
        OUTPUT("Thread created if policy is std::launch::deferred!!")
        std::future<ull> OddFuture = std::async(std::launch::deferred, findOdd, start, end);
    #endif

    OUTPUT("Waiting For Result!")

    OUTPUT("OddSum: ")
    OUTPUT(OddFuture.get())

    OUTPUT("Completed!")

    return 0;
}