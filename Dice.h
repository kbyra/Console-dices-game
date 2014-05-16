#ifndef DICE_H
#define DICE_H

#include <random>
#include <iostream>
using namespace std;

class Dice
{
	int die_roll;
public:
	Dice();
	~Dice();

	void draw();
};

#endif
