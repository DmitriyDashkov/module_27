#include "Message.h"

Message::Message() = default;
Message::Message(const std::string& from, const std::string& to, const std::string& message) : _from(from), _to(to), _message(message) {}
Message::~Message() = default;

const std::string& Message::getFrom() const { return _from; }
void Message::setFrom(std::string& from) { _from = from; }
const std::string& Message::getTo() const { return _to; }
void Message::setTo(std::string& to) { _to = to; }
const std::string& Message::getMessage() const { return _message; }
void Message::setMessage(std::string& message) { _message = message; }
