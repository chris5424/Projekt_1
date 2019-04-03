#pragma once
#include <cmath>
#include "quicksort.hpp"
#include "heapsort.hpp"
#include "insert.hpp"

template <typename T>
void intro_sort(T tab[], int left, int right, int maxdepth)
{
	if (maxdepth == 0)
	{
		heapsort_intro(tab, left, right);
		return;
	}
	int n = podziel(tab, left, right);
	if (n > 9)
	{
		intro_sort(tab, left, n, maxdepth - 1);
	}
	if ((right-1-n) > 9)
	{
		intro_sort(tab, n + 1, right, maxdepth - 1);
	}
}
template <typename T>
void intro_sort(T tab[], int rozmiar)
{
	int maxdepth = 2 * floor(log(rozmiar));
	intro_sort(tab, 0, rozmiar, maxdepth);
	insert(tab, rozmiar);
}
