#pragma once
#include "DBConnection.h"

class ClassThatUsesDB final
{
private:
    DBConnectionInterface *_connection;

public:
    ClassThatUsesDB(DBConnectionInterface*);
    ~ClassThatUsesDB();

    bool openConnection();
    void useConnection();
    void closeConnection();
};