#pragma once

template <typename T>
int podziel(T tab[], int left, int right)
{
	T pivot = tab[((left + right) / 2)];
	int i = left;
	int j = right;
	while (true)
	{
		while (tab[i] < pivot)
		{
			i++;
		}
		while ((tab[j] > pivot) && (j > 0))
		{
			j--;
		}
		if (i < j)
		{
			
			T temp;
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			i++;
			j--;
		}
		else
		{
			break;
		}
	}
	return j;
}

template <typename T>
bool quicksort(T tab[], int left, int right, double sorted)
{
	if (right > left)
	{
		//podzia³ tablicy
		T piv = podziel(tab, left, static_cast<T>(right*sorted));
		//wywo³ania rekurencyjne
		quicksort(tab, left, piv, 1);
		quicksort(tab, piv + 1, static_cast<T>(right*sorted), 1);
	}
	return 1;
}

