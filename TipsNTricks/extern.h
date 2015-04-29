/*
extern tells the compiler that this data is defined somewhere and will be connected with the linker.

	With the help of the responses here and talking to a few friends here is the practical example of a use of extern.

	Example 1 - to show a pitfall:

File stdio.h:

int errno;
/* other stuff...
myCFlie1.c:
#include <stdio.h>

Code...
	myCfile2.c:
#include <stdio.h>

Code...
	If myCFile1.o and myCFile2.o are linked, each of the c files have separate copies of errno. This is a problem as errno is suppose to be constant over over all linked files.

	Example 2 - The fix.

	File stdio.h:

extern int errno;
/* other stuff...
File stdio.c

	int errno;
myCFlie1.c:
#include <stdio.h>

Code...
	myCFile2.c:
#include <stdio.h>

Code...
	Now if both myCFile1.o and MyCFile2.o are linked by the linker they will both point to the same errno. Thus, solving the implementation with extern.

*/