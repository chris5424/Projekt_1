#include <cmath>

#include "quicksort.hpp"

bool quicksort(int tab[], int s)
{
	int* left = new int[s / 2];
	int* right = new int[s / 2];
	split(tab[],left[],right[]);
	quicksort(left[],s/2);
	quicksort(right[],s/2);
	return 1;
}

bool split(int tab[], int left[], int right[])
{
	pick_mid(tab[]);

	return 1;
}

int pick_mid(int tab[])
{
	int mid;
	mid= tab[]
	return mid;
}