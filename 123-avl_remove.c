#include "binary_trees.h"

/**
 * bal - func Measures balance factor of a AVL
 * @tree: tree to traverse
 * Return: a balanced factor
 */
void bal(avl_t **tree)
{
	int val_b;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	val_b = binary_tree_balance((const binary_tree_t *)*tree);
	if (val_b > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (val_b < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - func to get the next successor
 * @node: tree being checked
 * Return: min tree value
 */
int successor(bst_t *node)
{
	int l = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		l = successor(node->left);
		if (l == 0)
		{
			return (node->n);
		}
		return (l);
	}

}
/**
 *remove_type - Removes a node depending of its children
 *@root: node to remove
 *Return: 0 == no children || any val
 */
int remove_type(bst_t *root)
{
	int val_new = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		val_new = successor(root->right);
		root->n = val_new;
		return (val_new);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int tp = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		tp = remove_type(root);
		if (tp != 0)
			bst_remove(root->right, tp);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *a_root = (avl_t *) bst_remove((bst_t *) root, value);

	if (a_root == NULL)
		return (NULL);
	bal(&a_root);
	return (a_root);
}
