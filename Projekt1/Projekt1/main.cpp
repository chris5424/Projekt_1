#include <iostream>
#include <cstdlib>
#include <chrono>

#include "bubble.hpp"
#include "insert.hpp"
#include "merge.hpp"
#include "quicksort.hpp"
#include "tester.hpp"


int main()
{
	std::cout << "Podaj wielkosc tablicy do posortowania: ";
	int k;
	std::cin >> k;
	int* tab_10k = new int[k];
	for (int i = 0; i < k; i++)
	{
		tab_10k[i] = std::rand();
	}
	/*for (int i = 0; i < k; i++)
	{
		std::cout << tab_10k[i] << " ";
	}*/
	auto start = std::chrono::system_clock::now(); //start czasu

	//bubble(tab_10k, k);
	//insert(tab_10k, k);
	//quicksort(tab_10k, 0, k-1);

	auto end = std::chrono::system_clock::now(); //koniec czasu

	std::chrono::duration<double> elapsed_seconds = end - start;

	if (czy_posortowane(tab_10k,k)==1)
	{
		std::cout << "Posortowane\nCzas sortowania: " << elapsed_seconds.count() << "s\n";
		std::cout << "\n";
	}
	else
	{
		std::cout << "Blad sortowania\n";
	}

	for (int i = 0; i < k; i++)
	{
		//std::cout << tab_10k[i] << " ";
	}
	delete[] tab_10k;
	tab_10k = NULL;
	system("pause");
	return 1;
}