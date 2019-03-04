#include <iostream>
#include <cstdlib>
#include <time.h>

#include "bubble.hpp"



int main()
{
	time_t TimeStart, TimeEnd;
	const int k = 1000;
	int tab_10k[k];
	for (int i = 0; i < k; i++)
	{
		tab_10k[i] = std::rand();
	}
	/*for (int i = 0; i < k; i++)
	{
		std::cout << tab_10k[i] << " ";
	}*/
	time(&TimeStart);
	bubble(tab_10k, k);
	time(&TimeEnd);
	std::cout << "Posortowane\nCzas sortowania: " << difftime(TimeEnd, TimeStart)<<" sekundy\n";
	for (int i = 0; i < k; i++)
	{
		std::cout << tab_10k[i] << " ";
	}
	
	system("pause");
}