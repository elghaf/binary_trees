#include "binary_trees.h"

/**
 * array_to_avl - func turns  array to a avl tree
 * @array: the array to turns to AVL tree
 * @size: array size
 * Return: AVL tree from array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t a, b = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (avl_insert(&root, array[a]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
