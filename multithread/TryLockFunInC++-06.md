In this video we will learn how to use std::try_lock() On Mutex In C++11 Threading

Few things to remember about the try_lock is as follows:
0. std::try_lock() tries to lock all the mutex passed in it one by one in given order.
1. On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.
