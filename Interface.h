#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <Windows.h>

#include "Quiz.h"

class Interface
{
public:
	static constexpr int RULES_SIZE = 19;

	const char* RULES[RULES_SIZE] = {
			"PRZEPIS 1 BOISKO DO GRY",
			"PRZEPIS 2 CZAS GRY, SYGNA£ KOÑCOWY, ZATRZYMANIE CZASU GRY",
			"PRZEPIS 3 PI£KA",
			"PRZEPIS 4 DRU¯YNA, ZMIANY, WYPOSA¯ENIE, KONTUZJE ZAWODNIKA",
			"PRZEPIS 5 BRAMKARZ",
			"PRZEPIS 6 POLE BRAMKOWE",
			"PRZEPIS 7 GRA PI£K¥, GRA PASYWNA",
			"PRZEPIS 8 FAULE I NIESPORTOWE ZACHOWANIE",
			"PRZEPIS 9 ZDOBYCIE BRAMKI",
			"PRZEPIS 10 RZUT ROZPOCZYNAJ¥CY GRÊ",
			"PRZEPIS 11 RZUT Z LINII BOCZNEJ",
			"PRZEPIS 12 RZUT OD BRAMKI",
			"PRZEPIS 13 RZUT WOLNY",
			"14 RZUT KARNY",
			"15 OGÓLNE ZASADY WYKONYWANIA RZUTÓW(ROZPOCZYNAJ¥CEGO GRÊ, Z LINII BOCZNEJ, OD BRAMKI, WOLNEGO, KARNEGO)",
			"16 KARY 37",
			"17 SÊDZIOWIE",
			"18 MIERZ¥CY CZAS I SEKRETARZ",
			"REGULAMIN STREFY ZMIAN"
	};

	constexpr Interface() = default;

	void execute()
	{
		while (true)
		{
			system("CLS");
			std::cout << *this;

			int key = _getch();

			switch (key)
			{
			case 27:
				return;
			case 72:
				--cursor_position_;
				if (-1 == cursor_position_)
				{
					cursor_position_ = RULES_SIZE - 1;
				}
				break;
			case 80:
				++cursor_position_;
				if (RULES_SIZE == cursor_position_)
				{
					cursor_position_ = 0;
				}
				break;
			case 13:
				if (cursor_position_ <= 17)
				{
					quiz_ = Quiz(std::to_string(cursor_position_ + 1));
				}
				else
				{
					quiz_ = Quiz("RSZ");
				}
				quiz_.execute();
				break;
			}
		}
	}
protected:
	friend std::ostream& operator<<(std::ostream& out, const Interface& inter)
	{
		int i = 0;
		
		for (i; i < inter.cursor_position_; ++i)
		{
			out << inter.RULES[i] << '\n';
		}

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, static_cast<WORD>(Option::State::choosen));

		out << inter.RULES[i++] << '\n';

		SetConsoleTextAttribute(hConsole, static_cast<WORD>(Option::State::unchoosen));

		for (i; i < inter.RULES_SIZE; ++i)
		{
			out << inter.RULES[i] << '\n';
		}

		return out;
	}
private:
	Quiz quiz_;
	int cursor_position_ = 0;
};

