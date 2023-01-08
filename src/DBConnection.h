#pragma once
#include <mysql/mysql.h>
#include <string>

class DBConnectionInterface
{
public:
    DBConnectionInterface();
    virtual ~DBConnectionInterface()noexcept;

    virtual bool open() = 0;
    virtual void close() = 0;
    virtual MYSQL_RES* execQuery(const std::string&) = 0;
};

class DBConnection final: public DBConnectionInterface
{
private:
    MYSQL *_mysql;
    const char *_host;
    const char *_userName;
    const char * _password;
    const char *_dbName;
    const unsigned _port;
    const char *_socket;
    const unsigned _flag;
    bool _opened;

public:
    DBConnection(const std::string&, const std::string&, const std::string&, const std::string&, const unsigned,  const std::string&, const unsigned)noexcept;
    DBConnection(const std::string&, const std::string&, const std::string&, const std::string&, const unsigned,  const unsigned)noexcept;
    ~DBConnection();

    bool open() override;
    void close() override;
    MYSQL_RES* execQuery(const std::string&) override;

};