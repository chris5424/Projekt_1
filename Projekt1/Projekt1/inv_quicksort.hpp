#pragma once

template <typename T>
int inv_podziel(T tab[], int left, int right)
{
	T pivot = tab[((left + right) / 2)];
	int i = left;
	int j = right;
	while (true)
	{
		while (tab[i] > pivot)
		{
			i++;
		}
		while ((tab[j] < pivot) && (j > 0))
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
bool inv_quicksort(T tab[], int left, int right)
{
	if (right > left)
	{
		T piv = inv_podziel(tab, left, right);
		inv_quicksort(tab, left, piv);
		inv_quicksort(tab, piv + 1, right);
	}
	return 1;
}