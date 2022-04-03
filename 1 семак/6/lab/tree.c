#include <stdio.h>
#include <malloc.h>

#include "util.h"
#include "compare.h"

struct node_t;

typedef struct node_t
{
	char *data;
	struct node_t *left;
	struct node_t *right;
} node;

typedef struct
{
	int size;
	struct node_t *first;
} tree;

tree *createTree()
{
	tree *newTree = (tree *)newMem(sizeof(tree));
	newTree->size = 0;
	newTree->first = NULL;
	return newTree;
}

int nodeDepth(node *node_p)
{
	int depth = 1;
	int leftDepth = 0;
	int rightDepth = 0;

	if (node_p->left != NULL)
	{
		leftDepth = nodeDepth(node_p->left);
	}
	if (node_p->right != NULL)
	{
		rightDepth = nodeDepth(node_p->right);
	}

	depth += (leftDepth > rightDepth ? leftDepth : rightDepth);

	return depth;
}

int calculateDepth(tree *tree_p)
{
	if (tree_p->first == NULL)
	{
		return 0;
	}
	return nodeDepth(tree_p->first);
}

void insertIfPossibly(node *node_p, node *newNode)
{
	if (compareByAlphabet(node_p->data, newNode->data))
	{
		if (node_p->left == NULL)
		{
			node_p->left = newNode;
			return;
		}

		insertIfPossibly(node_p->left, newNode);

		return;
	}
	if (node_p->right == NULL)
	{
		node_p->right = newNode;
		return;
	}

	insertIfPossibly(node_p->right, newNode);
}

void insertTreeNode(tree *tree_p, char *str)
{
	node *newNode = (node *)newMem(sizeof(node));
	newNode->data = str;
	newNode->left = NULL;
	newNode->right = NULL;

	tree_p->size = tree_p->size + 1;

	if (tree_p->first == NULL)
	{
		tree_p->first = newNode;
	}
	else
	{
		insertIfPossibly(tree_p->first, newNode);
	}
}

void printNode(node *node_p)
{
	char *word = node_p->data;
	for (int i = 0; word[i] != '\0'; i++)
	{
		printf("%c", word[i]);
	}
}

void printNext(node *node_p)
{
	if (node_p->left != NULL)
	{
		printNext(node_p->left);
	}
	printNode(node_p);
	printf("\n");
	if (node_p->right != NULL)
	{
		printNext(node_p->right);
	}
}

void printTree(tree *tree_p)
{
	printNext(tree_p->first);
}