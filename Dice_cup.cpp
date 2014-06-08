#include "Dice_cup.h"

Dice_cup::Dice_cup()
{

	for (int i = 0; i < 5; i++)
	{

		select_dice[i] = false;

	}

}

int* Dice_cup::get_dice_tab()
{

	return dice_tab;

}

void Dice_cup::throw_dice()
{

	for (int i = 0; i < 5; i++)
	{

		dice[i].roll_the_dice();
		dice_tab[i] = dice[i].get_die_roll();

	}

	draw_dice();

}

bool Dice_cup::re_throw_dice()
{

	cout << "Wybierz kosci do ponownego rzutu. [ENTER] - zatwierdz\n";

	bool change = false; //zmienna zwracana przez ta funkcje, dzieki ktorej Game, wie czy gracz rzucal drugi raz czy zrezygnowal z dodatkowych rzutow

	int select;
	do {

		select = _getch();

		for (int i = 0; i < 5; i++)
		{

			if (select == 49 + i)
			{

				if (select_dice[i] == false)
					select_dice[i] = true;

				else
					select_dice[i] = false;

				break;

			}

		}
		
		if (select != 13) draw_dice();

	}while(select != 13);

	for (int i = 0; i < 5; i++) //ponowne rzuty
	{

		if (select_dice[i] == true)
		{

			change = true;
			dice[i].roll_the_dice();
			dice_tab[i] = dice[i].get_die_roll();

		}

	}

	for (int i = 0; i < 5; i++)
	{

		select_dice[i] = false;

	}

	draw_dice();
	return change;

}

void Dice_cup::draw_dice() //rysowanie kostek, niestety rysowanie kostek za pomoca metody klasy dice (dla kazdej kosci z osobna) odpada, poniewaz nie mozna w ten sposob narysowac wszystkich kostek obok siebie
{

	for (int i = 0; i < 5; i++)
	{

		if (select_dice[i] == true)
			cout << " -------/ ";

		else
			cout << " -------  ";

	}
	cout << endl;
	
	for (int i = 0; i < 5; i++)
	{

		if (dice_tab[i] == 1)
			cout << "|       | ";

		else if (dice_tab[i] == 2 || dice_tab[i] == 3)
			cout << "| o     | ";

		else if (dice_tab[i] == 4 || dice_tab[i] == 5 || dice_tab[i] == 6)
			cout << "| o   o | ";

	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{

		if (dice_tab[i] == 1 || dice_tab[i] == 3 || dice_tab[i] == 5)
			cout << "|   o   | ";

		else if (dice_tab[i] == 2 || dice_tab[i] == 4)
			cout << "|       | ";

		else if (dice_tab[i] == 6)
			cout << "| o   o | ";

	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{

		if (dice_tab[i] == 1)
			cout << "|       | ";

		else if (dice_tab[i] == 2 || dice_tab[i] == 3)
			cout << "|     o | ";

		else if (dice_tab[i] == 4 || dice_tab[i] == 5 || dice_tab[i] == 6)
			cout << "| o   o | ";

	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{

		if (select_dice[i] == true)
			cout << "/-------  ";

		else
			cout << " -------  ";

	}
	cout << endl << endl;

}