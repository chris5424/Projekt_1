#pragma once
#include <cmath>
#include "quicksort.hpp"
#include "heapsort.hpp"
#include "insert.hpp"

//Moja dzia³a i to lepiej ni¿ ta od Zwolina nie ruszaæ!!!!!!
template <typename T>
void intro_sort(T tab[], int firstIndex, int lastIndex, int maxdepth)
{
	if (maxdepth == 0)
	{
		heapsort_intro(tab, firstIndex, lastIndex);
		return;
	}
	int n = podziel(tab, firstIndex, lastIndex);
	if (n > 9)
	{
		intro_sort(tab, firstIndex, n, maxdepth - 1);
	}
	if ((lastIndex-1-n) > 9)
	{
		intro_sort(tab, n + 1, lastIndex, maxdepth - 1);
	}
	
}
template <typename T>
void intro_sort(T tab[], int rozmiar)
{
	int maxdepth = 2 * floor(log(rozmiar));
	intro_sort(tab, 0, rozmiar, maxdepth);
	insert(tab, rozmiar);
}


//Zwolina dzia³a nie ruszaæ!!!!!
//void intro_sort(int tab[], int firstIndex, int lastIndex, int maxdepth) 
//{
//	if (firstIndex < lastIndex)
//	{
//		if (maxdepth==0)
//		{
//			heapsort_intro(tab, firstIndex, lastIndex);
//		}
//		int n = podziel(tab, firstIndex, lastIndex);
//		intro_sort(tab, firstIndex, n, maxdepth - 1);
//		intro_sort(tab, n + 1, lastIndex, maxdepth - 1);
//	}
//}
//void intro_sort(int tab[], int rozmiar)
//{
//	int maxdepth = 2 * floor(log(rozmiar));
//	intro_sort(tab, 0, rozmiar, maxdepth);
//}