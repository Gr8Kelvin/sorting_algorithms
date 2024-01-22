#include "sort.h"
#include <stdio.h>


/**
 * merge -  Sort array using merge sort
 * @array: array if ints
 * @size: size of the array
 * @l: pointer to left array
 * @r: pointer to right array
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int ids = 0, jds = 0, kds = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_left);
	printf("[right]: ");
	print_array(r, size_right);

	while (ids < size_left && jds < size_right)
	{
		if (l[ids] < r[jds])
			array[kds++] = l[ids++];
		else
			array[kds++] = r[jds++];
	}

	while (ids < size_left)
		array[kds++] = l[ids++];

	while (jds < size_right)
		array[kds++] = r[jds++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	mid = size / 2;
	/*left = (int*)malloc(sizeof(int) * mid);*/
	/*right = (int*)malloc(sizeof(int) * (size - mid));*/

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
