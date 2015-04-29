#include "SearchingTech.h"

// linear search

typedef struct node {
    int rec;
    int key;
    node *next;
    
    node ( int r, int k, node *n )
    : rec ( r )
    , key ( k )
    , next ( n )
    {}
}node;

void linearSearch()
{
    // Basic sequential search
    const int size = 100;
    int array[size];
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }
    
    bool found = false;
    int key  = 11;
    int i;
    
    for ( i = 0; i < size; i++ ) {
        if ( key == array[i] )
            break;
    }
    if ( i < size ) {
        found = true;
        // found
        TIPS_TRACE("Found");
    } else {
        TIPS_TRACE("Not found");
        // not found
    }
    

    // linear search linked list
    node* list = (node*)malloc(sizeof(node));
    node* walker = list;
    for(int i = 0;;)
    {
        walker->key = rand() % 100;
        if((++i) < size)
        {
            walker->next = (node*)malloc(sizeof(node));
            walker = walker->next;
        } else {
            walker->next = NULL;
            break;
        }
    }
    
    for ( walker = list; walker != 0; walker = walker->next ) {
        if ( key == walker->key )
            break;
    }
    if ( i != 0 ) {
        found = true;
        TIPS_TRACE("Found");
    } else {
        TIPS_TRACE("Not Found");
    }
}

// end of linear search


// Self organising search
void selfOrganisingSearch()
{
    // Array
    const int size = 100;
    int array[size];
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }
    
    // Self-organizing (move to front) search
    bool found = false;
    int key = 11;
    // Is it already at the front?
    if ( key == array[0] ) {
        found = true;
    }
    else {
        int i;
        for ( i = 1; i < size; i++ ) {
            if ( key == array[i] )
                break;
        }
        if ( i < size ) {
            int save = array[i];
            // Fill the hole left by list[i]
            for ( int j = i; j < size - 1; j++ )
                array[j] = array[j + 1];
            // Make room at the front
            for ( int j = size - 1; j > 0; j-- )
                array[j] = array[j - 1];
            array[0] = save;
            found = true;
        }
    }
    
    
    // linked list
    // Self-organizing (move to front) search
    node* list = (node*)malloc(sizeof(node));
    node* walker = list;
    for(int i = 0;;)
    {
        walker->key = rand() % 100;
        if((++i) < size)
        {
            walker->next = (node*)malloc(sizeof(node));
            walker = walker->next;
        } else {
            walker->next = NULL;
            break;
        }
    }
    
    node *iter = list;
    found = false;
    
    // Is it already at the front?
    if ( key == iter->key ) {
        found = true;
    }
    else {
        for ( ; iter->next != 0; iter = iter->next ) {
            if ( key == iter->next->key )
                break;
        }
        // Was the item found?
        if ( iter->next != 0 ) {
            // Remove the node and fix the list
            node *save = iter->next;
            iter->next = save->next;
            // Place the node at the front
            save->next = list;
            list = save;
            found = true;
        }
    }
    
    // Array again
    // Self-organizing (swap with previous) search
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }
    
    key = 99;
    found = false;
    int i;
    
    for ( i = 0; i < size; i++ ) {
        if ( key == array[i] )
            break;
    }
    // Was it found?
    if ( i < size ) {
        // Is it already the first?
        if ( i > 0 ) {
            int save = array[i - 1];
            array[i - 1] = array[i];
            array[i--] = save;
        }
        found = true;
    }
}

// end of self organising search


// Binary Search
void binarySearch()
{
	// bsearch() is c standard function, you can just use this instead of writing your own
	//bsearch();
    
	// Array
    const int size = 100;
    int array[size];
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }
    
    // Binary search
    int key = 55;
    bool found = false;
    int low = 0, high = size - 1;
    
    while ( high >= low ) {
        int mid = ( low + high ) / 2;
        if ( key < array[mid] )
            high = mid - 1;
        else if ( key > array[mid] )
            low = mid + 1;
        else {
            found = true;
            break;
        }
    }
}
// end of binary search

// Interpolation Search
void interpolationSearch()
{
    const int size = 100;
    int array[size];
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }
    
    // Interpolation search
    int key = 20;
    bool found = false;
    int low = 0, high = size - 1;
    
    while ( array[high] >= key && key > array[low] ) {
        double low_diff = (double)key - array[low];
        double range_diff = (double)array[high] - array[low];
        double count_diff = (double)high - low;
        int range = (int)( low_diff / range_diff * count_diff + low );
        if ( key > array[range] )
            low = range + 1;
        else if ( key < array[range] )
            high = range - 1;
        else
            low = range;
    }
    if ( key == array[low] ) {
        found = true;
    }
}
