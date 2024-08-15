#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class Option
{
public:
	enum class State
	{
		unchoosen = 7,
		choosen = 8,
		correct = 2,
		incorrect = 4,
		unchoosen_correct = 3
	};

	Option(const std::string& option_) : option_(option_) {}

	std::string& option()
	{
		return option_;
	}
	const std::string& option() const
	{
		return option_;
	}

	State& state()
	{
		return state_;
	}
	const State& state() const
	{
		return state_;
	}
protected:
	friend std::ostream& operator<<(std::ostream& out, const Option& option)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, static_cast<WORD>(option.state_));

		out << option.option_;

		SetConsoleTextAttribute(hConsole, static_cast<WORD>(Option::State::unchoosen));

		return out;
	}
private:
	std::string option_;
	State state_ = State::unchoosen;
};

