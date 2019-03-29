#pragma once

int inv_podziel(int tab[], int l, int p)
{
	int pivot = tab[((l + p) / 2)];
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
			int temp;
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
bool inv_quicksort(int tab[], int l, int p)
{
	if (p > l)
	{
		int piv = inv_podziel(tab, l, p);
		inv_quicksort(tab, l, piv);
		inv_quicksort(tab, piv + 1, p);
	}
	return 1;
}