#pragma once

template <typename T>
void maxheap(T tab[], int rozmiar, int parentInd)
{
	int maxIndex = parentInd;
	int leftChild = parentInd * 2 + 1;
	int rightChild = parentInd * 2 + 2;

	if (leftChild < rozmiar && tab[leftChild] > tab[maxIndex]) {
		maxIndex = leftChild;
	}
	if (rightChild < rozmiar && tab[rightChild] > tab[maxIndex]) {
		maxIndex = rightChild;
	}
	if (maxIndex != parentInd) {
		T temp;
		temp = tab[maxIndex];
		tab[maxIndex] = tab[parentInd];
		tab[parentInd] = temp;
		maxheap(tab, rozmiar, maxIndex);
	}
}

template <typename T>
void heapsort(T tab[], int rozmiar)
{
	if (rozmiar == 0) {
		return;
	}
	int to_sort = rozmiar;
	for (int i = to_sort / 2 - 1; i >= 0; i--) {
		maxheap(tab, rozmiar, i);
	}

	for (int i = to_sort - 1; i > 0; i--) {
		T temp;
		temp = tab[0];
		tab[0] = tab[i];
		tab[i] = temp;
		to_sort--;
		maxheap(tab, to_sort, 0);
	}
}





template <typename T>
void maxheap_intro(T tab[], int right, int parentInd)
{
	int maxIndex = parentInd;
	int leftChild = parentInd * 2 + 1;
	int rightChild = parentInd * 2 + 2;

	if (leftChild < right && tab[leftChild] > tab[maxIndex]) {
		maxIndex = leftChild;
	}
	if (rightChild < right && tab[rightChild] > tab[maxIndex]) {
		maxIndex = rightChild;
	}
	if (maxIndex != parentInd) {
		T temp;
		temp = tab[maxIndex];
		tab[maxIndex] = tab[parentInd];
		tab[parentInd] = temp;
		maxheap(tab, right, maxIndex);
	}
}
template <typename T>
void heapsort_intro(T tab[],int left, int right)
{
	if ((right-left) == 0) {
		return;
	}
	int to_sort = right-left;
	for (int i = to_sort / 2 - 1; i >= left; i--) {
		maxheap(tab, right, i);
	}

	for (int i = to_sort - 1; i > left; i--) {
		T temp;
		temp = tab[left];
		tab[left] = tab[i];
		tab[i] = temp;
		to_sort--;
		maxheap(tab, to_sort, left);
	}
}
