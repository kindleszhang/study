> std::lock 是 C++ 标准库 <mutex> 头文件中定义的一个函数模板，用于在多个互斥量上进行原子化的加锁操作。

> 在多线程编程中，当需要同时操作多个互斥量时，为了`避免死锁`和`竞态条件`，需要按照特定的顺序对互斥量进行加锁。std::lock 函数提供了一种方便的方式，可以一次性对多个互斥量进行加锁，并确保没有死锁发生。

## 1. 语法
std::lock 函数的语法如下：
```
template <class Mutex1, class Mutex2, class... Mutexes>
void lock(Mutex1& m1, Mutex2& m2, Mutexes&... m);
```

## 2. Block call
它接受多个互斥量作为参数，并按照它们在参数列表中的顺序进行加锁。如果无法立即获得所有互斥量的锁，则 std::lock 会阻塞当前线程，直到所有互斥量都成功加锁为止。
std::lock 函数的关键特性是它能够避免死锁。它会使用一种算法来确保按照固定的顺序对互斥量进行加锁，从而避免了多个线程之间的死锁情况。

## 3. Example
```c++
// 以下是一个示例，演示如何使用 std::lock 函数：
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex1;
std::mutex mutex2;

void threadFunction() {
    std::lock(mutex1, mutex2); // 对 mutex1 和 mutex2 进行加锁

    // 执行需要保护的代码块
    std::cout<< "threadFunction" << std::endl;
    mutex1.unlock();
    mutex2.unlock();
}

int main() {
    std::thread t(threadFunction);

    // 对 mutex1 和 mutex2 进行加锁的顺序与线程函数中的顺序保持一致
    std::lock(mutex1, mutex2);

    // 执行需要保护的代码块
    std::cout<< "main" << std::endl;

    mutex1.unlock();
    mutex2.unlock();

    t.join();

    return 0;
}
```

在上述示例中，std::lock(mutex1, mutex2) 会以统一的顺序对 mutex1 和 mutex2 进行加锁，从而避免了潜在的死锁问题。这样，多个线程就可以安全地访问被保护的代码块，而不会出现竞态条件或死锁。


## 4. 视频注释
```
In this video we will learn how to avoid deadlocks in cpp programming language:
std::lock() In C++11 It is used to lock multiple mutex at the same time.

And the syntax is as follow:
std::lock(m1, m2, m3, m4);
1. All arguments are locked via a sequence of calls to lock(),  try_lock(), or unlock() on each argument.
2. Order of locking is not defined (it will try to lock provided mutex in any order and ensure that
    there is no dead lock).
3. It is a blocking call.

[Example:0] -- No deadlock.
    Thread 1                    Thread 2
    std::lock(m1,m2);           std::lock(m1,m2);

[Example:1] -- No deadlock. 

    Thread 1                    Thread 2
    std::lock(m1, m2);          std::lock(m2, m1);

[Example:2] -- No deadlock. 

    Thread 1                    Thread 2
    std::lock(m1, m2, m3, m4);  std::lock(m3, m4);
                                std::lock(m1, m2);

[Example:3] -- Yes, the below can deadlock. 

    Thread 1                    Thread 2
    std::lock(m1,m2);           std::lock(m3,m4);
    std::lock(m3,m4);           std::lock(m1,m2);
```