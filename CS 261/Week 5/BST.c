/******************************************************************************
** Filename: BST_test_driver.c
** Author(s): Casey Hines -adapted in part using code used in worksheet 29
** 				written by the CS 261 course writers and
**				members of WS Group 22 (Winter 2018):
**					Joseph Christy
**					Andrew Funk
**					Coby Hartman
**					Casey Hines
**					Timothy Loo
**					Pulak Saha
**
** Date: 02/10/18
** Description: Implementation of a binary search tree with a test driver.
**
** Problem Statement: Program a test driver for the BST algorithm and
** execute the operations using the test cases identified in the previous
** question.
**
** Test the search for the maximum and minimum values.
** Test the search for any of the leaves.
** Search for the root.
** Search for values not in the tree.
** Add and remove the max and min values.
** Remove the root.
******************************************************************************/

#ifndef BST_IMP_H
#define BST_IMP_H

#ifndef TYPE
#define TYPE int
#endif

struct Node
{
	TYPE value;
	struct Node * left;
	struct Node * right;
};

struct BinarySearchTree
{
	struct Node *root;
	int size;
};

void initBST(struct BinarySearchTree * tree);
void addBST(struct BinarySearchTree * tree, TYPE newValue);
int sizeBST(struct BinarySearchTree * tree);
struct Node * _nodeAddBST(struct Node * current, TYPE newValue);
int containsBST(struct BinarySearchTree * tree, TYPE d);
void removeBST(struct BinarySearchTree * tree, TYPE d);
TYPE _leftMostChild(struct Node * current);
struct Node * _removeLeftMostChild(struct Node * current);
struct Node * _nodeRemoveBST(struct Node * current, TYPE d);

#endif

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/******************************************************************************
** initBST
******************************************************************************/
void initBST(struct BinarySearchTree * tree)
{
	tree->size = 0;
	tree->root = 0;
}

/******************************************************************************
** addBST
******************************************************************************/
void addBST(struct BinarySearchTree *tree, TYPE newValue)
{
	tree->root = _nodeAddBST(tree->root, newValue);
	tree->size++;
}

/******************************************************************************
** initBST
******************************************************************************/
int sizeBST(struct BinarySearchTree *tree)
{
	return tree->size;
}

/******************************************************************************
** _nodeAddBST
******************************************************************************/
struct Node * _nodeAddBST(struct Node * current, TYPE newValue)
{
	struct Node * newNode;
	if (current == 0)
	{
		newNode = (struct Node *)malloc(sizeof(struct Node));
		assert(newNode != 0);

		newNode->value = newValue;
		newNode->left = newNode->right = 0;
		return newNode;
	}
	else if (newValue < current->value)
		current->left = _nodeAddBST(current->left, newValue);
	else
		current->right = _nodeAddBST(current->right, newValue);

	return current;
}


/******************************************************************************
** containsBST
******************************************************************************/
int containsBST(struct BinarySearchTree * tree, TYPE d)
{
	/* PS - 02/08/2018 */
	assert(tree != 0);

	struct Node *current = tree->root;

	while (current != 0)
	{
		if (current->value == d)
			return 1;

		if (d < current->value)
			current = current->left;
		else
			current = current->right;
	}
	return 0;
}

/******************************************************************************
** removeBST
******************************************************************************/
void removeBST(struct BinarySearchTree * tree, TYPE d)
{
	if (containsBST(tree, d))
	{
		tree->root = _nodeRemoveBST(tree->root, d);
		tree->size--;
	}
}

/******************************************************************************
** _leftMostChild
******************************************************************************/
TYPE _leftMostChild(struct Node * current)
{
	assert(current != 0);
	while (current->left)
	{
		current = current->left;
	}

	return current->value;
}


/******************************************************************************
** _removeLeftMostChild
******************************************************************************/
struct Node* _removeLeftMostChild(struct Node * current)
{
	/*if current is the leftmost node, replace current with right child*/
	if (current->left == 0)
	{
		struct Node * temp = current;
		current = current->right;
		free(temp);
		temp = 0;
		return current;
	}

	/*else, recursively call remove left most child*/
	else
	{
		current->left = _removeLeftMostChild(current->left);
	}
	return current;
}

/******************************************************************************
** _nodeRemoveBST
******************************************************************************/
struct Node * _nodeRemoveBST(struct Node * current, TYPE d)
{
	/*JC 2/8/18*/
	/*if current contains the value we want to delete*/
	if (current->value == d)
	{
		/*if right child is null, replace current with left child*/
		if (current->right == 0)
		{
			struct Node* temp = current;
			current = current->left;
			free(temp);
			temp = 0;
		}
		/*else, replace current value and remove the leftmost child of current’s
		right child*/
		else
		{
			current->value = _leftMostChild(current->right);
			current->right = _removeLeftMostChild(current->right);
		}
		return current;
	}
	/*if test value less/greater than current value, recursively call remove
	on respective child*/
	else if (d < current->value)
		current->left = _nodeRemoveBST(current->left, d);
	else
		current->right = _nodeRemoveBST(current->right, d);
	return current;
}

/******************************************************************************
** main
******************************************************************************/
int main(int argc, char const *argv[])
{
	struct BinarySearchTree * testBST = malloc(sizeof(struct BinarySearchTree));
	initBST(testBST);

	// random seed based on time.
	// comment out to get constant set.
	//time_t t;
	//srand((unsigned) time(&t));

	for (int i = 0; i<20; i++)
	{
		int randN = rand() % 100;
		printf("add: %d\n", randN);
		addBST(testBST, randN);
		//printf("contains %d: %d\n", randN, containsBST(testBST, randN));
	}


	for (int i = 0; i<100; i++)
	{
		if (containsBST(testBST, i))
			printf("contains %d\n", i);
	}

	// All test values based on the default random seed
	int testVal = 95; // Max
	printf("contains the max %d: %d\n",
		testVal, containsBST(testBST, testVal));
	removeBST(testBST, testVal);
	printf("contains %d after remove: %d\n",
		testVal, containsBST(testBST, testVal));

	testVal = 41; // Root
	printf("contains the root %d: %d\n",
		testVal, containsBST(testBST, testVal));
	removeBST(testBST, testVal);
	printf("contains %d after remove: %d\n", testVal,
		containsBST(testBST, testVal));

	testVal = 0; // Min
	printf("contains the min %d: %d\n",
		testVal, containsBST(testBST, testVal));
	removeBST(testBST, testVal);
	printf("contains %d after remove: %d\n",
		testVal, containsBST(testBST, testVal));

	// Remove random values that may or may not be in tree
	for (int i = 0; i<20; i++)
	{
		int randN = rand() % 100;
		printf("contains %d: %d\n",
			randN, containsBST(testBST, randN));
		printf("remove: %d\n", randN);
		removeBST(testBST, randN);
		printf("contains %d after remove: %d\n",
			randN, containsBST(testBST, randN));
	}

	for (int i = 0; i<100; i++)
	{
		if (containsBST(testBST, i))
			printf("contains %d\n", i);
	}
}
