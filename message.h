#pragma once
#include <iostream>
#include <string>

class Message
{
	std::string _from;
	std::string _to;
	std::string _message;

public:
	Message();
	Message(const std::string& from, const std::string& to, const std::string& message);
	~Message();

	const std::string& getFrom() const;
	void setFrom(std::string& from);
	const std::string& getTo() const;
	void setTo(std::string& to);
	const std::string& getMessage() const;
	void setMessage(std::string& message);
};