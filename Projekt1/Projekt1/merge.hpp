#pragma once

template <typename T>
void merge(T tab[], T pom[], int left, int mid, int right)
{
	int i = left, j = mid + 1;

	for (int i = left; i <= right; i++)
	{
		pom[i] = tab[i]; //kopiowanie do tablicy pomocniczej
	}


	for (int k = left; k <= right; k++)
	{
		if (i <= mid)
		{
			if (j <= right)
			{
				if (pom[j] < pom[i])
				{
					tab[k] = pom[j++];
				}
				else							//scalenie tablic w g³ównej
					tab[k] = pom[i++];
			}
			else
				tab[k] = pom[i++];
		}
		else
			tab[k] = pom[j++];
	}
}

template <typename T>
bool merge_sort(T tab[], T pom[], int left, int right)
{
	if (right <= left) return 1;  //gdy zostaje jeden element - koniec sortowania

	int mid = (right + left) / 2;


	merge_sort(tab, pom, left, mid);
	merge_sort(tab, pom, mid + 1, right);

	merge(tab, pom, left, mid, right);
}