#include "sort.h"

/**
 * stup - recurrssive heapSort
 * @array: Array of int
 * @heap: size of heap data
 * @ids: index
 * @size: size of array
 */

void stup(int *array, int heap, int ids, int size)
{
	int lards = ids, left = 2 * ids + 1, right = 2 * ids + 2, t;

	if (left < heap && array[left] > array[lards])
		lards = left;
	if (right < heap && array[right] > array[lards])
		lards = right;
	if (lards != ids)
	{
		t = array[ids], array[ids] = array[lards], array[lards] = t;
		print_array(array, size);
		stup(array, heap, lards, size);
	}
}

/**
 * heap_sort - Sorts array with heap sort algo
 * @array: array to sort
 * @size: Size of array to sort
 */

void heap_sort(int *array, size_t size)
{
	int ids = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; ids >= 0; ids--)
		stup(array, size, ids, size);
	for (ids = size - 1; ids >= 0; ids--)
	{
		temp = array[0];
		array[0] = array[ids];
		array[ids] = temp;
		if (ids > 0)
			print_array(array, size);
		stup(array, ids, 0, size);
	}

}
