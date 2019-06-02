#pragma once

template <typename T>
bool bubble(T tab[], int size)
{
	bool change = 0;
	do
	{
		change = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				T temp;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				change = 1;
			}
		}
	} while (change);
	return 1;
}