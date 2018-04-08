/*
 * This is the file in which you'll write the functions required to 
 * implement a stack using two queues.  Make sure to add your name 
 * and @oregonstate.edu email address below:
 */

 /*********************************************************************
 ** Program Filename: stack_from_queue.c
 ** Author: Andrew Funk 
 ** Email: funkand@oregonstate.edu
 ** Date: 02-04-18
 ** Description: This program creates a stack data structure, but the
				 underlying mechanics of the structure are created by 
				 using two queue data structures. The end user doesn't 
				 have to deal with queues at all and can simply use 
				 normal stack functions such as pop, top, push, etc.
 ** Input: This program asks for no user input
 ** Output: This program has output that is currently commented out. The
 **			commented out section was used for testing purposes.
 *********************************************************************/


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* All by yourself */ 
#ifndef TYPE
#define TYPE int
#endif

/* Struct definitions for links, queues, and stacks */
struct link
{
	TYPE value;
	struct link *next;
};

struct queue
{
	struct link *firstLink;
	struct link *lastLink;
};

struct stack
{
	struct queue *q1;
	struct queue *q2;
};

/* Function prototypes for queue functions */
void _queueInit(struct queue *q);
struct queue * _queueCreate();
void _queueAddBack(struct queue *q, TYPE value);
TYPE _queueFront(struct queue *q);
void _queueRemoveFront(struct queue *q);
int _queueIsEmpty(struct queue *q);
void _queueDelete(struct queue *q);

/* Function prototypes for stack functions*/
struct stack * stackCreate();
void stackInit(struct stack *s);
void stackFree(struct stack *s);
void push(struct stack *s, TYPE value);
TYPE top(struct stack *s);
void pop(struct stack *s);
int isEmpty(struct stack *s);

int main() 
{
	struct stack *s = stackCreate();
	
	/* Commented out, used for testing*/
	/*
	push(s, (TYPE)1);
	push(s, (TYPE)2);
	push(s, (TYPE)12);
	push(s, (TYPE)72);
	push(s, (TYPE)13);
	push(s, (TYPE)-8);
	
	printf("%i\n", top(s));
	pop(s);
	printf("%i\n", top(s));
	pop(s);
	printf("%i\n", top(s));
	pop(s);
	printf("%i\n", top(s));
	push(s, (TYPE)99);
	printf("%i\n", top(s));
	pop(s);
	pop(s);
	pop(s);
	printf("%i\n", top(s));
	pop(s);
	push(s, (TYPE)72);
	push(s, (TYPE)13);
	push(s, (TYPE)-8);
	*/

	stackFree(s);
	return 0;
}

/*********************************************************************
** Function: _queueInit
** Description: This function initializes a queue by dynamically 
				allocating a sentinel for it
** Parameters: q, a pointer to a queue structure
** Pre-Conditions: none
** Post-Conditions: q is an empty queue with one sentinel link
*********************************************************************/

void _queueInit(struct queue *q)
{
	/*Allocate memory for sentinel*/
	struct link *lnk = (struct link*) malloc(sizeof(struct link));
	assert(lnk != 0);

	lnk->next = 0;
	q->firstLink = q->lastLink = lnk;
}

/*********************************************************************
** Function: _queueCreate
** Description: This function dynamically allocates a queue and then
				initializes it to have a sentinel.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns an empty queue structure
*********************************************************************/

struct queue * _queueCreate()
{
	struct queue *newQueue = (struct queue*)malloc(sizeof(struct queue));
	assert(newQueue != 0);
	
	_queueInit(newQueue);
	return newQueue;
}

/*********************************************************************
** Function: _queueAddBack
** Description: This functions takes a value and adds it to the end of
				the queue.
** Parameters: q, a pointer to a queue structure
**			   value, the value to be added
** Pre-Conditions: none
** Post-Conditions: a new link holding value is added to the back of the
					queue
*********************************************************************/

void _queueAddBack(struct queue *q, TYPE value)
{
	struct link *newLink = (struct link*) malloc(sizeof(struct link));
	assert(newLink != 0);

	newLink->value = value;
	newLink->next = 0;

	q->lastLink->next = newLink;
	q->lastLink = newLink;
}

/*********************************************************************
** Function: _queueFront
** Description: This function returns the value at the front of the
				queue.
** Parameters: q, a pointer to a queue structure
** Pre-Conditions: queue must not be empty
** Post-Conditions: value at the front element is returned
*********************************************************************/

TYPE _queueFront(struct queue *q)
{
	assert(!_queueIsEmpty(q));
	return q->firstLink->next->value;
}

