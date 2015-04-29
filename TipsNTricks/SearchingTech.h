#ifndef _SEARCHING_TECH_H_
#define _SEARCHING_TECH_H_
#include "headers.h"

//Searching for data is one of the fundamental fields of computing. Often, the difference between a fast program and a slow one is the use of a good algorithm for the data set. This article will focus on searching for data stored in a linear data structure such as an array or linked list. Naturally, the use of a hash table or binary search tree will result in more efficient searching, but more often than not an array or linked list will be used. It is necessary to understand good ways of searching data structures not designed to support efficient search. 

void linearSearch();


//For lists that do not have a set order requirement, a self organizing algorithm may be more efficient if some items in the list are searched for more frequently than others. By bubbling a found item toward the front of the list, future searches for that item will be executed more quickly. This speed improvement takes advantage of the fact that 80% of all operations are performed on 20% of the items in a data set. If those items are nearer to the front of the list then search will be sped up considerably.
//
//The first solution that comes to mind is to move the found item to the front. With an array this would result in rather expensive memory shifting
void selfOrganisingSearch();


//All of the sequential search algorithms have the same problem; they walk over the entire list. Some of our improvements work to minimize the cost of traversing the whole data set, but those improvements only cover up what is really a problem with the algorithm. By thinking of the data in a different way, we can make speed improvements that are much better than anything sequential search can guarantee.
//
//Consider a list in ascending sorted order. It would work to search from the beginning until an item is found or the end is reached, but it makes more sense to remove as much of the working data set as possible so that the item is found more quickly. If we started at the middle of the list we could determine which half the item is in (because the list is sorted). This effectively divides the working range in half with a single test. By repeating the procedure, the result is a highly efficient search algorithm called binary search.
//
//The actual algorithm is surprisingly tricky to implement considering the apparent simplicity of the concept. Here is a correct function that implements binary search by marking the current lower and upper bounds for the working range
void binarySearch();

//Binary search is very efficient, but it can be improved by writing a variation that searches more like humans do. Consider how you would search for a name in the phonebook. I know of nobody who would start in the middle if they are searching for a name that begins with B. They would begin at the most likely location and then use that location as a gauge for the next most likely location. Such a search is called interpolation search because it estimates the position of the item being searched for based on the upper and lower bounds of the range. The algorithm itself isn't terribly difficult, but it does seem that way with the range calculation:void interpolationSearch();
void interpolationSearch();
#endif // endof _SEARCHING_TECH_H_