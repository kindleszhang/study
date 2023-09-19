#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");

    EXPECT_EQ(7*6, 42);
}

class MyTestFixtures : public ::testing::Test {
protected:
    void SetUp() {
        std::cout << "MyTestFixtures::SetUp()\n"; 
    }
};


TEST_F(MyTestFixtures, ONE) {
    EXPECT_EQ(1, 7-6);
}

int main(int argc, char**argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}