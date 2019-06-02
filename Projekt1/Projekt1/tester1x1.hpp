#pragma once
#include <iostream>

template <typename T>
bool ifSorted1x1(T tab[], int size)
{
	int bad = 0;

	for (int i = 0; i < size - 1; i++)
	{
		if (tab[i] > tab[i + 1])
		{
			bad++;
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