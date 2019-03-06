#include <iostream>
#include <cstdlib>
#include <time.h>

#include "bubble.hpp"
#include "insert.hpp"
#include "merge.hpp"
#include "quicksort.hpp"


int main()
{
	time_t TimeStart, TimeEnd;
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
	time(&TimeStart);
	//bubble(tab_10k, k);
	insert(tab_10k, k);
	time(&TimeEnd);
	std::cout << "Posortowane\nCzas sortowania: " << difftime(TimeEnd, TimeStart)<<" sekundy\n";
	std::cout << "\n";
	/*for (int i = 0; i < k; i++)
	{
		std::cout << tab_10k[i] << " ";
	}*/
	delete[] tab_10k;
	tab_10k = NULL;
	system("pause");
	return 1;
}