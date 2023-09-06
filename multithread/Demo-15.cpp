#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <algorithm>

typedef long long int ull;

#define OUTPUT(a) std::cout <<  a << std::endl;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {
    ull OddSum = 0;

    for (ull i = start;  i <= end; i++) 
        OddSum += (i&1 ? 0 : i);

    OddSumPromise.set_value(OddSum);
}


int main() {
    ull start = 0, end = 19000000;

    std::promise<ull> OddSum;
    std::future<ull> OddFuture = OddSum.get_future();
    
    OUTPUT("Thread Created!")
    std::thread t1(findOdd, std::move(OddSum), start, end);

    OUTPUT("Waiting For Result!")

    OUTPUT("OddSum: ")
    OUTPUT(OddFuture.get())

    OUTPUT("Completed!")

    t1.join();

    return 0;



}