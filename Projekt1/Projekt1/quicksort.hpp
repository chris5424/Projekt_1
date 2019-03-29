#pragma once
template <typename T>
int podziel(T tab[], int l, int p)
{
	T pivot = tab[((l + p) / 2)];
	int i = l;
	int j = p;
	while (true)
	{
		while (tab[i] < pivot)
		{
			//std::cout << "l";
			i++;
		}
		while ((tab[j] > pivot) && (j > 0))
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
bool quicksort(T tab[], int l, int p, double sorted)
{
	if (p > l)
	{
		T piv = podziel(tab, l, static_cast<T>(p*sorted));
		quicksort(tab, l, piv, 1);
		quicksort(tab, piv + 1, static_cast<T>(p*sorted), 1);
	}
	return 1;
}

