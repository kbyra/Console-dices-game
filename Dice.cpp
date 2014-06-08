#include "Dice.h"

Dice::Dice()
{

	roll_the_dice();

}

void Dice::roll_the_dice()
{
	random_device random;
	default_random_engine generator (random());
	uniform_int_distribution<int> distribution(1, 6);
	die_roll = distribution(generator);
}

int Dice::get_die_roll()
{

	return die_roll;

}