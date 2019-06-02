#pragma once

template <typename T>
void merge(T tab[], T temp[], int left, int mid, int right)
{
	int i = left, j = mid + 1;

	for (int i = left; i <= right; i++)
	{
		temp[i] = tab[i]; //copy to temporary table
	}


	for (int k = left; k <= right; k++)
	{
		if (i <= mid)
		{
			if (j <= right)
			{
				if (temp[j] < temp[i])
				{
					tab[k] = temp[j++];
				}
				else							//merge into main table
					tab[k] = temp[i++];
			}
			else
				tab[k] = temp[i++];
		}
		else
			tab[k] = temp[j++];
	}
}

template <typename T>
bool merge_sort(T tab[], T temp[], int left, int right)
{
	if (right <= left) return 1;  //if one element - end sorting

	int mid = (right + left) / 2;


	merge_sort(tab, temp, left, mid);
	merge_sort(tab, temp, mid + 1, right);

	merge(tab, temp, left, mid, right);
}