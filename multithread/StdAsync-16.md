# std::async
Here we will learn std::async and its usage like how to create task. There are three different launch policy for creating task using std::async are as follows:
1. std::launch::async
2. std::launch::deffered
3. std::launch::async | std::launch::deffered

With the help of above policies std::async decides to create task as asynchronous or synchronous. Please go through video for more details.

# 三种策略
在 C++ 的 <future> 头文件中，std::future 和 std::async 提供了几种执行策略，用于控制异步任务的执行方式。这些执行策略是作为 std::launch 枚举类型的值进行传递的。以下是这些执行策略的介绍：

1. std::launch::deferred：
使用 "deferred" 执行策略时，任务将在调用 get() 成员函数时开始执行，且在同一个线程上执行。
这意味着任务的执行被推迟到了 get() 被调用的时候。
适用于需要在 get() 调用之前对任务进行其他操作（例如条件检查、参数准备等）的情况。

2. std::launch::async：
使用 "async" 执行策略时，任务将立即在新的线程上开始执行。
这意味着任务将在独立的线程中并行执行。
适用于需要立即开始执行任务的情况，可以提高并发性能。
std::launch::deferred | std::launch::async：

3. std::launch::any:
使用 "deferred | async" 执行策略时，系统可以自由选择使用 "deferred" 或 "async" 中的任何一种策略来执行任务。
这意味着在选择执行方式时，系统可以根据具体情况来决定是延迟执行还是立即执行。
这是默认的执行策略。
在使用 std::async 函数时，可以通过将执行策略作为第一个参数传递来指定任务的执行方式。例如：

```c++
std::future<int> fut = std::async(std::launch::async, myFunction); // 使用 async 策略立即执行任务
std::future<int> fut = std::async(std::launch::deferred, myFunction); // 使用 deferred 策略延迟执行任务
std::future<int> fut = std::async(std::launch::any); // 使用 deferred 或 async 策略，由系统决定
```

需要注意的是，执行策略的行为可能因编译器和操作系统的不同而有所差异。因此，在选择执行策略时，需要仔细考虑任务的性质、性能需求和代码的可移植性。