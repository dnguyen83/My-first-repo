#include "Preprocessor.h"

void runPreprocessor()
{
	TIPS_TRACE("Prints a message with prefix");

	TIPS_FTRACE("Prints a message with file and line number");

	char string[] = "Test String";
	TIPS_STRACE(string);
}