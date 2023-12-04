#include <stdlib.h>
#include "binary_trees.h"
/**
* binary_tree_node - create a new node
* @parent: parent of the new node
* @value: value to put into the new node
* Return: new node or NULL if fails to create node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *NewNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
if (NewNode == NULL)
	return (NULL);
NewNode->n = value;
NewNode->left = NULL;
NewNode->right = NULL;
NewNode->parent = parent;
return (NewNode);
}
