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
int row = 100;
int rozmiary_tablic[5] = { 10000,50000, 100000, 500000, 1000000 };
double stopien_posortowania[8] = { -1, 1, 0.25, 0.5 , 0.75, 0.95, 0.99, 0.997 }; // -1 oznacza posortowan¹ odwrotnie a 1 to w pe³ni losowe
std::fstream test;
int **tablica = new int *[row];
for (int rozmiar = 0; rozmiar < 5; rozmiar++)
{
	std::cout << "Rozmiary: "<< rozmiar+1<<"/5 "<<rozmiary_tablic[rozmiar]<<std::endl;
	for (int stopien = 0; stopien < 8; ++stopien)
	{
		std::cout << "Stopien wstepnego posortowania: "<<stopien+1<<"/8"<<std::endl;

		// utworzenie i wype³nienie tablic
		for (int i = 0; i < row; ++i)
		{
			tablica[i] = new int[rozmiary_tablic[rozmiar]];
			for (int j = 0; j < rozmiary_tablic[rozmiar] - 1; ++j)
				tablica[i][j] = rand();
		}

		//warunek wstêpnego sortowania odwrotnego
		if (stopien_posortowania[stopien] == -1.0)
		{
			for (int i = 0; i < row - 1; ++i)
			{
				inv_quicksort(tablica[i], 0, rozmiary_tablic[rozmiar] - 1);
			}
		}

		//warunek wstêpnego sortowania z parametrem
		else if ((stopien_posortowania[stopien] != 1) && (stopien_posortowania[stopien] > 0))
		{
			for (int i = 0; i < row - 1; ++i)
			{
				quicksort(tablica[i], 0, rozmiary_tablic[rozmiar] - 1, stopien_posortowania[stopien]);
			}
		}

		//w³asciwe sortowanie
		for (int i = 0; i < row; ++i)
		{
			//tablica pomocnicza przy sortowaniu przez scalanie
			//int *tablica_pomocnicza = new int[rozmiaryTablic[rozmiar]];
			auto start = std::chrono::system_clock::now();

			//Tu wpisujemy sortowanie
			//insert(tablica[i], rozmiaryTablic[rozmiar]);
			quicksort(tablica[i], 0, rozmiary_tablic[rozmiar] - 1, 1); //czwarty parametr to stopieñ posortowania w % (0-1)
			//merge_sort(tablica[i],tablica_pomocnicza, 0, rozmiaryTablic[rozmiar] - 1);
			//heapsort(tablica[i], rozmiaryTablic[rozmiar]);
			//intro_sort(tablica[i], rozmiaryTablic[rozmiar]);
			auto end = std::chrono::system_clock::now();

			//sprawdzenie poprawnoœci posortowania/zapis do pliku
			if (czy_posortowane1x1(tablica[i], rozmiary_tablic[rozmiar]) == 1)
			{
				std::chrono::duration<double> elapsed_seconds = end - start;
				test.open("test.txt", std::ios::out | std::ios::app);
				if (test.good() == true)
				{

					test << i << ";" << rozmiary_tablic[rozmiar] << ";" << stopien_posortowania[stopien] << ";";
					test << elapsed_seconds.count() << std::endl;
					test.close();
				}
			}

			//jeœli Ÿle posortowane
			else if (czy_posortowane1x1(tablica[i], rozmiary_tablic[rozmiar]) == 0)
			{
				test.open("test.txt", std::ios::out | std::ios::app);
				if (test.good() == true)
				{
					test << "\nTablica nieposortowana" << "\n";
					test.close();
				}
			}
		}
		for (int q = 0; q < row; q++)
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