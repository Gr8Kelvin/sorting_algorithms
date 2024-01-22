#include "sort.h"

/**
 * swap - swap two int
 * @abs: int
 * @bbs: int
 * Return: (void) Swaped int
 */
void swap(int *abs, int *bbs)
{
	int tmp;

	tmp = *abs;
	*abs = *bbs;
	*bbs = tmp;
}
/**
 * parti - Partition an array and using pivot
 * @array: Array
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */
int parti(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int xds = low - 1, yds;

	for (yds = low; yds <= high; yds++)
	{
		if (array[yds] <= pivot)
		{
			xds++;
			if (xds != yds)
			{
				swap(&array[xds], &array[yds]);
				print_array(array, size);
			}
		}
	}
	return (xds);
}
/**
 * lomuto_qsort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int ibs;

	if (low < high)
	{
		ibs = parti(array, low, high, size);
		lomuto_qsort(array, low, ibs - 1, size);
		lomuto_qsort(array, ibs + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
