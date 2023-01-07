#include <mysql/mysql.h>
#include <string>

#include "DBConnection.h"

DBConnectionInterface::DBConnectionInterface()
{
}

DBConnectionInterface::~DBConnectionInterface() noexcept
{
}

DBConnection::DBConnection(const std::string &host, const std::string &userName, const std::string &password, const std::string &dbName, const unsigned port, const std::string &socket, const unsigned flag = 0)noexcept:
_mysql(mysql_init(nullptr)),_host(host.c_str()),_userName(userName.c_str()),_password(password.c_str()),_dbName(dbName.c_str()),_port(port),_socket(socket.c_str()),_flag(flag),_opened(false)
{
}

DBConnection::DBConnection(const std::string &host, const std::string &userName, const std::string &password, const std::string &dbName, const unsigned port = 0, const unsigned flag = 0)noexcept:
_mysql(mysql_init(nullptr)),_host(host.c_str()),_userName(userName.c_str()),_password(password.c_str()),_dbName(dbName.c_str()),_port(port),_socket(nullptr),_flag(flag),_opened(false)
{
}

DBConnection::~DBConnection()
{
    close();
}

bool DBConnection::open()
{
    if(!_opened)
    {
        _opened = mysql_real_connect(_mysql, _host, _userName, _password, _dbName, _port, _socket, _flag);
    }

    return _opened;
}

void DBConnection::close()
{
    if(_opened)
    {
        mysql_close(_mysql);
        _opened = false;
    }
}

MYSQL_RES* DBConnection::execQuery(const std::string &query)
{
    return mysql_query(_mysql, query.c_str()) ? nullptr : mysql_store_result(_mysql);
}