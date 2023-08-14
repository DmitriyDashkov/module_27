#include "DBConsChat.h"

DBConsChat::DBConsChat()
{
    init();
}

void DBConsChat::init()
{
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
        completed();
    if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
        completed();
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
        completed();

    std::cout << "Attempting connection to SQL Server...\n";

    switch (SQLDriverConnect(sqlConnHandle,
        GetDesktopWindow(),
        (SQLWCHAR*)L"DRIVER={MySQL ODBC 8.0 ANSI Driver};SERVER=localhost;PORT=3306;DATABASE=conschat;UID=root;PWD=0320;",
        //(SQLWCHAR*)L"DRIVER={PostgreSQL ANSI};SERVER=localhost;PORT=5432;DATABASE=conschat;UID=root;PWD=0320;",
        SQL_NTS,
        retconstring,
        1024,
        NULL,
        SQL_DRIVER_COMPLETE)) {

    case SQL_SUCCESS:
    case SQL_SUCCESS_WITH_INFO:
        std::cout << "Successfully connected to SQL Server \n";
        break;

    case SQL_INVALID_HANDLE:
    case SQL_ERROR:
        std::cout << "Could not connect to SQL Server \n;";
        completed();

    default:
        break;
    }

    //Если соединение не установлено, то выходим из программы
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
        completed();
    std::cout << "\nExecuting T-SQL query...\n";
}

void DBConsChat::completed()
{
    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}

void DBConsChat::addUser(std::string n)
{
    SQLWCHAR SQL[] = L"INSERT INTO chatusers(name) VALUES ('newUser')";
    //SQLWCHAR SQL[] = L"delete from users where id = 1";
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle,
        SQL,
        SQL_NTS)) {
        //std::cout << "Error querying SQL Server2 \n";
        completed();
    }
}