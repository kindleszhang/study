In this video we will learn how to use unique_lock In C++ programming language.
Few important points to remember about the unique_lock is as follows:

1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
    a. Can Have Different Locking Strategies
    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables. (See this in coming videos)

## Locking Strategies
   TYPE           EFFECTS(S)
1. defer_lock  do not acquire ownership of the mutex.
2. try_to_lock  try to acquire ownership of the mutex without blocking.
3. adopt_lock  assume the calling thread already has ownership of the mutex.


# ChatGPT
std::unique_lock 是 C++ 标准库提供的一种互斥锁封装工具。它提供了更灵活的锁定和解锁机制，比起简单的 std::lock_guard 更具可变性。

std::unique_lock 提供了以下主要特性：

1. 灵活性：std::unique_lock 支持可锁定和可解锁操作，这意味着你可以根据需要手动控制锁的状态。你可以在构造函数中指定锁定策略（如 std::defer_lock、std::try_to_lock 或 std::adopt_lock），或者在运行时使用成员函数 lock() 和 unlock() 进行锁定和解锁。

2. 所有权转移：std::unique_lock 对象可以拥有锁的所有权，这意味着你可以将它们传递给其他函数或线程，并在适当的时候释放锁。这种特性对于实现复杂的锁定和解锁逻辑非常有用。

3. 条件变量支持：std::unique_lock 可以与条件变量（std::condition_variable）一起使用，以实现线程之间的同步。它提供了成员函数 wait()、wait_for() 和 wait_until()，用于在等待条件满足时释放锁，并在条件满足或超时后重新获得锁。

使用 std::unique_lock 可以避免手动管理锁的状态，提供更灵活的锁定机制，并支持条件变量的使用，从而更好地控制多线程环境中的资源访问。

下面是一个简单的示例，展示了 std::unique_lock 的基本用法：


```c++
#include <mutex>

std::mutex mtx;

void someFunction()
{
    std::unique_lock<std::mutex> lock(mtx); // 锁定互斥量
    // 这里可以安全地访问受锁保护的资源

    // 在需要的时候手动解锁
    lock.unlock();

    // 这里可以进行一些无需锁保护的操作

    // 在适当的时候重新锁定
    lock.lock();

    // 继续访问受锁保护的资源

} // `lock` 在 `someFunction` 结束时自动释放锁
```
希望这个简要介绍能帮助你理解 std::unique_lock 的基本概念和用法。如有进一步的疑问，请随时提问。