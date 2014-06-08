#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Dice_cup.h"
#include "Score_sheet.h"

using namespace std;

class Game
{

private:
	int players = 2;
	int current_player = 1;
	Dice_cup dice_cup;
	Score_sheet score_sheet;

	void the_game();
	void show_score_sheet();
	int ask();
	
public:
	Game(int players);

};

#endif