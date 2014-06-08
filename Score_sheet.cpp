#include "Score_sheet.h"

Score_sheet::Score_sheet(int players) : players(players)
{

	saved_points_tab = new int[players][14];

	for (int i = 0; i < players; i++)
	{

		for (int j = 0; j < 13; j++)
		{

			saved_points_tab[i][j] = -1;

		}

		saved_points_tab[i][13] = 0;

	}

}

Score_sheet::~Score_sheet()
{

	delete[] saved_points_tab; //tu nie jestem pewien czy to calkowicie usuwa tablice

}

void Score_sheet::check_dice(int *dice_tab, int current_player)
{

	memcpy(this->dice_tab, dice_tab, sizeof(this->dice_tab));
	this->current_player = current_player;

}

void Score_sheet::count()
{

	for (int i = 0; i < 13; i++) //zerowanie tablicy aktualnych punktow
	{

		points[i] = 0;

	}

	int number_of_roll[6] = { 0, 0, 0, 0, 0, 0 }; //tablica z liczba jedynek[0], dwojek[1]...

	for(int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 6; j++)
		{

			if (dice_tab[i] == j + 1)
				number_of_roll[j]++;

		}

	}

	for (int i = 0; i < 6; i++) //jedynki, dwojki, ..., szostki
	{

		points[i] = number_of_roll[i] * (i + 1);

	}

	if (saved_points_tab[current_player - 1][6] == -1)
	{

		for (int i = 0; i < 6; i++) //3 jednakowe
		{

			if (number_of_roll[i] == 3)
			{

				points[6] = dice_tab[0] + dice_tab[1] + dice_tab[2] + dice_tab[3] + dice_tab[4];
				break;

			}

		}

	}

	if (saved_points_tab[current_player - 1][7] == -1)
	{

		for (int i = 0; i < 6; i++) //4 jednakowe
		{

			if (number_of_roll[i] == 4)
			{

				points[7] = dice_tab[0] + dice_tab[1] + dice_tab[2] + dice_tab[3] + dice_tab[4];
				break;

			}

		}

	}

	if (saved_points_tab[current_player - 1][8] == -1)
	{

		for (int i = 0; i < 6; i++) //full
		{

			if (number_of_roll[i] == 3)
			{

				for (int j = 0; j < 6; j++)
				{

					if (number_of_roll[j] == 2)
					{

						points[8] = 25;
						break;

					}

				}

				break;

			}

		}

	}

	if (saved_points_tab[current_player - 1][9] == -1)
	{

		if ((number_of_roll[2] >= 1 && number_of_roll[3] >= 1) && ((number_of_roll[0] >= 1 && number_of_roll[1] >= 1) //maly strit
			|| (number_of_roll[1] >= 1 && number_of_roll[4] >= 1)
			|| (number_of_roll[4] >= 1 && number_of_roll[5] >= 1)))
			points[9] = 30;

	}

	if (saved_points_tab[current_player - 1][10] == -1)
	{

		if (number_of_roll[1] == 1 && number_of_roll[2] == 1 && number_of_roll[3] == 1 && number_of_roll[4] == 1) //duzy strit
			points[10] = 40;

	}

	if (saved_points_tab[current_player - 1][11] == -1)
	{

		if (dice_tab[0] == dice_tab[1] == dice_tab[2] == dice_tab[3] == dice_tab[4]) //general
			points[11] = 50;

	}

	if (saved_points_tab[current_player - 1][12] == -1)
	{

		points[12] = dice_tab[0] + dice_tab[1] + dice_tab[2] + dice_tab[3] + dice_tab[4]; //szansa

	}

}

void Score_sheet::count_sum()
{

	for (int i = 0; i < players; i++)
	{

		int sum = 0;

		for (int j = 0; j < 13; j++)
		{

			if (saved_points_tab[i][j] != -1)
				sum += saved_points_tab[i][j];

		}

		saved_points_tab[i][13] = sum;
	}

}

void Score_sheet::operator++()
{
	count_sum();
}

void Score_sheet::draw()
{

	string category_names[13] = { "Jedynki", "Dwojki", "Trojki", "Czworki", "Piatki", "Szostki", "3 jednakowe", "4 jednakowe", "Full", "Maly strit", "Duzy strit", 
		"General", "Szansa"};

	cout << setw(20) << " ";

	for (int i = 0; i < players; i++)
	{

		cout << "G" << setw(7) << left << i + 1;

	}
	cout << endl;

	for (int i = 0; i < 48; i++)
	{

		cout << "-";

	}
	cout << endl << endl;

	for (int i = 0; i < 13; i++)
	{

		cout << setw(2) << right << i + 1 << ". " << setw(15) << left << category_names[i];

		for (int j = 0; j < players; j++)
		{

			if (saved_points_tab[j][i] != -1)
			{

				cout << setw(3) << right << saved_points_tab[j][i] << setw(5) << " ";

			}

			else
			{

				if (current_player == j + 1)
				{

					cout << "|" << setw(2) << right << points[i] << setw(5) << left << "|";
				}

				else
				 cout << setw(8) << " ";

			}

		}

		cout << endl << endl;
	}

	for (int i = 0; i < 48; i++)
	{

		cout << "-";

	}
	cout << endl;

	cout << setw(4) << " " << setw(15) << left << "SUMA";

	for (int i = 0; i < players; i++)
	{

		if (saved_points_tab[i][13] != 0)
			cout << setw(3) << right << saved_points_tab[i][13] << setw(5) << " ";

		else
			cout << setw(8) << " ";

	}

	cout << endl << endl;
}

bool Score_sheet::save_points(bool last_throw)
{

	string category;
	int category_int;
	
	do {

		cout << "Wpisz do kategorii";

		if (last_throw == false)
			cout << " (0 - powrot): ";

		else if (last_throw == true) //po ostatnim z trzech rzutow trzeba wpisac wynik
			cout << ": ";

		cin >> category;

		istringstream iss(category); //dzieki operowaniu na stringach gracz moze wpisac cokolwiek, a program dalej bedzie dzialac
		iss >> category_int;

		if (category_int >= 1 && category_int <= 13)
		{

			if (saved_points_tab[current_player - 1][category_int - 1] == -1) //ten if pilnuje by wpisywac punkty tylko do pustych kategorii(-1)
			{

				saved_points_tab[current_player - 1][category_int - 1] = points[category_int - 1];
				return true;

			}

			else
			{

				cout << "Do tej kategorii juz wpisales punkty. Wybierz inna." << endl;

			}
		}
		else if (category_int == 0)
		{

			if (last_throw == false)
				return false;

		}

	} while (1);

}

void Score_sheet::who_win()
{

	int* final_points = new int[players];
	
	for (int i = 0; i < players; i++)
	{

		final_points[i] = saved_points_tab[i][13];

	}

	int* best_points = max_element(final_points, final_points + (players));

	int winner;
	int same_points = -1;

	for (int i = 0; i < players; i++)
	{

		if (saved_points_tab[i][13] == *best_points)
		{

			winner = i;
			same_points++;

		}

	}

	if (same_points == 0)
	{

		cout << "Zwyciezyl gracz " << winner + 1 << "!" << endl;

	}
	else
	{

		cout << "Remis!" << endl;

	}

	delete[] final_points;

}