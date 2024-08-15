#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Answer
{
public:
	std::string& number()
	{
		return number_;
	}
	const std::string& number() const
	{
		return number_;
	}

	std::string& answer()
	{
		return answer_;
	}
	const std::string& answer() const
	{
		return answer_;
	}

	std::string& rules()
	{
		return rules_;
	}
	const std::string& rules() const
	{
		return rules_;
	}
protected:
	friend std::ifstream& operator>>(std::ifstream& in, Answer& answer)
	{
		std::getline(in, answer.number_);
		std::getline(in, answer.answer_);
		std::getline(in, answer.rules_);

		std::string tmp = "";

		std::getline(in, tmp);

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Answer& answer)
	{
		out << answer.number_ << '\n' << answer.answer_ << '\n' << answer.rules_;
		
		return out;
	}
private:
	std::string number_ = "";
	std::string answer_ = "";
	std::string rules_ = "";
};

