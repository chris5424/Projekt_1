#pragma once
bool insert(int tab[], int s)
{
	for (int i = 1; i < s; i++)
	{
		int porownywana = tab[i];
		int j = i - 1;
		while (j >= 0 && porownywana < tab[j])
		{
			tab[j + 1] = tab[j];
			j = j - 1;
		}
		tab[j + 1] = porownywana;
	}
	return 1;
}