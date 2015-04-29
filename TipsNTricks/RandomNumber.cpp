#include "RandomNumber.h"

void printRandMax()
{
	TIPS_TRACE("%d\n", RAND_MAX);
}

void randGen()
{
	int v1 = rand() % 100;         // v1 in the range 0 to 99
	TIPS_TRACE("%d", v1);
	int v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
	TIPS_TRACE("%d", v2);
	int v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 
	TIPS_TRACE("%d", v3);
}

void rangGenSeed()
{
	//If seed is set to 1, the generator is reinitialized to its initial value and produces the same values as before any call to rand or srand.

	TIPS_TRACE ("First number: %d\n", rand()%100);
	srand(time(NULL));
	TIPS_TRACE ("Random number: %d\n", rand()%100);
	srand (1);
	TIPS_TRACE ("Again the first number: %d\n", rand()%100);
}