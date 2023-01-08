#include <iostream>
#include "DBConnection.h"
#include "ClassThatUsesDB.h"

int main()
{

    DBConnection connection("localhost", "sfchat", "sfchatpassword", "sfchatdb", 0, 0);
    ClassThatUsesDB db_user(&connection);

    if(db_user.openConnection())
    {
        db_user.useConnection();
        db_user.closeConnection();
    }
    else
    {
        std::cout << "Connection failed" << std::endl;
    }


    return 0;
}