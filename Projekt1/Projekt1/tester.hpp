#pragma once

template <typename T>
bool ifSorted(T **tab, int size)
{
	int bad = 0;
	for (int row = 0; row < 99; row++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (tab[row][i] > tab[row][i + 1])
			{
				bad++;
			}
		}

	}
	if (bad > 0)
	{
		std::cout << bad << " missort\n";
		return 0;
	}
	else
	{
		return 1;
	}
}