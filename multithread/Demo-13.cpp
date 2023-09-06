#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

long long bankBalance = 0;

std::mutex m;

void addMoney(long long val) {
    // 缺少这一行，会使得bankBalance的结果不可控，100，200，300都有可能
    std::lock_guard<mutex> s(m);

    bankBalance += val;
}

int main() {
    std::thread t1(addMoney, 100);
    std::thread t2(addMoney, 200);

    t1.join();
    t2.join();

    cout << "Finial BankBalance: " << bankBalance << endl;
}