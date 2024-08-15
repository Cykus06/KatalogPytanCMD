#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "Option.h"

class Question
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

	std::string& question()
	{
		return question_;
	}
	const std::string& question() const
	{
		return question_;
	}

	std::vector<Option>& option()
	{
		return option_;
	}
	const std::vector<Option>& option() const
	{
		return option_;
	}
protected:
	friend std::ifstream& operator>>(std::ifstream& in, Question& question)
	{
		question.number_ = "";
		question.question_ = "";
		question.option_.clear();

		in >> question.number_;
		in.ignore();
		std::getline(in, question.question_);
		std::string tmp = "";
		while (std::getline(in, tmp) && tmp != "")
		{
			question.option_.push_back(Option(tmp));
		}

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Question& question)
	{
		out << question.number_ << '\n' << question.question_ << '\n';

		for (int i = 0; i < question.option_.size(); ++i)
		{
			out << question.option_[i] << '\n';
		}

		return out;
	}
private:
	std::string number_ = "";
	std::string question_ = "";
	std::vector<Option> option_;
};