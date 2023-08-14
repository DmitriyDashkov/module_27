#pragma once
#include "user.h"
#include "Message.h"
#include "ChatError.h"
#include "DBConsChat.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>
#include <limits>
#include <windows.h>
#include <chrono>
#include "Logger.h"

class Chat
{
private:
    std::string _name;                               //��� ����
    std::vector<std::shared_ptr<User>> _users;       //������������ ����
    std::vector<std::shared_ptr<Message>> _messages; //��� ���������
    std::shared_ptr<User> _curentUserName = nullptr;

public:
    Chat(std::string n);
    ~Chat();

    void working();                                         //������ ����
    void createUser();                                      //������� �����
    std::shared_ptr<User> getCurentUserName() const;        //������� ��� ������������
    void chatEntry();                                       //���� � ���
    void workingUser();                                     //������ ���� �� �����
    std::shared_ptr<User> getHavingLogin(const std::string& name) const;//������� ������
    std::shared_ptr<User> getHavingName(const std::string& name) const;//������� �����
    void readMessages();                                    //������ ���������
    void writeMessage();                                    //�������� ���������
    void userInfo();
    void showUserInfo(unsigned int);
    std::vector<std::shared_ptr<User>> users() { return _users; }
    DBConsChat *db;
    Logger* logger;
    void write_message_to_logger(std::shared_ptr<Message> message);
    void showUserPosts();

};

