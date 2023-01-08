#include <string>
#include <mysql/mysql.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/DBConnection.h"
#include "../src/ClassThatUsesDB.h"


class MockDBConnection: public DBConnectionInterface
{
public:
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(void, close, (), (override));
    MOCK_METHOD(MYSQL_RES*, execQuery, (const std::string &query), (override));
};

TEST(Test_ClassThatUsesDB, Open_connection)
{
    MockDBConnection connection;

    EXPECT_CALL(connection, open).Times(::testing::AtLeast(1));
    EXPECT_CALL(connection, close).Times(::testing::AtLeast(1));

    ClassThatUsesDB db_user(&connection);
    db_user.openConnection();
}

TEST(Test_ClassThatUsesDB, Use_connection)
{
    MockDBConnection connection;

    EXPECT_CALL(connection, execQuery).Times(::testing::AtLeast(1));
    EXPECT_CALL(connection, close).Times(::testing::AtLeast(1));

    ClassThatUsesDB db_user(&connection);
    db_user.useConnection();
}

TEST(Test_ClassThatUsesDB, Close_connection)
{
    MockDBConnection connection;

    EXPECT_CALL(connection, close).Times(::testing::AtLeast(2));

    ClassThatUsesDB db_user(&connection);
    db_user.closeConnection();
}