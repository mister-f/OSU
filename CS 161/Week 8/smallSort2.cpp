/**************************************
 * Name: Andrew Funk
 * Date: 8-4-17
 * Description: This set of functions takes the memory addresses 
 * 				of three integer variables and sorts the integers
 * 				stored at the addresses in ascending order. 
 *************************************/

/************************************
 * Description: This function takes two integers by reference and
 * 				swaps their values.
 ***********************************/

void swapPlaces(int &slotA, int &slotB)
{
	// tempSlot variable is used so data is not overwritten
	int tempSlot = slotA;
	slotA = slotB;
	slotB = tempSlot;
} 

/***********************************
 * Description: This function takes three pointers to integers. It
 * 				then loops twice, sequentially comparing each value 
 * 				at the indicated memory addresses. If the values 
 * 				are out of order it calls a function to swap their 
 * 				places.
 **********************************/

void smallSort2(int *numA, int *numB, int *numC)
{
	// Loop through the values twice, comparing each value sequentially
	// Two passes are needed to ensure sorting is complete
	for (int i = 1; i <= 2; i++)
		{
			// If a number is higher than the following number, the
			// contents at the memory addresses pointed to are swapped.
			if (*numA > *numB)
			{
				swapPlaces(*numA, *numB);
			}
			if (*numB > *numC)
			{
				swapPlaces(*numB, *numC);
			}
		}
}

