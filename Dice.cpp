#include "Dice.h"

Dice::Dice()
{
	random_device random;
	default_random_engine generator (random());
	uniform_int_distribution<int> distribution(1, 6);
	die_roll = distribution(generator);

	//cout << die_roll << "\n"; //tymczasowo wyœwietla wynik rzutu, w przysz³oœci kostki bêd¹ rysowane
	draw();
}

Dice::~Dice()
{

}

void Dice::draw()
{
	if (die_roll == 1)
	{
		cout << " -------\n|       |\n|   o   |\n|       |\n ------- \n";
	}

	else if (die_roll == 2)
	{
		cout << " -------\n| o     |\n|       |\n|     o |\n ------- \n";
	}

	else if (die_roll == 3)
	{
		cout << " -------\n| o     |\n|   o   |\n|     o |\n ------- \n";
	}

	else if (die_roll == 4)
	{
		cout << " -------\n| o   o |\n|       |\n| o   o |\n ------- \n";
	}

	else if (die_roll == 5)
	{
		cout << " -------\n| o   o |\n|   o   |\n| o   o |\n ------- \n";
	}

	else if (die_roll == 6)
	{
		cout << " -------\n| o   o |\n| o   o |\n| o   o |\n ------- \n";
	}

}