#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: Return the diff btw the heights of the nodes
 * or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: if the tree is NULL, must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh = 0, rh = 0;

	if (tree)
	{
		lh = (tree->left) ? 1 + binary_tree_height(tree->left) : 1;
		rh = (tree->right) ? 1 + binary_tree_height(tree->right) : 1;
		return (lh > rh ? lh : rh);
	}
	return (0);
}
