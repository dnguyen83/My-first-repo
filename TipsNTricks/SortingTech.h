#ifndef _SORTING_TECH_H_
#define _SORTING_TECH_H_
#include "headers.h"

	//Sort						Average		Best		Worst		Space		Stability	Remarks
	//Bubble sort				O(n^2)		O(n^2)		O(n^2)		Constant	Stable		Always use a modified bubble sort
	//Modified Bubble sort		O(n^2)		O(n)		O(n^2)		Constant	Stable		Stops after reaching a sorted array
	//Selection Sort			O(n^2)		O(n^2)		O(n^2)		Constant	Stable		Even a perfectly sorted input requires scanning the entire array
	//Insertion Sort			O(n^2)		O(n)		O(n^2)		Constant	Stable		In the best case (already sorted), every insert requires constant time
	//Heap Sort					O(n*log(n))	O(n*log(n))	O(n*log(n))	Constant	Instable	By using input array as storage for the heap, it is possible to achieve constant space
	//Merge Sort				O(n*log(n))	O(n*log(n))	O(n*log(n))	Depends		Stable		On arrays, merge sort requires O(n) space; on linked lists, merge sort requires constantspace
	//Quicksort					O(n*log(n))	O(n*log(n))	O(n^2)		Constant	Stable		Randomly picking a pivot value (or shuffling the array prior to sorting) can help avoid worst case scenarios such as a perfectly sorted array.


void bubbleSort();

void modifiedBubbleSort();

void selectionSort();

void insertionSort();

void heapSort();

void mergeSort();

void quickSort();

#endif // endof _SORTING_TECH_H_