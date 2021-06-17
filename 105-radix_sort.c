#include "sort.h"

/**
 * getMax - A utility function to get maximum value in arr[]
 * @array: Pointer integer
 * @n: integer
 * Return: mx
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
	return (mx);
}

/**
 * countSort - A function to do counting sort of array[]
 * @array: Pointer integer
 * @size: Size_t
 * @exp: integer
 * @output: Pointer integer
 * Return: void
 *  according to the digit represented by exp.
 */
void countSort(int *array, int size, int exp, int *output)
{
	/*int output[size];*/ /*Output array*/
	int count[10] = { 0 };
	int i;

	/*Store count of occurrence in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/**
	* Change count[i] so that count[i] now contains actual
	* position of this digit in output[]
	*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/**
	* Copy the output array to array[], so that array[] now contains
	* sorted numbers according to current digit
	*/
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Main function to that sorts arr[] of size n using Radix Sort
 * @array: Pointer integer
 * @size: Size_t
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int exp;
	int max;
	int *sz;

	if (!array || size < 2)
		return;

	sz = (malloc(sizeof(int) * size));
	if (!sz)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, sz);
		print_array(array, size);
	}
	free(sz);
}
