#ifndef DICE_H
#define DICE_H

#include <random>
#include <iostream>
using namespace std;

class Dice
{

private:
	int die_roll;
public:
	Dice();

	void roll_the_dice();
	int get_die_roll();

};

#endif
