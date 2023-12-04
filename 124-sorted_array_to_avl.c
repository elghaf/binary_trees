#include "binary_trees.h"
/**
 * aux_sort - func creates a tree using the half element of the array
 * @parent: parent node
 * @array: sorted array
 * @begin: start position
 * @last: ending array position
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *rt;
	binary_tree_t *ax;
	int md = 0;

	if (begin <= last)
	{
		md = (begin + last) / 2;
		ax = binary_tree_node((binary_tree_t *)parent, array[md]);
		if (ax == NULL)
			return (NULL);
		rt = (avl_t *)ax;
		rt->left = aux_sort(rt, array, begin, md - 1);
		rt->right = aux_sort(rt, array, md + 1, last);
		return (rt);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - func create a alv tree from sorted array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: alv tree form sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
