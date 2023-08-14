#pragma once
#include <string>

class ChatError : public std::exception
{
private:
    int m_numError;
    const std::string m_message[1]{
                                "Incorrect access by index"     //0
    };
public:
    ChatError() = default;
    ChatError(int num);
    int NumError() const;
    const std::string Message(int i) const;
    virtual const char* what() const noexcept override;
};