#ifndef DICE_CUP_H
#define DICE_CUP_H

#include "Dice.h"

class Dice_cup
{
	Dice* Dice1;
	Dice* Dice2;
	Dice* Dice3;
	Dice* Dice4;
	Dice* Dice5;

public:
	void Throw();
	void reThrow(int dice);

	void reThrow_interface();
};

#endif
