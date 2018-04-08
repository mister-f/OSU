#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	list->sentinel = (struct Link*)malloc(sizeof(struct Link));
	assert(list->sentinel != 0);

	//Set pointers
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;

	list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
	assert(newLink != 0);

	newLink->next = NULL;
	newLink->prev = NULL;
	newLink->value = value; 

	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	struct Link* newLink = createLink(value);

	// Assign a temporary pointer to next link
	struct Link* nextLink = link->next;

	// Set pointers to new link
	link->next->prev = newLink;
	link->next = newLink;

	// Set pointers from new link
	newLink->next = nextLink;
	newLink->prev = link;

	// Increment list size
	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	list->size--;

	struct Link* before = link->prev;
	struct Link* after = link->next;

	// Set pointers of links surrounding target link to each other
	after->prev = link->prev;
	before->next = link->next;

	free(link);
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link* temp;

	// Remove links until list is empty
	while (!circularListIsEmpty(list))
	{
		temp = list->sentinel->next;
		removeLink(list, temp);
	}
	free(list->sentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!circularListIsEmpty(list));
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!circularListIsEmpty(list));
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!circularListIsEmpty(list));
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!circularListIsEmpty(list));
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	return list->size == 0;;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!circularListIsEmpty(list));
	
	struct Link* temp = list->sentinel->next;

	// Loop until sentinel is reached, printing value of each link
	while (temp != list->sentinel)
	{
		printf("%g ", temp->value);
		temp = temp->next;
	}

	printf("\n");
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	assert(!circularListIsEmpty(list));
	
	struct Link* current = list->sentinel;
	struct Link* temp;
	int i;

	// Loop through list plus one to account for sentinel
	for (i = 0; i < list->size + 1; i++)
	{
		// Use temporary link pointer to reverse prev and next at each
		// link, then move to next
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = current->next;
	}
}
