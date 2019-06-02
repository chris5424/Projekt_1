#pragma once

template <typename T>
bool insert(T tab[], int size)
{
	for (int i = 1; i < size; i++)
	{
		T temp = tab[i];
		int j = i - 1;
		while (j >= 0 && temp < tab[j])
		{
			tab[j + 1] = tab[j];
			j = j - 1;
		}
		tab[j + 1] = temp;
	}
	return 1;
}