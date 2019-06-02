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
int size_of_tables[5] = { 10000,50000, 100000, 500000, 1000000 };
double sizing_level[8] = { -1, 1, 0.25, 0.5 , 0.75, 0.95, 0.99, 0.997 }; // -1 - posortowane odwrotnie, 1 - w pe³ni posortowane
std::fstream file;
int **table = new int *[row];
for (int size = 0; size < 5; size++)
{
	std::cout << "Rozmiary: "<< size+1<<"/5 "<<size_of_tables[size]<<std::endl;
	for (int stage = 0; stage < 8; ++stage)
	{
		std::cout << "Stopien wstepnego posortowania: "<<stage+1<<"/8"<<std::endl;

		// utworzenie i wype³nienie tablic
		for (int i = 0; i < row; ++i)
		{
			table[i] = new int[size_of_tables[size]];
			for (int j = 0; j < size_of_tables[size] - 1; ++j)
				table[i][j] = rand();
		}

		//warunek wstêpnego sortowania odwrotnego
		if (sizing_level[stage] == -1.0)
		{
			for (int i = 0; i < row - 1; ++i)
			{
				inverted_quicksort(table[i], 0, size_of_tables[size] - 1);
			}
		}

		//warunek wstêpnego sortowania z parametrem
		else if ((sizing_level[stage] != 1) && (sizing_level[stage] > 0))
		{
			for (int i = 0; i < row - 1; ++i)
			{
				quicksort(table[i], 0, size_of_tables[size] - 1, sizing_level[stage]);
			}
		}

		//w³asciwe sortowanie
		for (int i = 0; i < row; ++i)
		{
			//table pomocnicza przy sortowaniu przez scalanie
			//int *tablica_pomocnicza = new int[rozmiaryTablic[size]];
			auto start = std::chrono::system_clock::now();

			//Tu wpisujemy sortowanie
			//insert(table[i], rozmiaryTablic[size]);
			//quicksort(table[i], 0, size_of_tables[size] - 1, 1); //czwarty parametr to stopieñ posortowania w % (0-1)
			//merge_sort(table[i],tablica_pomocnicza, 0, rozmiaryTablic[size] - 1);
			//heapsort(table[i], rozmiaryTablic[size]);
			intro_sort(table[i], size_of_tables[size]);
			auto end = std::chrono::system_clock::now();

			//sprawdzenie poprawnoœci posortowania/zapis do pliku
			if (ifSorted1x1(table[i], size_of_tables[size]) == 1)
			{
				std::chrono::duration<double> elapsed_seconds = end - start;
				file.open("test.txt", std::ios::out | std::ios::app);
				if (file.good() == true)
				{

					file << i << ";" << size_of_tables[size] << ";" << sizing_level[stage] << ";";
					file << elapsed_seconds.count() << std::endl;
					file.close();
				}
			}

			//jeœli Ÿle posortowane
			else if (ifSorted1x1(table[i], size_of_tables[size]) == 0)
			{
				file.open("test.txt", std::ios::out | std::ios::app);
				if (file.good() == true)
				{
					file << "\nTablica nieposortowana" << "\n";
					file.close();
				}
			}
		}
		for (int q = 0; q < row; q++)
		{
			//delete[] table[q]; //zwolnienie pamiêci
		}
	}
}
std::cout << "Zakonczono pomiary :)"<<std::endl;
delete[] table;
table = NULL;
system("pause");
return 0;
}