#pragma once

template <typename T>
bool bubble(T tab[], int size)
{
	bool zamiana = 0;
	do
	{
		zamiana = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				T temp;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				zamiana = 1;
			}
		}
	} while (zamiana);
	return 1;
}