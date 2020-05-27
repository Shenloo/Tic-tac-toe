#include "PoleGry.h"

char** StworzPoleGry(int rozmiar_pola_gry)
{
	char** pole_gry = new char* [rozmiar_pola_gry];

	for (int i = 0; i < rozmiar_pola_gry; ++i)
		pole_gry[i] = new char[rozmiar_pola_gry];

	for (int i = 0; i < rozmiar_pola_gry; ++i)
		for (int j = 0; j < rozmiar_pola_gry; ++j)
			pole_gry[i][j] = '-';
	return pole_gry;
}

void UsunPoleGry(char** pole_gry, int rozmiar_pola_gry)
{
	for (int i = 0; i < rozmiar_pola_gry; ++i)
		delete[] pole_gry[i];
	delete[] pole_gry;
}

void WyswietlPoleGry(char** pole_gry, int rozmiar_pola_gry)
{
	system("CLS");

	for (int i = 0; i < rozmiar_pola_gry - 1; ++i)
		cout << "         |";
	cout << endl;

	for (int i = 0; i < rozmiar_pola_gry - 1; ++i)
	{
		for (int j = 0; j < rozmiar_pola_gry - 1; ++j)
			cout << "    " << pole_gry[i][j] << "    |";
		cout << "    " << pole_gry[i][rozmiar_pola_gry - 1];
		cout << endl;

		for (int l = 0; l < rozmiar_pola_gry - 1; ++l)
			cout << "         |";
		cout << endl;

		for (int i = 0; i < rozmiar_pola_gry * 10 - 1; ++i)
			cout << "-";
		cout << endl;

		for (int l = 0; l < rozmiar_pola_gry - 1; ++l)
			cout << "         |";
		cout << endl;

	}
	for (int j = 0; j < rozmiar_pola_gry - 1; ++j)
		cout << "    " << pole_gry[rozmiar_pola_gry - 1][j] << "    |";
	cout << "    " << pole_gry[rozmiar_pola_gry - 1][rozmiar_pola_gry - 1];
	cout << endl;

	for (int l = 0; l < rozmiar_pola_gry - 1; ++l)
		cout << "         |";
	cout << endl;

}

char SprawdzPole(char** pole_gry, int rozmiar_pola_gry, int ile_w_linii)
{
	char x = 'X';
	char o = 'O';
	char poprzedni='0';
	bool remis = false;
	int wolne_komorki = rozmiar_pola_gry * rozmiar_pola_gry;
	int licznik = 1;

	/* Sprawdzenie 'X' w poziomie */
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		licznik = 1;
		poprzedni = '0';
		for (int j = 0; j < rozmiar_pola_gry; ++j)
		{
			if (x == pole_gry[i][j] && (poprzedni == x))
				++licznik;
			else if (x != pole_gry[i][i])
				licznik = 1;
			poprzedni = pole_gry[i][j];
			if (licznik == ile_w_linii)
				return x;
		}	
	}

	/* Sprawdzenie 'X' w pionie */
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		licznik = 1;
		poprzedni = '0';
		for (int j = 0; j < rozmiar_pola_gry; ++j)
		{
			if (x == pole_gry[j][i] && (poprzedni == x))
				++licznik;
			else if (x != pole_gry[j][i])
				licznik = 1;
			poprzedni = pole_gry[j][i];
			if (licznik == ile_w_linii)
				return x;
		}
	}

	/* Sprawdzenie 'O' w poziomie */
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		licznik = 1;
		poprzedni = '0';
		for (int j = 0; j < rozmiar_pola_gry; ++j)
		{
			if (o == pole_gry[i][j] && (poprzedni == o))
				++licznik;
			else if (o != pole_gry[i][j])
				licznik = 1;
			poprzedni = pole_gry[i][j];
			if (licznik == ile_w_linii)
				return o;
		}
	}

	/* Sprawdzenie 'O' pionie */
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		licznik = 1;
		poprzedni = '0';
		for (int j = 0; j < rozmiar_pola_gry; ++j)
		{
			if (o == pole_gry[j][i] && (poprzedni == o))
				++licznik;
			else if (o != pole_gry[j][i])
				licznik = 1;
			poprzedni = pole_gry[j][i];
			if (licznik == ile_w_linii)
				return o;
		}
	}

	/* Sprawdzenie 'X' na przekatnych */
	licznik = 1;
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		if (x == pole_gry[i][i] && (poprzedni == x))
			++licznik;
		else if (x != pole_gry[i][i])
			licznik = 1;
		poprzedni = pole_gry[i][i];
		if (licznik == ile_w_linii)
			return x;
	}

	licznik = 1;
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		if (x == pole_gry[(rozmiar_pola_gry - 1) - i][i] && (poprzedni == x))
			++licznik;
		else if (x != pole_gry[(rozmiar_pola_gry - 1) - i][i])
			licznik = 1;
		poprzedni = pole_gry[(rozmiar_pola_gry - 1) - i][i];
		if (licznik == ile_w_linii)
			return x;
	}

	/* Sprawdzenie'O' na przekatnych */
	licznik = 1;
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		if (o == pole_gry[i][i] && (poprzedni == o))
			++licznik;
		else if (o != pole_gry[i][i])
			licznik = 1;
		poprzedni = pole_gry[i][i];
		if (licznik == ile_w_linii)
			return o;
	}

	licznik = 1;
	for (int i = 0; i < rozmiar_pola_gry; ++i)
	{
		if (o == pole_gry[(rozmiar_pola_gry - 1) - i][i] && (poprzedni == o))
			++licznik;
		else if (o != pole_gry[(rozmiar_pola_gry - 1) - i][i])
			licznik = 1;
		poprzedni = pole_gry[(rozmiar_pola_gry - 1) - i][i];
		if (licznik == ile_w_linii)
			return o;
	}

	/* Sprawdzenie czy nie nastapil remis */
	licznik = 1;
	for(int i=0;i<rozmiar_pola_gry;++i)
		for (int j = 0; j < rozmiar_pola_gry; ++j)
		{
			if (pole_gry[i][j] == 'X' || pole_gry[i][j] == 'O')
				--wolne_komorki;
		}
	if (wolne_komorki == 0)
		remis = true;
	if (remis)
		return '-';
	return '0';
}

void ZmienKomorke(char** pole_gry, char* biezacy_ruch, int rozmiar_pola_gry)
{
	int x, y;
	cout << "Podaj wspolrzedne komorki do zmiany : [x  y] : ";
	do
	{
		do
		{
			cin >> x >> y;
			if (x < 0 || x >= rozmiar_pola_gry || y < 0 || y >= rozmiar_pola_gry)
				cout << "nieprawidlowa wspolrzedne ";
		} while (x < 0 || x >= rozmiar_pola_gry || y < 0 || y >= rozmiar_pola_gry);
		if (pole_gry[x][y] == 'X' || pole_gry[x][y] == 'O')
			cout << "komorka zajeta, wybierz inna ";
	} while ((pole_gry[x][y] == 'X' || pole_gry[x][y] == 'O') || (x < 0 || x >= rozmiar_pola_gry || y < 0 || y >= rozmiar_pola_gry));
	pole_gry[x][y] = *biezacy_ruch;
}