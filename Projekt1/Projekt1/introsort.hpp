#pragma once
#include <cmath>
#include "quicksort.hpp"
#include "heapsort.hpp"
#include "insert.hpp"

//Testowane Marty dzia³a dobrze
//template <typename T>
//void IntroSort(T tab[], int left, int right, int MaxRekurencji)
//{
//	if (left < right)
//	{
//		if (MaxRekurencji == 0)
//		{
//			heapsort_intro(tab,left, right);
//			//return;
//		}
//
//
//		int pivotIndex = podziel(tab, left, right);
//		IntroSort(tab, left, pivotIndex, MaxRekurencji - 1);
//		IntroSort(tab, pivotIndex + 1, right, MaxRekurencji - 1);
//
//	}
//}
//
//template <typename T>
//void IntroSort(T tab[], int right)
//{
//	int MaxRekurencji = (2 * floor(log2(right)));
//	IntroSort(tab, 0, right, MaxRekurencji);
//}

//Od Mi³osza v2
//template <typename T>
//void swap(T* tab, int a, int b) 
//{
//	T temp = tab[a];
//	tab[a] = tab[b];
//	tab[b] = temp;
//}
//template <typename T>
//void introsort(T* tab, int size, int availibleDepth) 
//{
//	if (availibleDepth > 0) 
//	{
//		heapsort(tab, size);
//		return;
//	}
//	int pivotIndex = size/2;
//	T pivot = tab[pivotIndex];
//	swap(tab, pivotIndex, size - 1);
//	int changeIndex = 0;
//	for (int i = 0; i < size - 1; i++)
//		if (tab[i] < pivot)
//			swap(tab, i, changeIndex++);
//	swap(tab, size - 1, changeIndex);
//	if (0 < changeIndex - 1 && changeIndex > 9)
//		introsort(tab, changeIndex, availibleDepth--);
//	if (changeIndex + 1 < size - 1 && size - changeIndex - 1 > 9)
//		introsort(tab + changeIndex + 1, size - changeIndex - 1, availibleDepth--);
//}
//template <typename T>
//void intro_sort(T* tab, int size)
//{
//	introsort(tab, size, (int)floor(2 * log2(size)));
//	insert(tab, size);
//}

//Z jakiejœ stronki (sta³a z³o¿onoœæ czasowa)  https://www.programmingalgorithms.com/algorithm/intro-sort?lang=C%2B%2B
//void intro_sort(int data[], int count) 
//{
//	int partitionSize = podziel(data, 0, count - 1);
//
//	if (partitionSize < 16)
//	{
//		insert(data, count);
//	}
//	else if (partitionSize > (2 * log(count)))
//	{
//		heapsort(data, count);
//	}
//	else
//	{
//		quicksort(data, 0, count - 1,1);
//	}
//}

//Mój
//template <typename T>
//void sort(T tab[], int l, int p, int maxdepth)
//{
//	if ((l - p) <= 16)
//	{
//		insert(tab, p);
//	}
//	//if (p <= 1)
//		//return;
//	else if (maxdepth = 0)
//	{
//		heapsort(tab, p);
//		return;
//	}
//	else
//	{
//		int piv = podziel(tab, l, p);
//		sort(tab, l, piv - 1, maxdepth - 1);
//		sort(tab, piv + 1, p, maxdepth - 1);
//	}
//}
//template <typename T>
//void intro_sort(T tab[], int rozmiar)
//{
//	int maxdepth = 2 * floor(log(rozmiar));
//	sort(tab, 0, rozmiar, maxdepth);
//}

//Mi³osz
//void introsort(T* tab, int size, int availibleDepth) 
//{
//	if (availibleDepth > 0) 
//	{
//		heapsort(tab, size);
//		return;
//	}
//	int pivotIndex = choosePivot(tab, size);
//	T pivot = tab[pivotIndex];
//	swap(tab, pivotIndex, size - 1);
//	int changeIndex = 0;
//	for (int i = 0; i < size - 1; i++)
//		if (tab[i] < pivot)
//			swap(tab, i, changeIndex++);
//	swap(tab, size - 1, changeIndex);
//	if (0 < changeIndex - 1 && changeIndex > 9)
//		introsort(tab, changeIndex, availibleDepth--);
//	if (changeIndex + 1 < size - 1 && size - changeIndex - 1 > 9)
//		introsort(tab + changeIndex + 1, size - changeIndex - 1, availibleDepth--);
//}

//Moja dzia³a i to lepiej ni¿ ta od Zwolina nie ruszaæ!!!!!!
//template <typename T>
//void intro_sort(T tab[], int firstIndex, int lastIndex, int maxdepth)
//{
//	if (maxdepth == 0)
//	{
//		heapsort_intro(tab, firstIndex, lastIndex);
//		return;
//	}
//	int n = podziel(tab, firstIndex, lastIndex);
//	if (n > 9)
//	{
//		intro_sort(tab, firstIndex, n, maxdepth - 1);
//	}
//	if ((lastIndex-1-n) > 9)
//	{
//		intro_sort(tab, n + 1, lastIndex, maxdepth - 1);
//	}
//	
//}
//template <typename T>
//void intro_sort(T tab[], int rozmiar)
//{
//	int maxdepth = 2 * floor(log(rozmiar));
//	intro_sort(tab, 0, rozmiar, maxdepth);
//	insert(tab, rozmiar);
//}


//Zwolina dzia³a nie ruszaæ!!!!!
void intro_sort(int tab[], int firstIndex, int lastIndex, int maxdepth) 
{
	if (firstIndex < lastIndex)
	{
		if (maxdepth==0)
		{
			heapsort_intro(tab, firstIndex, lastIndex);
		}
		int n = podziel(tab, firstIndex, lastIndex);
		intro_sort(tab, firstIndex, n, maxdepth - 1);
		intro_sort(tab, n + 1, lastIndex, maxdepth - 1);
	}
}
void intro_sort(int tab[], int rozmiar)
{
	int maxdepth = 2 * floor(log(rozmiar));
	intro_sort(tab, 0, rozmiar, maxdepth);
}