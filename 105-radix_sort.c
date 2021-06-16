#include "sort.h"

int getMax(int *array, int n);
void countSort(int *array, int size, int exp);

/**
 * radix_sort - The main function to that sorts arr[] of size n using Radix Sort
 * @array: Pointer integer
 * @size: Size_t
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int exp;
	int max;
	max = getMax(array, size);
	for (exp = 1; max/exp > 0; exp*=10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
/**
 * radix_sort - A utility function to get maximum value in arr[]
 * @array: Pointer integer
 * @n: integer
 * Return: void
 */
int getMax(int *array, int n)
{
	int i;
	int mx = array[0];

	for (i = 1; i < n; i++)
	{
		if (array[i] > mx)
			mx = array[i];
	}
	return mx;
}
/**
 * countSort - A function to do counting sort of array[] according to the digit represented by exp.
 * @array: Pointer integer
 * @size: Size_t
 * @exp: integer
 * Return: void
 */
void countSort(int *array, int size, int exp)
{
	int output[size]; /*Output array*/
	int i, count[10] = { 0 };
	/*Store count of occurrence in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] so that count[i] now contains actual position of this digit in output[] */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;		
	}

	/* Copy the output array to array[], so that array[] now contains sorted numbers according to current digit */
	for (i = 0; i < size; i++)
		array[i] = output[i];
}