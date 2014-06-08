#ifndef DICE_CUP_H
#define DICE_CUP_H

#include <conio.h>
#include "Dice.h"

class Dice_cup
{

private:
	Dice dice[5];
	int dice_tab[5]; //wyniki poszczegolnych rzutow
	bool select_dice[5];
	void draw_dice();

public:
	Dice_cup();

	int* get_dice_tab();
	void throw_dice();
	bool re_throw_dice();

};

#endif