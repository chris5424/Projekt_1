#include <cmath>
#include <iostream>

#include "quicksort.hpp"

bool quicksort(int tab[], int l, int p)
{
	
	int pivot = tab[((l + p) / 2)];
	int i = l;
	int j = p;
	while (true)
	{
		while (tab[i] < pivot)
		{
			i++;
		}
		while ((tab[j] > pivot)&&(j > 0))
		{
			j--;
		}
		if(i<j)
		{
			//std::swap(tab[i], tab[j]);
			int temp;
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
		else
		{
			break;
		}
	}
	if (j > l)
	{
		quicksort(tab, l, j);
	}
	if (i < p)
	{
		quicksort(tab, i+1, p);
	}
	return 1;
}