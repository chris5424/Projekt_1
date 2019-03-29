#pragma once
#include <iostream>

template <typename T>
bool czy_posortowane(T **tab, int rozmiar)
{
	int bad = 0;
	for (int row = 0; row < 99; row++)
	{
		for (int i = 0; i < rozmiar - 1; i++)
		{
			if (tab[row][i] > tab[row][i + 1])
			{
				bad++;
			}
		}

	}
	if (bad > 0)
	{
		std::cout << bad << " missort\n";
		return 0;
	}
	else
	{
		return 1;
	}
}