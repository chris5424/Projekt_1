#include <cmath>
#include <iostream>

#include "quicksort.hpp"

//bool quicksort(int tab[], int s)
//{
//	int* left = new int[s / 2];
//	int* right = new int[s / 2];
//	split(tab[],left[],right[]);
//	quicksort(left[],s/2);
//	quicksort(right[],s/2);
//	return 1;
//}
//
//bool split(int tab[], int left[], int right[])
//{
//	pivot(tab[]);
//
//	return 1;
//}
//
//int pivot(int tab[])
//{
//	int pivot;
//	pivot = tab[s / 2];
//	return pivot;
//}

bool quicksort(int tab[], int l, int p)
{
	while (true)
	{
		int pivot = tab[(int)ceil((l + p) / 2)];
		int i = l;
		while (tab[i] < pivot)
		{
			i++;
		}
		int j = p - 1;
		while (tab[j] > pivot&&j > 0)
		{
			j--;
		}
		/*int temp;
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;*/
		if(i<=j)
		{
			std::swap(tab[i], tab[j]);
		}
		else
		{
			break;
		}
	}

	return 1;
}