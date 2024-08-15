#pragma once
#include <conio.h>
#include <string>
#include <fstream>

#include "Question.h"
#include "Answer.h"

class Quiz
{
public:
	Quiz() = default;

	Quiz(const std::string& rule) : rule_(rule)
	{
		in_question_.open(rule_ + ".txt");
		in_answer_.open(rule_ + "_odp.txt");
	}

	const Quiz& operator=(const Quiz& quiz)
	{
		rule_ = quiz.rule_;

		in_question_.close();
		in_answer_.close();

		in_question_.open(rule_ + ".txt");
		in_answer_.open(rule_ + "_odp.txt");

		return quiz;
	}

	void read()
	{
		in_question_ >> question_;
		in_answer_ >> answer_;
	}

	void print()
	{
		system("CLS");
		std::cout << question_ << '\n';
	}

	void check()
	{
		system("CLS");

		for (int i = 0; i < answer_.answer().size(); ++i)
		{
			Option::State& answer_state = question_.option()[answer_.answer()[i] - 'a'].state();

			if (Option::State::choosen == answer_state)
			{
				answer_state = Option::State::correct;
			}
			if (Option::State::unchoosen == answer_state)
			{
				answer_state = Option::State::unchoosen_correct;
			}
		}

		for (int i = 0; i < question_.option().size(); ++i)
		{
			if (Option::State::choosen == question_.option()[i].state())
			{
				question_.option()[i].state() = Option::State::incorrect;
			}
		}

		print();
	}

	void execute()
	{
		read();
		print();

		while (true)
		{
			int key = _getch();

			if (27 == key)
			{
				return;
			}
			if ('a' <= key && key <= 'z')
			{
				if (key - 'a' < question_.option().size())
				{
					switch (question_.option()[key - 'a'].state())
					{
					case Option::State::unchoosen:
						question_.option()[key - 'a'].state() = Option::State::choosen;
						break;
					case Option::State::choosen:
						question_.option()[key - 'a'].state() = Option::State::unchoosen;
						break;
					}
					print();
				}
			}
			if (13 == key)
			{
				check();
				(void)_getch();
				if (!in_question_.eof() && !in_question_.eof())
				{
					read();
					print();
				}
				else
				{
					return;
				}
			}
		}
	}

	~Quiz()
	{
		in_question_.close();
		in_answer_.close();
	}
private:
	std::string	rule_ = "";
	std::ifstream in_question_;
	std::ifstream in_answer_;

	Question question_;
	Answer answer_;
};

