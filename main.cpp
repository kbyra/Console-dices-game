#include "Game.h"
#include "Dice.h"
#include "Dice_cup.h"
#include "Score_sheet.h"

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int menu;

	do
	{

		cout << "----- KOSCI -----\n\n 1. Nowa gra.\n 2. Wyjdz" << endl << endl;

		menu = _getch();

		switch (menu)
		{

			case 49:
			{

				int players;

				do
				{

					cout << "\n 1. Dwoch graczy\n 2. Trzech graczy\n 3. Czterech graczy\n 4. Powrot" << endl << endl;

					players = _getch();

					switch (players)
					{

						case 49:
						{

							Game two_players(2);
							break;

						}

						case 50:
						{

							Game three_players(3);
							break;

						}

						case 51:
						{

							Game four_players(4);
							break;

						}

						case 52:
							break;

						default:
							cout << "Nieznana opcja" << endl;
							break;

					}

				} while (players != 52);

			}

			case 50:
				break;

			default:
				cout << "Nieznana opcja." << endl << endl;
				break;

		}

	} while (menu != 50);
}