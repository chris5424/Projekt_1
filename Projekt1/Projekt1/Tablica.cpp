#include <iostream>
#include <cstdlib>
//#include <algorithm>





void bubble(int tab[], int s)
{
	int zamiana = 0;
	do
	{
		for (int i = 0; i < s-1; i++)
		{
			zamiana = 0;
			if (tab[i] > tab[i + 1])
			{
				std::swap(tab[i], tab[i + 1]);
				zamiana = 1;
				//std::cout << "Zamiana";
			}
		}
		
	} while (zamiana =! 0);
}







int main()
{
	const int k = 5;
	int tab_10k[k];
	for (int i = 0; i < k; i++)
	{
		tab_10k[i] = std::rand();
	}
	for (int i = 0; i < k; i++)
	{
		std::cout << tab_10k[i] << " ";
	}
	bubble(tab_10k, k);
	std::cout << "Posortowane";
	for (int i = 0; i < k; i++)
	{
		std::cout << tab_10k[i] << " ";
	}
	
	system("pause");
}