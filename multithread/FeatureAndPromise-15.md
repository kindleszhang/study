# Promise
> "Promise"（承诺）是一种在异步编程中用于表示将来可能会完成的结果的对象。它是一种对未来值的占位符，可以用于表示异步操作的最终结果。

在 C++ 中，Promise 是由 <future> 头文件中的 std::promise 类来表示的。通过 Promise，我们可以在一个线程中设置一个值，并在另一个线程中获取该值。

Promise 提供了两个主要的操作：
1. 设置值（Set value）：通过 set_value 成员函数可以设置 Promise 的值。一旦值被设置，与该 Promise 关联的 Future 对象就可以获取到这个值。

2. 设置异常（Set exception）：通过 set_exception 成员函数可以设置 Promise 的异常。当异常被设置后，与该 Promise 关联的 Future 对象在获取值时将抛出该异常。

以下是一个简单的示例，展示了 Promise 的基本用法：
```
#include <iostream>
#include <future>

void setValue(std::promise<int>& prom) {
    int value = 42;
    prom.set_value(value);
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread t(setValue, std::ref(prom));
    t.join();

    int result = fut.get();
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```
> 上述示例中，我们创建了一个 Promise 对象 prom，并通过 get_future 函数获取与之关联的 Future 对象 fut。然后，我们在另一个线程中使用 set_value 函数设置 Promise 的值为 42。在主线程中，我们使用 get 函数获取 Future 对象的值，并将其打印输出。

> Promise 和 Future 是一对一的关系，通过 Promise 可以设置 Future 对象的值。Promise 对象通常由一个线程设置值，而 Future 对象通常由另一个线程获取值。这种机制在异步编程中非常有用，可以方便地在不同线程之间传递结果和进行同步。


# Future
> "Future"（未来）是异步编程中的一个概念，用于表示一个可能在将来完成的操作的结果。Future 代表了一个异步任务的未来值，可以用于获取异步操作的结果、等待操作完成以及处理可能的异常。

在 C++ 中，Future 是由 <future> 头文件中的 std::future 类来表示的。它与 Promise 相互配合，用于获取 Promise 对象设置的值或处理异常。

Future 提供了以下主要操作：

1. 获取值（Get value）：通过 get 成员函数可以获取 Future 对象关联的值。如果值尚未准备好，调用 get 会阻塞当前线程，直到值可用为止。

2. 等待完成（Wait for completion）：通过 wait 成员函数可以等待 Future 对象关联的操作完成。它会阻塞当前线程，直到异步操作完成为止。

3. 检查状态（Check status）：通过 valid 成员函数可以检查 Future 对象是否与一个有效的异步操作关联。如果 Future 对象与异步操作关联，则返回 true，否则返回 false。

以下是一个简单的示例，展示了 Future 的基本用法：
```
#include <iostream>
#include <future>

int getValue() {
    return 42;
}

int main() {
    std::future<int> fut = std::async(getValue);

    // 等待异步操作完成
    fut.wait();

    // 获取异步操作的结果
    int result = fut.get();
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```
在上述示例中，我们使用 std::async 函数创建了一个异步任务，并将其结果与 Future 对象 fut 关联起来。然后，我们使用 wait 函数等待异步操作完成，并使用 get 函数获取异步操作的结果。

Future 提供了一种方便的方式来处理异步操作的结果，它允许我们在需要结果时等待异步操作完成，并从 Future 对象中获取最终的值。此外，Future 还提供了其他一些功能，如超时等待、异步操作链式调用等，可以根据具体需求进行使用。

# 视频讲解
In this video we will learn about how std::promise and std::future and how they work together to synchronise threads.
Basically std::promise is sent to the called thread and once the value is ready we set that value in promise object, now at calling thread side we get that value using std::future object which was created using std::promise object before sending it to the called thread. And this is how we receive value from one thread to another in synchronisation.