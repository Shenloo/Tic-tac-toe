#include<iostream>
#include<cstdlib>
#include"PoleGry.h"
#include"SztucznaInteligencja.h"

using namespace std;

int main()
{
	int rozmiar_pola_gry;                            
	int wolne_komorki;                                // liczba pozostalych wolnych komorek na polu gry
	int ile_w_linii;                                  // ile znakow w linii jest potrzebnych do wygranej
	char czy_grac_dalej = 'T';                        // zmienna, ktora odpowiada za to czy po skonczonej grze rozpocznie sie nowa gra
	char zwyciezca = '-';                             // przechowuje znak zwyciezcy, '-' w przypadku remisu, badz 0
	char gracz1 = '-';                                // znak gracz
	char komputer = '-';                              // znak komputera
	char* biezacy_ruch;                               
	char** pole_gry;


	/* Glowna petla odpowiedzialna za ponawianie gry */
	/*************************************************/
	do
	{
		/* wczytywanie rozmiaru pola gry w celu jego stworzenia */
		do
		{
			cout << "Podaj rozmiar pola gry [od 3 do 5] : ";
			cin >> rozmiar_pola_gry;
			system("CLS");
		} while (rozmiar_pola_gry <= 2 || rozmiar_pola_gry > 5);
		pole_gry = StworzPoleGry(rozmiar_pola_gry); 
		wolne_komorki = rozmiar_pola_gry * rozmiar_pola_gry;                     

		/* wybor ile znakow bedzie potrzebnych do wygranej */
		do
		{
			cout << "Ile znakow w linii do wygranej ? [3-5 (<= rozmiar planszy)] : ";
			cin >> ile_w_linii;
			system("CLS");
		} while (ile_w_linii < 3 || ile_w_linii > rozmiar_pola_gry);
	
		/* gracz wybiera jakim znakiem chce sie poslugiwac */
		do
		{
			cout << "Wybierz kolko lub krzyzyk [O/X]: ";
			cin >> gracz1;
			if (gracz1 == 'X')
				komputer = 'O';
			else if (gracz1 == 'O')
				komputer = 'X';
		} while (gracz1 != 'X' && gracz1 != 'O');
		biezacy_ruch = &gracz1;

		/* wlasciwa petla odpowiadajaca za dana partie gry    */
		/* na polu gry dodawane sa znaku do momentu uzyskania */
		/* zwyciezcy badz remisu                              */
		while (zwyciezca != 'X' && zwyciezca != 'O' && wolne_komorki > 0)
		{
			WyswietlPoleGry(pole_gry, rozmiar_pola_gry);
			if (*biezacy_ruch == gracz1)
				cout << "gracz1 - " << gracz1 << endl;
			else if (*biezacy_ruch == komputer)
				cout << "gracz2 - " << komputer << endl;

			if (*biezacy_ruch == gracz1)
				ZmienKomorke(pole_gry, biezacy_ruch, rozmiar_pola_gry);
			else if (*biezacy_ruch == komputer)
				NajlepszyRuch(pole_gry, rozmiar_pola_gry,ile_w_linii, biezacy_ruch);

			if (*biezacy_ruch == gracz1)
				biezacy_ruch = &komputer;
			else if (*biezacy_ruch == komputer)
				biezacy_ruch = &gracz1;
			zwyciezca = SprawdzPole(pole_gry, rozmiar_pola_gry,ile_w_linii);
			--wolne_komorki;
		}
		WyswietlPoleGry(pole_gry, rozmiar_pola_gry);
		if (zwyciezca == 'X' || zwyciezca == 'O')
			cout << "Zwycieza " << zwyciezca << endl;
		else
			cout << "Remis" << endl;

		cout << "Czy chcesz grac dalej ? [T/N] ";
		cin >> czy_grac_dalej;
		system("CLS");
		if (czy_grac_dalej == 'N' || czy_grac_dalej == 'n')
			break;

		UsunPoleGry(pole_gry, rozmiar_pola_gry);                 // usuwa biezace pole gry
		
		rozmiar_pola_gry = 0;
		ile_w_linii = 0;
		zwyciezca = '-';
		gracz1 = '-';
		komputer = '-';
		biezacy_ruch = nullptr;

	} while (czy_grac_dalej == 'T' || czy_grac_dalej == 't');
	/*************************************************/

	return 0;
}