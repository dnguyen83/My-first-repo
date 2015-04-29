#include "pointers.h"

NODE* g_head = NULL; // in real code this would be pointing to the head of the memory

void insert(NODE* new_node)
{
	// optimal of going through a linked list using pointers, noice
	NODE** link = &g_head;
	while((*link)->next != NULL)
	{
		link = &(*link)->next;
	}

	new_node->next = *link;
	*link = new_node;
}

void sizeOfArray()
{
	int array[10] = {0};

	// instead of doing
	int size = sizeof(array) / sizeof(array[0]);

	// do, this is basically end of array minus beginning of array
	size = *(&array + 1) - array;
}

void arrayLooping()
{
	// this is good because it prevents array overflow
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	for(int* p = array; p < (&array)[1]; ++p)
	{
		printf("%d\n", *p);
	}
}

// extra notes on pointers

/* 

The container_of macro
The Linux kernel source includes this useful macro that’s invaluable for writing object-oriented code in C. I’ve simplified its definition to remove GCC-specific extensions:

#define container_of(ptr, type, member) \
(type *)((char *)(ptr) - offsetof(type, member))


It’s used as follows (example taken from linux/Documentation/kobject.txt). Imagine you have a structure containing another structure:

struct uio_map {
struct kobject kobj;
struct uio_mem *mem;
};

Then, given a struct kobject that you know is a member of a struct uio_map, you might be tempted to get the outer struct uio_map just by casting the pointer:

struct kobject *kp = …;
struct uio_map *u_map = (struct uio_map *)kp;


But that leads to fragile code that would be broken by the addition of another member to the beginning of struct uio_map. Instead, write:

struct uio_map *u_map = container_of(kp, struct uio_map, kobj);

*/