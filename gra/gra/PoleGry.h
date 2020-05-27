#pragma once
#include<iostream>

using namespace std;
/* Funkcja tworzaca pole gry, jako argument przyjmuje  
   tylko rozmiar pola gry i zwraca do niego wskaznik   */
char** StworzPoleGry(int rozmiar_pola_gry);

/* Funkcja wyswietlajaca pole gry, argumentami sa pole 
   gry do wyswietlenia oraz jego rozmiar               */
void WyswietlPoleGry(char** pole_gry, int rozmiar_pola_gry);

/* Funkcja sprawdzajaca kto jest zwyciezca, badz czy 
   nastapil remis, argumentami sa: pole gry, jego rozmiar, 
   oraz liczba znakow potrzebnych do wygranej. Funkcja
   zwraca wskaznik do znaku, ktory wskazuje albo na 
   zwyciezce, albo na remis                               */
char SprawdzPole(char** pole_gry, int rozmiar_pola_gry, int ile_w_linii);

/* Funkcja zmieniajaca dana komorke, jednoczesnia sprawdza,
   czy dana zmiana moze zostac dokonana, w przypadku gdy gracz
   poda zle wspolrzedne, argumentami sa: pole gry, biezacy
   ruch i rozmiar pola gry                                     */
void ZmienKomorke(char** pole_gry, char* biezacy_ruch, int rozmiar_pola_gry);

/* Funkcja odpowiedzialne za usuwanie pola gry, wazna ze 
   wzgledu na to, ze pamiec dla pola gry jest przydzielana
   dynamicznie, zapobiega wyciekom pamieci                   */
void UsunPoleGry(char** pole_gry, int rozmiar_pola_gry);