/*	FIX ME sections of code added by Andrew Funk, ID# 932955748
	funkand@oregonstate.edu */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


/*  Create a task from the description and the priority

    param:  priority    priority of the task
    param:  desc    	pointer to the description string
    pre:    none
    post:   none
	ret: 	a task with description and priority
*/
TYPE createTask (int priority, char *desc) 
{
	TYPE newTask;
	newTask.priority = priority;
	strcpy(newTask.description, desc);
	return newTask;
}

/*  Save the list to a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file to which the list is saved
    pre:    The list is not empty
    post:   The list is saved to the file in tab-delimited format.
			Each line in the file stores a task, starting with the 
			task priority, followed by a tab character (\t), and 
			the task description.
			
			The tasks are not necessarily stored in the file in 
			priority order. 
	
*/
void saveList(DynArr *heap, FILE *filePtr)
{
  	/* FIX ME */
	int i;
	TYPE taskToSave;

	/* Loop through array and save each task */
	for (i = 0; i < sizeDynArr(heap); i++)
	{
		taskToSave = getDynArr(heap, i);
		fprintf(filePtr, "%d\t%s\n", taskToSave.priority, taskToSave.description);
	}
}

/*  Load the list from a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file
    pre:    none
    post:   The tasks are retrieved from the file and are added to the list.
			Refer to the saveList() function for the format of tasks in the file				
*/
void loadList(DynArr *heap, FILE *filePtr)
{
  	/* FIX ME */
	int priority;
	char description[TASK_DESC_SIZE];
	TYPE taskToAdd;

	/* Clear any currently stored heap and reinitialize*/
	freeDynArr(heap);
	initDynArr(heap, 10);

	/* Continue until EOF reached */
	while (!feof(filePtr))
	{
		/* Scan in one line of priority and description */
		fscanf(filePtr, "%d\t%[^\n]\n", &priority, description);
		/* Save priority and description into taskToAdd */
		taskToAdd = createTask(priority, description);
		/* Add task to heap */
		addHeap(heap, taskToAdd);
	}
}

/*  Print the list

    param:  heap    pointer to the list
    pre:    the list is not empty
    post:   The tasks from the list are printed out in priority order.
			The tasks are not removed from the list.
*/
void printList(DynArr *heap)
{
  	/* FIX ME  */
	assert(sizeDynArr(heap) != 0);

	DynArr tempList;
	TYPE taskToPrint;

	/* Copy list to temporary location for printing*/
	copyDynArr(heap, &tempList);

	while (sizeDynArr(&tempList) > 0)
	{
		/* get highest priority task */
		taskToPrint = getMinHeap(&tempList);
		/* print task */
		printf("%s\n", taskToPrint.description);
		/* remove task from temporary list*/
		removeMinHeap(&tempList);
	}

	freeDynArr(&tempList);
}

/*  Compare two tasks by priority

    param:  left    first task
    param:  right 	second task
    pre:    none
    post:   none
	ret: 	-1 if priority of left < priority of right
			1 if priority of left > priority of right
			0 if priority of left = priority of right
*/
int compare(TYPE left, TYPE right)
{
	if (left.priority < right.priority)
		return -1;
	else if (left.priority > right.priority)
		return 1;
	else
		return 0;
}
