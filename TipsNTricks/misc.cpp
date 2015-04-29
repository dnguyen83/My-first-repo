#include "misc.h"
#include <iostream>
using namespace std;


void doSomething()
{
	TIPS_TRACE("doing something");
}

int getValueFromSomewhere(){return 10;}

void commaSeparated()
{
	/*The comma operator isn't widely used. It can certainly be abused, but it can also be very useful. This use is the most common one:*/

	for(int i = 0; i < 10; ++i, doSomething())
	{
		TIPS_TRACE("%d: ", i);
	}

	//But you can use this operator anywhere. Observe:

	int j = (printf("Assigning variable j\n"), getValueFromSomewhere());
	TIPS_TRACE("J is: %d", j);
	
	//Each statement is evaluated, but the value of the expression will be that of the last statement evaluated.
}

void multiCharacterConstant()
{
	//This sets x to 0x41424344 (or 0x44434241, depending on architecture).
	int x = 'ACCD';

	//This makes it much simpler if you're looking at a raw memory dump and need to determine the value of an enum without having to look it up.
	enum state {
		stopped = 'STOP',
		running = 'RUN!',
		waiting = 'WAIT',
	};

	//This feature is as portable as it needs to be. Multi-char constant is an extremely useful feature that provides readable way to for generating unique integer IDs
}

void bitFields()
{
	typedef struct cat {
		unsigned int legs:3;  // 3 bits for legs (0-4 fit in 3 bits)
		unsigned int lives:4; // 4 bits for lives (0-9 fit in 4 bits)
		// ...
	}cat;

	cat kitty;
	kitty.legs = 4;
	kitty.lives = 9;

	//This means that sizeof(cat) can be as small as sizeof(char).
}

void printf01()
{
	// this feature allows you to use variables for formatting format specifiers themselves. look for the code, you will see better

	int a = 3;
	float b = 6.412355;
	printf("%.*f\n",a,b);

	// so decimal point of a which is 3. Cool
}

void compileTimeAssert()
{
	//--- size of static_assertion array is negative if condition is not met
#define STATIC_ASSERT(condition) \
	typedef struct { \
	char static_assertion[condition ? 1 : -1]; \
} static_assertion_t

	//--- ensure structure fits in 
	STATIC_ASSERT(1 > 0);

	// below code will not compile because of compile time assertion
	// STATIC_ASSERT(1 < 0);
}

void constantStringConcatenation()
{
#define PATH "/some/path/"

	char test[] = PATH "something\0";
	TIPS_TRACE("%s", test);

	// notice the lack of '+'
}