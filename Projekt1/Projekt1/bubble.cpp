#include "bubble.hpp"

void bubble(int tab[], int s)
{
	bool zamiana = 0;
	do
	{
		zamiana = 0;
		for (int i = 0; i < s - 1; i++)
		{

			if (tab[i] > tab[i + 1])
			{
				int temp;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				zamiana = 1;
			}
		}

	} while (zamiana);
}