#include "Logger.h"


Logger::Logger(string s) : dir(s)
{
	out.open(dir, std::ios::app);				//открытие файла для записи в конец
    file.open(dir, ios::in);
}

Logger::~Logger()
{
    out.close();
    file.close();
}
void Logger::write_to_file(string message)
{
    shared_mutex.lock();
    if (out.is_open())
    {
        out << message << std::endl;
    }
    else {
        std::cout << "Log not created. Could not open file." << std::endl;
    }
    shared_mutex.unlock();
}

void Logger::read_user_message_from_file(string user_name)
{
    shared_mutex.lock_shared();
    if (file.is_open())
    {
        vector<string> vec = user_messages_from_file(user_name);
        cout << "Messages of user:" << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec.at(i) << endl;
        }
    }
    else
    {
        cout << "Could not open file" << endl;
    }
    shared_mutex.unlock_shared();
}

vector<string> Logger::user_messages_from_file(string user_name)
{   
    string var1 = user_name; var1 += " ------> ";
    string var2 = " ------> "; var2 += user_name;
    vector<string> vec;
    string tmpline;
    while (getline(file, tmpline))
    {
        const char* found1 = strstr(tmpline.c_str(), var1.c_str());
        const char* found2 = strstr(tmpline.c_str(), var2.c_str());
        if (found1 || found2) vec.push_back(tmpline);
    }

    return vec;
}