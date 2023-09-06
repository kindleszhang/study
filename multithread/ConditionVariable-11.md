In this video we will learn how to use "Condition Variable In C++ Threading".
Few important points to remember while using "condition variables" are as follows:
1. Condition variables allow us to synchronise threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronise two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition

For more please watch full video and do let me know if you have any doubts in the comment section.




## wati() 
当调用std::condition_variable的wait()函数时，线程会进入等待状态，同时会做以下几件事情：

   1. 自动释放互斥锁：在调用wait()函数之前，线程必须先获取互斥锁（通常是std::unique_lock对象），wait()函数会自动释放该互斥锁，以允许其他线程在此期间获取该互斥锁并修改共享数据。

1. 等待条件变量通知：线程进入等待状态，等待条件变量的通知。条件变量的通知可以通过其他线程调用相同条件变量对象的notify_one()或notify_all()函数来发送。

2. 阻塞线程：线程被阻塞，暂停执行，直到以下情况之一发生：

    + 收到通知：其他线程调用相同条件变量对象的notify_one()或notify_all()函数，向等待的线程发送通知，唤醒其中一个或全部线程。
    + 虚假唤醒（spurious wake-up）：在没有显式通知的情况下，线程可能会被唤醒。这种情况是可能发生的，因此在收到通知后，需要再次检查条件是否满足。

3. 重新获取互斥锁：当线程被唤醒后，会重新尝试获取之前释放的互斥锁。一旦成功获取互斥锁，线程可以继续执行。

总结起来，wait()函数的目的是使线程在等待某个条件满足时暂时阻塞，以避免不必要的轮询，节省系统资源。等待期间，线程会释放互斥锁，允许其他线程执行，并在满足特定条件的通知到来时被唤醒。

需要注意的是，wait()函数应该在持有互斥锁的情况下调用，以确保在进入等待状态之前释放互斥锁。这样可以避免死锁和竞态条件的发生。

## notify_one() 和 notify_all() 
std::condition_variable提供了两个成员函数用于发送通知给等待的线程：notify_one()和notify_all()。

+ notify_one()函数用于通知等待在条件变量上的一个线程。如果有多个线程在等待，只会唤醒其中一个线程（通常是先等待的线程）。
+ notify_all()函数用于通知等待在条件变量上的所有线程，唤醒它们继续执行。

+ 这些通知的目的是告知等待的线程，某些共享状态或条件已经发生变化，它们可以检查条件是否满足，然后决定是否继续执行或重新等待。