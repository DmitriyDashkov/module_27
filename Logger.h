#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <shared_mutex>
#include <vector>

using namespace std;

class Logger
{
private:
	shared_mutex shared_mutex;

public:
	Logger(string directory);
	~Logger();
	string dir;
	std::ofstream out;										// ����� ��� ������
	std::ifstream file;										// ����
	void write_to_file(string message);						//������ ��������� � ���
	void read_user_message_from_file(string user_name);
	vector<string> user_messages_from_file(string user_name);				//������ ��������� ����������� �����
};

