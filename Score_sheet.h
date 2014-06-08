#ifndef SCORE_SHEET_H
#define SCORE_SHEET_H

#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <algorithm>

using namespace std;

class Score_sheet
{

private:
	int players;
	int current_player;
	int dice_tab[5]; //wyniki poszczegolnych rzutow
	int points[13];
	int (*saved_points_tab)[14]; //wskazujê na tablice dwuwymiarow¹ [gracz][punkty]; [i][13] - suma punktow i-tego gracza

public:
	Score_sheet(int players);
	~Score_sheet();

	void check_dice(int *dice_tab, int current_player);
	void count();

	void count_sum();
	void operator++();

	void draw();
	bool save_points(bool last_throw);
	void who_win();

};

#endif
