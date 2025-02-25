#include "sort.h"

/**
  * split - pivot and split
  * @arr: array
  * @left: leftmost index
  * @right:rightmost index
  * @size: size of full index
  * Return: pivot index
  */
int split(int *arr, int left, int right, size_t size)
{
	int i, i2, pivot, tmp;

	pivot = arr[right];
	i = left;
	i2 = right;

	while (1)
	{
		do i++;
		while (arr[i] < pivot);
		do i2--;
		while (arr[i2] > pivot);
		if (i < i2)
		{
			tmp = arr[i2];
			arr[i2] = arr[i];
			arr[i] = tmp;
			print_array(arr, size);
		}
		else
			return (i2);
	}
}

/**
  * recursive_sort - sorting algorithm
  * @arr: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: size of full array
  */
void recursive_sort(int *arr, int left, int right, size_t size)
{
	int pivot;

	if ((right - left) < 2)
		return;
	pivot = split(arr, left, right, size);
	recursive_sort(arr, left, pivot, size);
	recursive_sort(arr, pivot, right, size);
}

/**
  * quick_sort_hoare - quicksort algorithm
  * @array: array to be sorted
  * @size: size of array
  */
void quick_sort_hoare(int *array, size_t size)
{
	recursive_sort(array, 0, size - 1, size);
}
