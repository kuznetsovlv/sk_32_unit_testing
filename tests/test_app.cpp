#include "../src/DBConnection.h"
#include "../src/ClassThatUsesDB.h"
#include <gtest/gtest.h>

TEST(Test, Test_test)
{
    DBConnection connection("localhost", "sfchat", "sfchatpassword", "sfchatdb", 0, 0);
    ASSERT_EQ(0, 0);
}