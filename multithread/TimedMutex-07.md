In this video we will learn about "Timed Mutex In C++ Threading (std::timed_mutex)"
We have learned Mutex, Race Condition, Critical Section in previous videos.
And few points to remember about timed mutex is as follows:
0. std::timed_mutex is blocked till timeout_time or the lock is acquired and returns true if success 
   otherwise false.
1. Member Function:
   a. lock 
   b. try_lock
   c. try_lock_for    ---\ These two functions makes it different from mutex.
   d. try_lock_until  ---/ 
   e. unlock

EXAMPLE: try_lock_for();
Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
On successful lock acquisition returns true, otherwise returns false.