#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>

#include "bubble.hpp"
#include "insert.hpp"
#include "merge.hpp"
#include "quicksort.hpp"
#include "inv_quicksort.hpp"
#include "tester.hpp"
#include "tester1x1.hpp"
#include "heapsort.hpp"
#include "introsort.hpp"


int main()
{
int wiersz = 100;
int rozmiaryTablic[5] = { 10000,50000, 100000, 500000, 1000000 };
double wstepnePosortowanie[8] = { -1, 1, 0.25, 0.5 , 0.75, 0.95, 0.99, 0.997 };
std::fstream plik;
int **tablica = new int *[wiersz];
for (int rozmiar = 0; rozmiar < 5; rozmiar++)
{
	std::cout << "Rozmiary: "<< rozmiar+1<<"/5 "<<rozmiaryTablic[rozmiar]<<std::endl;
	for (int posortowanie = 0; posortowanie < 8; ++posortowanie)
	{
		std::cout << "Stopien wstepnego posortowania: "<<posortowanie+1<<"/8"<<std::endl;

		// utworzenie i wype³nienie 
		for (int i = 0; i < wiersz; ++i)
		{
			tablica[i] = new int[rozmiaryTablic[rozmiar]];
			for (int j = 0; j < rozmiaryTablic[rozmiar] - 1; ++j)
				tablica[i][j] = rand();
		}

		//warunek wstêpnego sortowania odwrotnego
		if (wstepnePosortowanie[posortowanie] == -1.0)
		{
			for (int i = 0; i < wiersz - 1; ++i)
			{
				inv_quicksort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1); // wstêpne odwrotne sortowanie
			}
		}

		//warunek wstêpnego sortowania z parametrem
		else if ((wstepnePosortowanie[posortowanie] != 1) && (wstepnePosortowanie[posortowanie] > 0))
		{
			for (int i = 0; i < wiersz - 1; ++i)
			{
				quicksort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, wstepnePosortowanie[posortowanie]); //wstêpne sortowanie
			}
		}

		//w³asciwe sortowanie
		for (int i = 0; i < wiersz; ++i)
		{
			//int *tablica_pomocnicza = new int[rozmiaryTablic[rozmiar]];
			auto start = std::chrono::system_clock::now();

			//Tu wpisujemy sortowanie
			insert(tablica[i], rozmiaryTablic[rozmiar]);
			//quicksort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, 1); //czwarty parametr to stopieñ posortowania w % (0-1)
			//merge_sort(tablica[i],tablica_pomocnicza, 0, rozmiaryTablic[rozmiar] - 1);
			//heapsort(tablica[i], rozmiaryTablic[rozmiar]);
			//intro_sort(tablica[i], rozmiaryTablic[rozmiar]);
			auto end = std::chrono::system_clock::now();

			//sprawdzenie poprawnoœci posortowania
			if (czy_posortowane1x1(tablica[i], rozmiaryTablic[rozmiar]) == 1)
			{
				std::chrono::duration<double> elapsed_seconds = end - start;
				plik.open("plik.txt", std::ios::out | std::ios::app);
				if (plik.good() == true)
				{

					plik << i << ";" << rozmiaryTablic[rozmiar] << ";" << wstepnePosortowanie[posortowanie] << ";";
					plik << elapsed_seconds.count() << std::endl;
					plik.close();
				}
			}

			//jeœli Ÿle posortowane
			else if (czy_posortowane1x1(tablica[i], rozmiaryTablic[rozmiar]) == 0)
			{
				plik.open("plik.txt", std::ios::out | std::ios::app);
				if (plik.good() == true)
				{
					plik << "\nTablica nieposortowana" << "\n";
					plik.close();
				}
			}
		}
		for (int q = 0; q < wiersz; q++)
		{
			delete[] tablica[q]; //zwolnienie pamiêci
		}
	}
}
std::cout << "Zakonczono pomiary :)"<<std::endl;
delete[] tablica;
tablica = NULL;
system("pause");
return 0;
}