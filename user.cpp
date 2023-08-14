#include "user.h"

bool chInRange(char ch)
{
    return ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));   //диапазон 65-90 и 97-122
}

vector<string> wordsFromMessage(string message)    //разбивка сообщения на слова
{
    message += '#';
    vector<string> list;
    string tmp;
    for (size_t i = 0; i < message.length(); i++) {
        if (chInRange(message[i])) {
            tmp += message[i];
        }
        else {
            if (tmp != "")
                list.push_back(tmp);
            tmp = "";
        }
    }
    return list;
}

User::User() = default;
User::User(const std::string& login, const std::string& password, const std::string& name) :
    _login(login), _password(password), _name(name)
{
    dictionary = new Trie;
}
User::~User() = default;

std::string User::getUserLogin() const { return _login; }
std::string User::getUserPassword() const { return _password; }
void User::setUserPassword(std::string& password) { _password = password; }
std::string User::getUserName() const { return _name; }
void User::setUserName(std::string& name) { _name = name; }

void User::insertWordsToDictionary(string message)
{
    vector<string> list = wordsFromMessage(message);
    for (size_t i = 0; i < list.size(); i++) {
        string tmp = list.at(i);
        if (!dictionary->search(tmp)) {
            dictionary->insert(tmp);
        }
    }

}

void User::getUserDictionary() const
{
    dictionary->printWords();
}

