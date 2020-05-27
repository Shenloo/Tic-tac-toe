#include"SztucznaInteligencja.h"

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int minimax(char** pole_gry, int rozmiar_pola_gry,int ile_w_linii, int glebokosc, bool czy_komputer, char* biezacy_ruch, int alfa, int beta)
{
	int wynik, najlepszy_wynik, najgorszy_wynik;
	char zwyciezca = SprawdzPole(pole_gry, rozmiar_pola_gry, ile_w_linii);
	char komputer;
	char gracz;

	/* W zaleznosci od wyboru znaku przez gracza, przypisywane sa odpowiednie znaki  */
	if ((*biezacy_ruch == 'X' && czy_komputer) || (*biezacy_ruch == 'O' && !czy_komputer))
	{
		komputer = 'X';
		gracz = 'O';
	}
	else
	{
		komputer = 'O';
		gracz = 'X';
	}

	/* Zwracanie wartosci w przypadku zakonczenia danej gry 
	   Wieksza wartosc przypisywana, gdy ruch nalezy do komputera,
	   a mniejsza gdy ruch nalezy do gracz                         */
	if (zwyciezca == komputer)
	{
		return 10 + glebokosc;
	}
	else if (zwyciezca == '-' || glebokosc == 0)
	{
		return 0;
	}
	else if (zwyciezca == gracz)
	{
		return -10 - glebokosc;
	}

	/* Kiedy ruch nalezy do komputera algorytm przeszukuje liscie w poszukiwaniu
	   jak najwiekszych wartosci, ktore oznaczaja wygrana komputera              */
	if (czy_komputer)
	{
		najlepszy_wynik = -1000000;
		for (int i = 0; i < rozmiar_pola_gry; ++i)
		{
			for (int j = 0; j < rozmiar_pola_gry; ++j)
			{
				if (pole_gry[i][j] != 'X' && pole_gry[i][j] != 'O')
				{
					pole_gry[i][j] = komputer;
					wynik = minimax(pole_gry, rozmiar_pola_gry,ile_w_linii, glebokosc - 1, false, &gracz, alfa, beta);
					pole_gry[i][j] = '-';
					najlepszy_wynik = max(wynik, najlepszy_wynik);
					alfa = max(alfa, wynik);
				}
				if (beta <= alfa)
					break;
			}
			if (beta <= alfa)
				break;
		}
		return najlepszy_wynik;
	}
	/* Analogiczna sytuacja z tym, ze teraz wartosc wybierana jest
	   z punktu widzenia gracza, a wiec jak najmniejsza            */
	else
	{
		najgorszy_wynik = 1000000;
		for (int i = 0; i < rozmiar_pola_gry; ++i)
		{
			for (int j = 0; j < rozmiar_pola_gry; ++j)
			{
				if (pole_gry[i][j] != 'X' && pole_gry[i][j] != 'O')
				{
					pole_gry[i][j] = gracz;
					wynik = minimax(pole_gry, rozmiar_pola_gry, ile_w_linii, glebokosc - 1, true, &komputer, alfa, beta);
					pole_gry[i][j] = '-';
					najgorszy_wynik = min(wynik, najgorszy_wynik);
					beta = min(beta, wynik);
				}
				if (beta <= alfa)
					break;
			}
			if (beta <= alfa)
				break;
		}
		return najgorszy_wynik;
	}
}

void NajlepszyRuch(char** pole_gry, int rozmiar_pola_gry,int ile_w_linii, char* biezacy_ruch)
{
	int wynik, najlepszy_wynik;
	int najlepszy_ruch[2] = { -1, -1 };              // tablica wspolrzednych dla najbardziej optymalnego ruchu
	int glebokosc = 30;                              // zmienna odpowiedzialna za glebokosc wywolan rekurencyjnych
	char gracz;

	if (*biezacy_ruch == 'X')
		gracz = 'O';
	else
		gracz = 'X';


	najlepszy_wynik = -1000000;
	wynik = -1000001;

	/* gdy zostanie znaleziona komorka, dla ktorej wartosc
	   z punktu widzenia komputera jest najwieksza, jej wspolrzedne
	   zostana zapamietane, by potem dodac tam znak przypisany komputerowi */
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		for (int j = 0; j < rozmiar_pola_gry; ++j)
		{
			if (pole_gry[i][j] != 'X' && pole_gry[i][j] != 'O')
			{
				pole_gry[i][j] = *biezacy_ruch;
				wynik = minimax(pole_gry, rozmiar_pola_gry,ile_w_linii, glebokosc, false, &gracz, -1000000, 1000000);
				pole_gry[i][j] = '-';
				if (wynik > najlepszy_wynik)
				{
					najlepszy_wynik = wynik;
					najlepszy_ruch[0] = i;
					najlepszy_ruch[1] = j;
				}
			}
		}
	}
	pole_gry[najlepszy_ruch[0]][najlepszy_ruch[1]] = *biezacy_ruch;
}