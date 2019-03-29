#include <iostream>
#include <cstdlib>
#include <chrono>

#include "bubble.hpp"
#include "insert.hpp"
#include "merge.hpp"
#include "quicksort.hpp"
#include "inv_quicksort.hpp"
#include "tester.hpp"
#include "heapsort.hpp"
#include "introsort.hpp"


int main()
{
	//std::cout << "Podaj wielkosc tablicy do posortowania: ";

	int wielkosc=100;
	//std::cin >> wielkosc;



	int** tablica = new int *[100];
	for (int row = 0; row < 99; row++)  //utworzenie 100 tablic
	{
		tablica[row] = new int[wielkosc];
	}


	for (int row = 0; row < 99; row++)
	{
		for (int i = 0; i < wielkosc; i++)
		{
			tablica[row][i] = rand();  //wype³nienie tablic liczbami losowymi
		}
	}
	

	//for (int row = 0; row < 99; row++)
	//{
	//	for (int i = 0; i < wielkosc; i++)
	//	{
	//		std::cout << tablica[row][i] << " ";  //wyœwietlenie tablic nieposortowanych
	//	}
	//	std::cout << "\n";
	//}
	//std::cout << "\n";

	for (int i = 0; i < 99; i++)
	{
		//quicksort(tablica[i], 0, wielkosc - 1, 0.25);  //wstêpne sortowanie
		//inv_quicksort(tablica[i], 0, wielkosc - 1);    //sortowanie odwrotne
	}

	auto start = std::chrono::system_clock::now(); //start czasu
	for (int i = 0; i < 99; i++)
	{
		int *tab_pom = new int[wielkosc];
		//bubble(tablica[i], wielkosc);
		//insert(tablica[i], wielkosc);
		//quicksort(tablica[i], 0, wielkosc - 1, 1);  //czwarty parametr to stopieñ posortowania w % (0-1)
		//merge_sort(tablica[i], tab_pom, 0, wielkosc-1);
		//heapsort(tablica[i], wielkosc);
		//intro_sort(tablica[i], wielkosc);
	}
	auto end = std::chrono::system_clock::now(); //koniec czasu

	std::chrono::duration<double> elapsed_seconds = end - start;  //obliczenie zmiany czasu

	if (czy_posortowane(tablica, wielkosc)==1)
	{
		std::cout << "Posortowane\nCzas sortowania: " << elapsed_seconds.count() << "s\n";
		std::cout << "\n";
	}
	else
	{
		std::cout << "Blad sortowania\n";
	}


	//for (int row = 0; row < 99; row++)
	//{
	//	for (int i = 0; i < wielkosc; i++)
	//	{
	//		std::cout << tablica[row][i] << " ";  //wyœwietlenie tablic posortowanych
	//	}
	//	std::cout << "\n";
	//}
	//std::cout << "\n";
	


	for (int i = 0; i < 99; i++)  
	{
		delete[] tablica[i];   //zwolnienie pamiêci
	}
	delete[] tablica;





	//int rozmiary[5] = { 10000,50000,100000,500000,1000000 };
	//double stopien_posortowania[7] = { 1,0.25,0.5,0.75,0.95,0.99,0.997 -1};
	//for (int rozmiar = 0; rozmiar < 5; rozmiar++)
	//{
	//	for (int stopien = 0; stopien < 6; stopien++)
	//	{
	//		int** tablica = new int *[100];

	//		for (int row = 0; row < 99; row++)  //utworzenie 100 tablic
	//		{
	//			tablica[row] = new int[rozmiar];
	//		}



	//		std::cout << rozmiary[rozmiar] << " " << stopien_posortowania[stopien];
	//		for (int row = 0; row < 99; row++)
	//		{
	//			for (int i = 0; i < rozmiary[rozmiar]-1; i++)
	//			{
	//				tablica[row][i] = rand();  //wype³nienie tablic liczbami losowymi
	//				
	//			}
	//		}
	//		std::cout << "wypelnione";



			//if(stopien_posortowania[stopien]!=1)
			//	for (int i = 0; i < 99; i++)
			//	{
			//		quicksort(tablica[i], 0, rozmiary[rozmiar] - 1, stopien_posortowania[stopien]);  //wstêpne sortowanie
			//	}
			//else if (stopien_posortowania[stopien] == -1.0)
			//{
			//	for (int i = 0; i < 99; i++)
			//	{
			//		inv_quicksort(tablica[i], 0, rozmiary[rozmiar] - 1);   // wstêpne odwrotne sortowanie
			//	}
			//}

			//for (int i = 0; i < 99; i++)
			//{
			//	int *tab_pom = new int[rozmiary[rozmiar]];
			//	auto start = std::chrono::system_clock::now();
			//	//bubble(tablica[i], wielkosc);
			//	//insert(tablica[i], k);
			//	quicksort(tablica[i], 0, rozmiary[rozmiar] - 1, stopien_posortowania[stopien]);  //czwarty parametr to stopieñ posortowania w % (0-1)
			//	//merge_sort(tablica[i], tab_pom, 0, wielkosc - 1);
			//	auto end = std::chrono::system_clock::now();
			//	std::chrono::duration<double> elapsed_seconds = end - start;

			//}
	//		for (int i = 0; i < 99; i++)
	//		{
	//			delete[] tablica[i];   //zwolnienie pamiêci
	//		}
	//		delete[] tablica;
	//		std::cout << "Kolejny stopien";
	//	}
	//	std::cout << "Kolejny rozmiar";
	//}



	system("pause");
	return 1;
}