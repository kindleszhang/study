#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money) {
    std::lock_guard<mutex> lg(m);
    balance += money;

    cout << "Amount Added Current money: " << balance << endl;
    cv.notify_one();
}

void withdrowMoney(int money) {
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, []() {return balance != 0;});
    if (balance >= money) {
        balance -=money;
        cout << "Amount Deducted: " << money << endl;
    } else {
        cout << "Amount Can't Be Deducted, Current money less than " << money << endl; 
    }

    cout << "Current money: " << balance << endl;
}

int main() {
    std::thread t1(addMoney, 1000);
    std::thread t2(withdrowMoney, 500);

    t1.join();
    t2.join();

    return 0;

}