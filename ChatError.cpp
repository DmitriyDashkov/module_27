#include "ChatError.h"

ChatError::ChatError(int num) : m_numError(num) {}

int ChatError::NumError() const { return m_numError; }

const std::string ChatError::Message(int i) const { return m_message[i]; }

const char* ChatError::what() const noexcept
{
    return m_message[m_numError].c_str();
}