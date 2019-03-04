#include <iostream>
#include <cstdlib>
#include <time.h>

void bubble(int tab[], int s)
{
	bool zamiana = 0;
	do
	{
		zamiana = 0;
		for (int i = 0; i < s-1; i++)
		{
			
			if (tab[i] > tab[i + 1])
			{
				int temp;
				temp=tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				zamiana = 1;
			}
		}
		
	} while (zamiana);
}



int main()
{
	time_t TimeStart, TimeEnd;
	const int k = 100000;
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