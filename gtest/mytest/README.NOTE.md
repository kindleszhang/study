# Basic concept
+ 1. TestCase
  由多个ASSERT组成。
+ 2. TestSuite
  由一组关联的TestCase组成。
+ 解释
TEST(TestSuiteName, TestCaseName) {

}
这个宏会生成一个继承::testing::Test的TestSuiteName_TestCaseName_Test的类， 即每个TEST宏都是一个::testing::Test的子类。

# Test Fixtures
配置类, 可以为多个Test配置 Before和After时做的事情。
配置类继承::testing::Test，重写SetUp or TearDown或者Con or De.
之后的TEST_F再继承配置类。

# Main and Invoking The Tests
gtest库提供了一个gtest_main作为程序的entry_point, 所以可以不用写main函数。 如果要custom，main里面要return RUN_ALL_TESTS(), 在此之前应该调用::testing::InitGoogleTest(&argc, argv);

RUN_ALL_TESTS的流程。
**When invoked, the RUN_ALL_TESTS() macro:**
+ Saves the state of all GoogleTest flags.

+ Creates a test fixture object for the first test.

+ Initializes it via SetUp().

+ Runs the test on the fixture object.

+ Cleans up the fixture via TearDown().

+ Deletes the fixture.

+ Restores the state of all GoogleTest flags.

+ Repeats the above steps for the next test, until all tests have run.

**If a fatal failure happens the subsequent steps will be skipped.**


# 程序参数
程序参数可以用来控制那些运行和那些不运行。
参数也可以直接写在main函数中。
以下是一些示例用法：

运行特定测试用例：
```
./my_test_binary --gtest_filter=TestCase.TestName
```
这将只运行名为`TestCase.TestName`的测试用例。

运行特定测试用例并排除其他测试用例：
```
./my_test_binary --gtest_filter=TestCase.TestName:AnotherTestCase.*
```
这将只运行名为`TestCase.TestName`的测试用例，并排除了`AnotherTestCase`测试用例下的所有测试。

运行带有特定标记（tag）的测试用例：
```
./my_test_binary --gtest_filter=-tag_name
```
这将运行不带有`tag_name`标记的所有测试用例。

运行带有多个标记（tags）的测试用例：
```
./my_test_binary --gtest_filter=tag1,-tag2
```
这将运行带有`tag1`标记但不带有`tag2`标记的所有测试用例。