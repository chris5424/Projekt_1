#pragma once
#include <cmath>
#include "quicksort.hpp"
#include "heapsort.hpp"

template <typename T>
void sort(T tab[], int l, int p, int maxdepth)
{
	int piv = podziel(tab, 0, p);
	if (p <= 1)
		return;
	else if (maxdepth == 0)
	{
		heapsort(tab, p);
	}
	else
	{
		sort(tab, 0, piv, maxdepth - 1);
		sort(tab, piv + 1, l, maxdepth - 1);
	}

}

template <typename T>
void intro_sort(T tab[], int rozmiar)
{
	int maxdepth = static_cast<int>((2*log(rozmiar))/log(2));
	sort(tab, 0, rozmiar, maxdepth);
}
