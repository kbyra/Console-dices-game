#include "Game.h"
#include "Player.h"

#include "Dice.h"
#include "Dice_cup.h"

#include "Score_sheet.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int menu;

	cout << " -------   -------   -------   -------   -------   -------\n"
		<<  "|       | | o     | | o     | | o   o | | o   o | | o   o |\n"
		<<  "|   o   | |       | |   o   | |       | |   o   | | o   o |\n"
		<<  "|       | |     o | |     o | | o   o | | o   o | | o   o |\n"
		<<  " -------   -------   -------   -------   -------   -------\n\n\n";

	do
	{
		cout << "-----KOSCI-----\n\n 1. Nowa gra.\n 2. Wyjdz\n\n";
		
		cin >> menu;

		switch (menu)
		{
			case 1:
			{
				int players;

				do
				{

					cout << "\n 1. Dwoch graczy\n 2. Trzech graczy\n 3. Czterech graczy\n 4. Powrot\n\n";

					cin >> players;
					switch (players)
					{
						case 1:
						{
							Game two_players(2);

							Dice_cup DC; //roboczo
							DC.Throw();

							break;
						}
						case 2:
						{
							Game three_players(3);
							break;
						}
						case 3:
						{
							Game four_players(4);
							break;
						}
						case 4:
							break;
						default:
							cout << "Nieznana opcja\n";
							break;
					}

				} while (players != 4);

			}

			case 2:
				break;

			default:
				cout << "Nieznana opcja.\n";
				break;
		}

		} while (menu != 2);
}