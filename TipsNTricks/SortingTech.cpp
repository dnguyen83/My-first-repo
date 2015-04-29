#include "SortingTech.h"

void bubbleSort()
{
	const unsigned int n = 100;
	int array[n];

	//fill the array with random number first
	for(int i = 0; i < n; ++i)
	{
		array[i] =  rand() % 100;
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}


	TIPS_TRACE("Do Bubble sort");
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<n-1; y++)
		{
			if(array[y]>array[y+1])
			{
				int temp = array[y+1];
				array[y+1] = array[y];
				array[y] = temp;
			}
		}
	}

	TIPS_TRACE("After bubbl sort");
	for(int i = 0; i < n; ++i)
	{
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}
}

void modifiedBubbleSort()
{
	const unsigned int n = 100;
	int array[n];

	//fill the array with random number first
	for(int i = 0; i < n; ++i)
	{
		array[i] =  rand() % 100;
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}


	TIPS_TRACE("Do Modified Bubble sort");
	bool sorted;
	for(int x=0; x<n; x++)
	{
		sorted = true;
		for(int y=0; y<n-1; y++)
		{
			if(array[y]>array[y+1])
			{
				int temp = array[y+1];
				array[y+1] = array[y];
				array[y] = temp;
				sorted = false;
			}
		}

		// if sorted then quit
		if(sorted)
		{
			TIPS_TRACE("Number of iterations: %d", x);
			break;
		}
	}

	TIPS_TRACE("After bubbl sort");
	for(int i = 0; i < n; ++i)
	{
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}
}

void selectionSort()
{
	const unsigned int n = 100;
	int array[n];

	//fill the array with random number first
	for(int i = 0; i < n; ++i)
	{
		array[i] =  rand() % 100;
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}


	TIPS_TRACE("Do selection sort");

	for(int x=0; x<n; x++)
	{
		int index_of_min = x;
		for(int y=x; y<n; y++)
		{
			if(array[index_of_min]>array[y])
			{
				index_of_min = y;
			}
		}

		int temp = array[x];
		array[x] = array[index_of_min];
		array[index_of_min] = temp;
	}

	TIPS_TRACE("After selection sort");
	for(int i = 0; i < n; ++i)
	{
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}
}

void insertionSort()
{
	const unsigned int n = 100;
	int array[n];

	//fill the array with random number first
	for(int i = 0; i < n; ++i)
	{
		array[i] =  rand() % 100;
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}

	int i, j ,tmp;
	for (i = 1; i < n; i++) 
	{  
		j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			tmp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = tmp;
			j--;
		}//end of while loop
	}//end of for loop

	TIPS_TRACE("After selection sort");
	for(int i = 0; i < n; ++i)
	{
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}
}


void heapSort()
{

}

/*------------Merge Sort-----------------*/

//Merge sort works using the principle that if you have two sorted lists, you can merge them together to form another sorted list. Consequently, sorting a large list can be thought of as a problem of sorting two smaller lists and then merging those two lists together. For instance, if you have the list

/* Helper function for finding the max of two numbers */
int max(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

/* left is the index of the leftmost element of the subarray; right is one
 * past the index of the rightmost element */
void merge_helper(int *input, int left, int right, int *scratch)
{
    /* base case: one element */
    if(right == left + 1)
    {
        return;
    }
    else
    {
        int i = 0;
        int length = right - left;
        int midpoint_distance = length/2;
        /* l and r are to the positions in the left and right subarrays */
        int l = left, r = left + midpoint_distance;

        /* sort each subarray */
        merge_helper(input, left, left + midpoint_distance, scratch);
        merge_helper(input, left + midpoint_distance, right, scratch);

        /* merge the arrays together using scratch for temporary storage */ 
        for(i = 0; i < length; i++)
        {
            /* Check to see if any elements remain in the left array; if so,
             * we check if there are any elements left in the right array; if
             * so, we compare them.  Otherwise, we know that the merge must
             * use take the element from the left array */
            if(l < left + midpoint_distance && 
                    (r == right || max(input[l], input[r]) == input[l]))
            {
                scratch[i] = input[l];
                l++;
            }
            else
            {
                scratch[i] = input[r];
                r++;
            }
        }
        /* Copy the sorted subarray back to the input */
        for(i = left; i < right; i++)
        {
            input[i] = scratch[i - left];
        }
    }
}

/* mergesort returns true on success.  Note that in C++, you could also
 * replace malloc with new and if memory allocation fails, an exception will
 * be thrown.  If we don't allocate a scratch array here, what happens? 
 *
 * Elements are sorted in reverse order -- greatest to least */

void mergeSort()
{
	const unsigned int n = 100;
	int array[n];

	//fill the array with random number first
	for(int i = 0; i < n; ++i)
	{
		array[i] =  rand() % 100;
		TIPS_TRACE("array[%d]: %d", i, array[i]);
	}

	int *scratch = (int *)malloc(n * sizeof(int));
	if(scratch != NULL)
	{
		merge_helper(array, 0, n, scratch);
		free(scratch);
	}
}

/*------------End Of Merge Sort-----------*/

void quickSort()
{

}