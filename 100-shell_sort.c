#include "sort.h"
/**
 * shell_sort -Sort an Array using shell sort
 * @array: array of Int
 * @size: array size
 **/

void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, ids, jds;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (ids = gap; ids < size; ids++)
		{
			temp = array[ids];
			jds = ids;
			while (jds >= gap && array[jds - gap] > temp)
			{
				array[jds] = array[jds - gap];
				jds -= gap;
			}
			array[jds] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
