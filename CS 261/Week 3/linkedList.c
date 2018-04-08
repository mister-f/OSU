#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	// Allocate new links
	struct Link* front = (struct Link*)malloc(sizeof(struct Link));
	assert(front != 0);
	struct Link* back = (struct Link*)malloc(sizeof(struct Link));
	assert(back != 0);

	//Set new link pointers
	front->next = back;
	back->prev = front;

	// Assign the Sentinels the new link addresses
	list->frontSentinel = front;
	list->backSentinel = back;

	list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	// Allocate a new link
	struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
	assert(newLink != 0);

	// Assign a temporary pointer to previous link
	struct Link* prevLink = link->prev;

	// Set pointers to new link
	link->prev->next = newLink;
	link->prev = newLink;

	// Set pointers from new link
	newLink->next = link;
	newLink->prev = prevLink;

	// Assign new link a vlue and increment list size
	newLink->value = value;
	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
	list->size--;
	
	// Set pointers of links surrounding target link to each other
	link->prev->next = link->next;
	link->next->prev = link->prev;
	
	free(link);
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
	return list->size == 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));
	struct Link* temp = list->frontSentinel->next;

	// Loop until back sentinel is reached, printing value of each link
	while (temp != list->backSentinel)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	} 

	printf("\n");
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));

	struct Link* current = list->frontSentinel->next;

	// Loop until next pointer is null
	while (current->next)
	{
		// If value matches target, return true
		if (current->value == value)
		{
			return 1;
		}
		current = current->next;
	}
	// Return false with no match
	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(!linkedListIsEmpty(list));

	struct Link* current = list->frontSentinel->next;

	// Loop until back sentinel is reached
	while (current != list->backSentinel)
	{
		// If value matches target, remove the link and break out of loop
		if (current->value == value)
		{
			removeLink(list, current);
			break;
		}
		current = current->next;
	}
}
