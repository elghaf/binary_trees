#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to go through
 * Return: height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lf = 0;
	size_t rt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			lf = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lf > rt) ? lf : rt);
		}
}

/**
 * binary_tree_balance - Func measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced_factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int r = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		r = ((int)binary_tree_height(tree->right));
		total = left - r;
	}
	return (total);
}

/**
 * tree_is_perfect - says if a tree is perfect or not
 * @tree: tree to check
 * Return: 0 if is not a perfect or other number that is the level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + tree_is_perfect(tree->left);
		r = 1 + tree_is_perfect(tree->right);
		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - perfect or not a tree
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		r = tree_is_perfect(tree);
		if (r != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - func checks if a binary tree is a valid Max Binary Heap
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int valb;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	valb = binary_tree_balance(tree);
	if (valb == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (valb == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