/*********************************************************************
** Function: _queueRemoveFront
** Description: This function removes the element at the front of the 
				queue and frees any associated memory.
** Parameters: q, a pointer to a queue structure
** Pre-Conditions: queue must not be empty
** Post-Conditions: front element in the queue is removed, allocated 
					memory is freed
*********************************************************************/

void _queueRemoveFront(struct queue *q)
{
	assert(!_queueIsEmpty(q));
	
	struct link *temp = q->firstLink->next;

	/* Check if there is only one value remaining*/
	if (q->firstLink->next == q->lastLink)
	{
		q->lastLink = q->firstLink;
		q->firstLink->next = 0;
	}
	else
	{
		q->firstLink->next = q->firstLink->next->next;
	}

	free(temp);
}

/*********************************************************************
** Function: _queueIsEmpty
** Description: This function checks whether a queue is empty.
** Parameters: q, a pointer to a queue structure
** Pre-Conditions: none
** Post-Conditions: 1 returned for empty, 0 returned otherwise
*********************************************************************/

int _queueIsEmpty(struct queue *q)
{
	return q->firstLink == q->lastLink;
}

/*********************************************************************
** Function: _queueDelete
** Description: This function deletes a queue and any dynamically
				allocated memory associated with it. This includes any
				remaining links, the sentinel, and the queue structure.
** Parameters: q, a pointer to a queue structure
** Pre-Conditions: none
** Post-Conditions: all memory allocated to queue is freed
*********************************************************************/

void _queueDelete(struct queue *q)
{
	while (!_queueIsEmpty(q))
	{
		_queueRemoveFront(q);
	}
	free(q->firstLink);
	free(q);
}

/*********************************************************************
** Function: stackCreate
** Description: This function dynamically allocates a new stack and 
				initializes it.
** Parameters: q, a pointer to a queue structure
** Pre-Conditions: none
** Post-Conditions: a new empty stack is created
*********************************************************************/

struct stack * stackCreate()
{
	struct stack *newStack = (struct stack*)malloc(sizeof(struct stack));
	assert(newStack != 0);

	stackInit(newStack);

	return newStack;
}

/*********************************************************************
** Function: stackInit
** Description: This function initialzes a stack with two empty queues.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: stack is initialized with two empty queues
*********************************************************************/

void stackInit(struct stack *s)
{
	s->q1 = _queueCreate();
	s->q2 = _queueCreate();
}

/*********************************************************************
** Function: stackFree
** Description: This function deletes the stack and any allocated memory
				associated with it. That includes any remaining values
				and the underlying queue structures.
** Parameters: s, a pointer to a stack structure
** Pre-Conditions: none
** Post-Conditions: all memory allocated to stack is freed
*********************************************************************/

void stackFree(struct stack *s)
{
	while (!isEmpty(s))
	{
		pop(s);
	}

	_queueDelete(s->q1);
	_queueDelete(s->q2);
	free(s);
}

/*********************************************************************
** Function: push
** Description: This function pushes a value to the top of the stack.
** Parameters: s, a pointer to a stack structure
			   value, the value to be added
** Pre-Conditions: none
** Post-Conditions: value is added to the top of the stack
*********************************************************************/

void push(struct stack *s, TYPE value)
{
	/* Add the value to the front of q2 */
	_queueAddBack(s->q2, value);

	/* Remove the value from the front of q1 and add it to the back
	** of q2*/
	while (!_queueIsEmpty(s->q1))
	{
		_queueAddBack(s->q2, _queueFront(s->q1));
		_queueRemoveFront(s->q1);
	}

	/* Swap q2 with q1, q1 will hold the values*/
	struct queue *temp = s->q2;
	s->q2 = s->q1;
	s->q1 = temp;
}

/*********************************************************************
** Function: top
** Description: This function returns the value at the top of the stack.
** Parameters: s, a pointer to a stack structure
** Pre-Conditions: stack must not be empty
** Post-Conditions: value of top element is returned
*********************************************************************/

TYPE top(struct stack *s)
{
	assert(!isEmpty(s));
	return _queueFront(s->q1);
}

/*********************************************************************
** Function: pop
** Description: This function removes the value at the top of the stack.
** Parameters: s, a pointer to a stack structure
** Pre-Conditions: stack must not be empty
** Post-Conditions: top element of stack is removed
*********************************************************************/

void pop(struct stack *s)
{
	assert(!isEmpty(s));
	_queueRemoveFront(s->q1);
}

/*********************************************************************
** Function: isEmpty
** Description: This value checks whether the stack is empty.
** Parameters: s, a pointer to a stack structure
** Pre-Conditions: none
** Post-Conditions: 1 returned for empty, 0 returned otherwise
*********************************************************************/

int isEmpty(struct stack *s)
{
	return _queueIsEmpty(s->q1);
}