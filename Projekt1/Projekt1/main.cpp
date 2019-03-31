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
	////std::cout << "Podaj wielkosc tablicy do posortowania: ";
	//
	//int wielkosc=1000000;
	////std::cin >> wielkosc;
	//
	//
	//
	//int** tablica = new int *[100];
	//for (int row = 0; row < 99; row++)  //utworzenie 100 tablic
	//{
	//	tablica[row] = new int[wielkosc];
	//}
	//
	//
	//for (int row = 0; row < 99; row++)
	//{
	//	for (int i = 0; i < wielkosc; i++)
	//	{
	//		tablica[row][i] = rand();  //wype³nienie tablic liczbami losowymi
	//	}
	//}
	//
	//
	////for (int row = 0; row < 99; row++)
	////{
	////	for (int i = 0; i < wielkosc; i++)
	////	{
	////		std::cout << tablica[row][i] << " ";  //wyœwietlenie tablic nieposortowanych
	////	}
	////	std::cout << "\n";
	////}
	////std::cout << "\n";
	//
	//for (int i = 0; i < 99; i++)
	//{
	//	quicksort(tablica[i], 0, wielkosc - 1, 0.5);  //wstêpne sortowanie
	//	//inv_quicksort(tablica[i], 0, wielkosc - 1);    //sortowanie odwrotne
	//}
	//std::cout << "sortujemy";
	////auto start = std::chrono::system_clock::now(); //start czasu
	//for (int i = 0; i < 99; i++)
	//{
	//	auto start = std::chrono::system_clock::now();
	//	//int *tab_pom = new int[wielkosc];
	//	//bubble(tablica[i], wielkosc);
	//	//insert(tablica[i], wielkosc);
	//	//quicksort(tablica[i], 0, wielkosc - 1, 1);  //czwarty parametr to stopieñ posortowania w % (0-1)
	//	//merge_sort(tablica[i], tab_pom, 0, wielkosc-1);
	//	//heapsort(tablica[i], wielkosc);
	//	intro_sort(tablica[i],wielkosc);
	//	//IntroSort(tablica[i], wielkosc);
	//	auto end = std::chrono::system_clock::now();
	//	std::chrono::duration<double> elapsed_seconds = end - start;
	//	if (czy_posortowane1x1(tablica[i], wielkosc) == 1)
	//	{
	//		std::cout << "Posortowane\nCzas sortowania: " << elapsed_seconds.count() << "s\n";
	//		std::cout << "\n";
	//	}
	//	else
	//	{
	//		std::cout << "Blad sortowania\n";
	//	}
	//}
	////auto end = std::chrono::system_clock::now(); //koniec czasu
	//
	////std::chrono::duration<double> elapsed_seconds = end - start;  //obliczenie zmiany czasu
	//
	//if (czy_posortowane(tablica, wielkosc)==1)
	//{
	//	std::cout << "Posortowane\nCzas sortowania: " << elapsed_seconds.count() << "s\n";
	//	std::cout << "\n";
	//}
	//else
	//{
	//	std::cout << "Blad sortowania\n";
	//}
	//
	//
	////for (int row = 0; row < 99; row++)
	////{
	////	for (int i = 0; i < wielkosc; i++)
	////	{
	////		std::cout << tablica[row][i] << " ";  //wyœwietlenie tablic posortowanych
	////	}
	////	std::cout << "\n";
	////}
	////std::cout << "\n";
	//
	//
	//
	////for (int i = 0; i < 99; i++)  
	////{
	////	delete[] tablica[i];   //zwolnienie pamiêci
	////}
	////delete[] tablica;
	////tablica = NULL;
	//
	//
	//
	//system("pause");
	//return 1;

int wiersz = 100;
int rozmiaryTablic[5] = { 10000,50000, 100000, 500000, 1000000 };
double wstepnePosortowanie[8] = { -1, 1, 0.25, 0.5 , 0.75, 0.95, 0.99, 0.997 };
std::fstream plik;
int **tablica = new int *[wiersz];
for (int rozmiar = 0; rozmiar < 5; rozmiar++)
{
	std::cout << "Kolejny rozmiar ********* \n";
	for (int posortowanie = 0; posortowanie < 8; ++posortowanie)
	{
		std::cout << "Kolejny stopien posortowania\n";
		// utworzenie i wype³nienie 
		for (int i = 0; i < wiersz; ++i)
		{
			std::cout << "Kolejna tablica\n";
			tablica[i] = new int[rozmiaryTablic[rozmiar]];
			for (int j = 0; j < rozmiaryTablic[rozmiar] - 1; ++j)
				tablica[i][j] = rand();
		}
		//std::cout << posortowanie << " \n";

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
			//insert(tablica[i], rozmiaryTablic[rozmiar]);
			//quicksort(tablica[i], 0, rozmiaryTablic[rozmiar] - 1, 1); //czwarty parametr to stopieñ posortowania w % (0-1)
			//mergesort(tablica[i],tablica_pomocnicza, 0, rozmiaryTablic[rozmiar] - 1);
			//heapsort(tablica[i], rozmiaryTablic[rozmiar]);
			intro_sort(tablica[i], rozmiaryTablic[rozmiar]);
			auto end = std::chrono::system_clock::now();

			//sprawdzenie poprawnoœci posortowania
			if (czy_posortowane1x1(tablica[i], rozmiaryTablic[rozmiar]) == 1)
			{
				std::chrono::duration<double> elapsed_seconds = end - start;
				plik.open("plik.txt", std::ios::out | std::ios::app);
				if (plik.good() == true)
				{

					plik << i << " " << rozmiaryTablic[rozmiar] << " " << wstepnePosortowanie[posortowanie] << " ";
					plik << " " << elapsed_seconds.count() << std::endl;
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
delete[] tablica;
tablica = NULL;
system("pause");
return 0;

}