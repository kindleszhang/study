# Sync(同步)

> "Synchronization"（同步）是指协调多个并发执行的线程或进程之间的操作，以确保它们按照预期的顺序和时间进行执行。在并发编程中，同步是为了避免竞态条件（race conditions）、数据竞争（data races）和其他并发问题而进行的一种机制。

> 当多个线程或进程同时访问共享的资源时，如果没有适当的同步机制，可能会导致不确定的行为和错误的结果。同步的目标是保证线程或进程之间的顺序和互斥性，以便它们能够正确地协调和共享数据。

常见的同步机制包括：

1. 互斥锁（Mutex）：互斥锁用于保护共享资源，只允许一个线程或进程访问资源，其他线程或进程必须等待锁释放后才能继续访问。

2. 条件变量（Condition Variable）：条件变量用于在线程之间进行通信和同步，允许线程等待某个条件满足后再继续执行。

3. 信号量（Semaphore）：信号量是一种计数器，用于控制同时访问某个资源的线程或进程数量。

4. 原子操作（Atomic Operations）：原子操作是指不能被中断的操作，可以确保在多线程环境下的原子性操作，避免数据竞争。

> 同步机制的选择取决于具体的应用场景和需求。正确地使用同步机制可以确保线程或进程之间的安全交互和协调，避免竞态条件和数据竞争带来的问题。然而，不正确或过度的同步也可能导致性能下降和死锁等问题，因此需要小心地设计和管理同步机制。

    
```c++
// In this video we will learn how to synchronise multiple threads 
// Few important points to remember for "Thread OR Process Synchronisation" is as follows:
    // 1.0 Thread Or Process synchronize to access critical section.
    // 2.0 Critical section is one or collection of program statements which should be executed by only one thread or process at a time.
//If there is any doubt regarding the video, please let me know in the comment section i would definitely try to solve it.
```