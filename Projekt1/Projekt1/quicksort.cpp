//#include <cmath>
//#include <iostream>
//
//#include "quicksort.hpp"
//
//int podziel(int tab[], int l, int p)
//{
//	int pivot = tab[((l + p) / 2)];
//	int i = l;
//	int j = p;
//	while (true)
//	{
//		while (tab[i] < pivot)
//		{
//			//std::cout << "l";
//			i++;
//		}
//		while ((tab[j] > pivot) && (j > 0))
//		{
//			//std::cout << "p";
//			j--;
//		}
//		if (i < j)
//		{
//			//std::swap(tab[i], tab[j]);
//			int temp;
//			temp = tab[i];
//			tab[i] = tab[j];
//			tab[j] = temp;
//			i++;
//			j--;
//		}
//		else
//		{
//			break;
//		}
//		//std::cout << "w";
//	}
//	return j;
//}
//
//bool quicksort(int tab[], int l, int p, double sorted)
//{
//	if (p > l)
//	{
//		int piv = podziel(tab, l, p*sorted);
//		quicksort(tab, l, piv, 1);
//		quicksort(tab, piv + 1, p*sorted, 1);
//	}
//	return 1;
//}
