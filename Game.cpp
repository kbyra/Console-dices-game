#include "Game.h"

Game::Game(int players) : players(players), score_sheet(players)
{

	the_game();

}

int Game::ask()
{

	int ask;

	do {

		cout << "[1] - wpisz punkty do tabeli [2] - wybierz i rzuc ponownie" << endl;
		ask = _getch();

	} while (ask != 49 && ask != 50);

	return ask;

}

void Game::the_game()
{
	
	for (int i = 0; i < 13 * players; i++)
	{

		cout << "\nGRACZ " << current_player << endl << endl;

		dice_cup.throw_dice();
		score_sheet++; //sumowanie punktow
		show_score_sheet();

		//ponowne rzuty 

		int additional_throws = 0;

		do {

			if (ask() == 49)
			{

				if (score_sheet.save_points(false))
					break;

				else
					continue;

			}

			else
			{

				if (dice_cup.re_throw_dice())
				{

					additional_throws++;
					show_score_sheet();

					if (additional_throws == 2)
					{

						score_sheet.save_points(true);
						break;

					}
				}

				else
				{

					score_sheet.draw();

				}

			}

		} while (1);

		if (current_player == players)
			current_player = 1;

		else
			current_player++;

	}

	score_sheet++;
	show_score_sheet();
	score_sheet.who_win();
}

void Game::show_score_sheet()
{

	score_sheet.check_dice(dice_cup.get_dice_tab(), current_player); 
	score_sheet.count();
	score_sheet.draw();

}