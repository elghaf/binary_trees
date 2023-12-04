#include <stdlib.h>

#include "binary_trees.h"
/**
*binary_tree_insert_left - insert a node as left child
*@parent: pointer to the assigned parent of node
*@value: value to store in the new node
*
*Return: new node or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *NewNode;
if (parent == NULL)
	return (NULL);
NewNode = binary_tree_node(parent, value);
if (NewNode == NULL)
	return (NULL);
if (parent->left != NULL)
{
	NewNode->left = parent->left;
	parent->left->parent = NewNode;
}
parent->left = NewNode;
return (NewNode);
}
