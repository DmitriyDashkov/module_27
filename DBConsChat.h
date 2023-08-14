#pragma once

#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

constexpr auto SQL_RESULT_LEN = 240;
constexpr auto SQL_RETURN_CODE_LEN = 1024;

class DBConsChat
{
private:
    

public:
    SQLHANDLE sqlConnHandle{ nullptr }; //���������� ��� ���������� � ����� ������
    SQLHANDLE sqlEnvHandle{ nullptr }; //���������� ��������� ���� ������
    SQLHANDLE sqlStmtHandle{ nullptr }; //���������� ��� ���������� �������� � ���� ������
    SQLWCHAR retconstring[SQL_RETURN_CODE_LEN]{}; //������ ��� ���� �������� �� ������� API ODBC
    DBConsChat();
    void init();
    void completed();
    void addUser(std::string name);


};

