#pragma once
#include<iostream>
#include"PoleGry.h"

using namespace std;
/* funkcja zwraca mniejsza wartosc */
int min(int a, int b);
/* funkcja zwraca wieksza wartosc  */
int max(int a, int b);

/* Algorytm minimax 
   glebokosc - odpowiada za to ile wywowolan rekurencyjnych algorytmu zostanie wykonanych 
   czy_komputer - zmienna bool informujaca o tym, czy algorytm ma maksymalizowac zysk czy minimalizowac 
   ( maksymalizacja dla komputera, minimalizacja dla gracza 
   alfa, beta - zmienne wykorzystywane do ciec alfa beta                                                  */
int minimax(char** pole_gry, int rozmiar_pola_gry,int ile_w_linii, int glebokosc, bool czy_komputer,char* biezacy_ruch, int alfa, int beta);

/* Funkcja podejmujaca decyzje, ktory ruch bedzie najbardziej optymalny w danej turze */
void NajlepszyRuch(char** pole_gry, int rozmiar_pola_gry,int ile_w_linii, char* biezacy_ruch);