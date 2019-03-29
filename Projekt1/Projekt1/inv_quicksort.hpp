#pragma once

template <typename T>
int inv_podziel(T tab[], int l, int p)
{
	T pivot = tab[((l + p) / 2)];
	int i = l;
	int j = p;
	while (true)
	{
		while (tab[i] > pivot)
		{
			//std::cout << "l";
			i++;
		}
		while ((tab[j] < pivot) && (j > 0))
		{
			//std::cout << "p";
			j--;
		}
		if (i < j)
		{
			//std::swap(tab[i], tab[j]);
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
		//std::cout << "w";
	}
	return j;
}

template <typename T>
bool inv_quicksort(T tab[], int l, int p)
{
	if (p > l)
	{
		T piv = inv_podziel(tab, l, p);
		inv_quicksort(tab, l, piv);
		inv_quicksort(tab, piv + 1, p);
	}
	return 1;
}