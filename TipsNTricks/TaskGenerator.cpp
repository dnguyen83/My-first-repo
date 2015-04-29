//#include "TaskGenerator.h"
//#include <stdio.h>
//#include <time.h>
//
//void TaskGenerator::printTask() {
//	srand(time(NULL));
//	size_t size = TASK_MAX_NUM;
//	int taskSize = rand() % (size-1);
//	std::string description;
//
//	switch(taskSize) {
//	case RANDOM_NUMBER:
//		description = "Random number\n\n";
//		description += "1. random number with various range options\n\n";
//		break;
//	case ABSTRACT_FACTORY:
//		description = "Abstract Factory Pattern\n\n";
//		break;
//	case BINARY_TREE:
//		description = "Binary tree\n";
//		break;
//	case BUILDER:
//		description = "Builder pattern\n";
//		break;
//	case FACTORY_METHOD:
//		description = "Factory Method pattern\n";
//		break;
//	case OBJECT_POOL:
//		description = "Object Pool pattern\n";
//		break;
//	case PROTOTYPE:
//		description = "Prototype pattern\n";
//		break;
//	case SINGLETON:
//		description = "Singleton patten\n";
//		description += "Do various techniques of singleton, inside an object, as an object itself etc.\n";
//		break;
//	case ADAPTER:
//		description = "Adapter pettern\n";
//		break;
//	case BRIDGE:
//		description = "Bridge pattern\n";
//		break;
//	case COMPOSITE:
//		description = "Composite pattern\n";
//		break;
//	case DECORATOR:
//		description = "Decorator pattern\n";
//		break;
//	case FACADE:
//		description = "Facade pattern\n";
//		break;
//	case FLY_WEIGHT:
//		description = "Fly weight pattern\n";
//		break;
//	case PRIVATE_CLASS_DATA:
//		description = "Private Class Data Pattern\n";
//		break;
//	case PROXY:
//		description = "Proxy pattern\n";
//		break;
//	case CHAIN_OF_RESPONSIBILITY:
//		description = "Chain of Responsibility pattern\n";
//		break;
//	case COMMAND:
//		description = "Command pattern\n";
//		break;
//	case INTERPRETER:
//		description = "Interpreter pattern\n";
//		break;
//	case MEDIATOR:
//		description = "Mediator pattern\n";
//		break;
//	case MEMENTO:
//		description = "Memento pattern\n";
//		break;
//	case NULL_OBJECT:
//		description = "Null object\n";
//		break;
//	case OBSERVER:
//		description = "Observer pattern\n";
//		break;
//	case STATE:
//		description = "State pattern\n";
//		break;
//	case STRATEGY:
//		description = "Strategy pattern\n";
//		break;
//	case TEMPLATE_METHOD:
//		description = "Template Method pattern\n";
//		break;
//	case VISITOR:
//		description = "Visitor pattern\n";
//		break;
//	case BITWISE_OPERATIONS:
//		description = "Bitwise operations\n";
//		description += "1. Integer Sign\n";
//		description += "2. Opposite Sign\n";
//		description += "3. Integer Absolute Value\n";
//		description += "4. IntegerMin\n";
//		description += "5. IntegerMax\n";
//		description += "6. Is power of two\n";
//		description += "7. Sign extending constant bit width\n";
//		description += "8. Sign extending variable bit width\n";
//		description += "9. Conditionally set clear bits\n";
//		description += "10. Conditionally Negate Value\n";
//		description += "11. Merge bits\n";
//		description += "12. Counting bits\n";
//		description += "13. Counting bits lookup table\n";
//		description += "14. Select bit position given count\n";
//		description += "15. Compute parity\n";
//		description += "16. Swap values using bits\n";
//		description += "17. Reverse bits\n";
//		break;
//	case SORTING_TECHNIQUES:
//		description = "Sorting Techniques\n";
//		description += "1. Bubble Sort\n";
//		description += "2. Modified Bubble sort\n";
//		description += "3. Selection sort\n";
//		description += "4. Insertion sort\n";
//		description += "5. Heap sort\n";
//		description += "6. Merge sort\n";
//		description += "7. Quick sort\n";
//		break;
//	case THREADING:
//		description = "Threading\n";
//		description += "1. Create a thread\n";
//		description += "2. Join a thread\n";
//		description += "3. Terminate a thread\n";
//		description += "4. Event\n";
//		description += "5. Mutex\n";
//		description += "6. Semaphore\n";
//		description += "7. Waitable timer\n";
//		description += "8. Conditional variable\n";
//		description += "9. Write a producer consumer paradign\n";
//		break;
//	case STRING_MANIPULATION:
//		description = "String manipulation\n";
//		description += "1. getline()\n";
//		description += "2. go through all the std::string functions\n";
//		description += "3. go through all the c string functions\n";
//		description += "3. convert utf-8 and other convertions\n";
//		break;
//	case MESSAGE_AND_EVENT_DRIVEN_PROGRAMMING:
//		description = "Message and Event driven programming\n";
//		description += "Write one\n";
//		break;
//	case PREPROCESSOR_TECHNIQUES:
//		description = "Pre processor\n";
//		description += "1. Macros\n";
//		description += "2. Macros pasting tokens\n";
//		description += "3. String-izing tokens\n";
//		description += "4. Pattern matching https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms";
//		description += "5. Detection\n";
//		description += "6. Deferred expression\n";
//		description += "7. Comparison\n";
//		description += "8. http://www.mybitbox.com/tag/robust-code/";
//		description += "9. http://uncommoncode.wordpress.com/2010/08/04/advanced-c-preprocessor-tricks/";
//		break;
//	case SEARCH_TECHNIQUES:
//		description = "Searching techniques\n";
//		description += "1. Linear/Sequential Search\n";
//		description += "2. Self organising search\n";
//		description += "3. Binary search\n";
//		description += "4. Interpolation search\n";
//		break;
//	case TEMPLATE_PROGRAMMING:
//		description = "Template programming\n";
//		break;
//	case TIMER_AND_TIME_OPERATIONS:
//		description = "Timer and time operations\n";
//		description += "1. Get current time\n";
//		description += "2. convert to different time formats\n";
//		break;
//	case COMMAND_LINE_PROGRAM:
//		description = "Command line program\n";
//		description += "1. Write a command line program that takes command and executes a function\n";
//		break;
//	case POINTERS:
//		description = "Pointers\n";
//		description += "1. Optimal way of going through linked list using pointer to pointer\n";
//		description += "2. find size of array using pointer\n";
//		description += "3. Array looping using pointer\n";
//		description += "4. Find a container address of a struct\n";
//		description += "http://www.codeproject.com/Articles/82880/C-Pointer-Tricks";
//		break;
//	case ARTIFICIAL_INTELLIGENT:
//		description = "Artifical Intelligent\n";
//		break;
//	case FILE_OPERATIONS:
//		description = "File Operations\n";
//		break;
//	case C_PLUS_PLUS_EVELEN:
//		description = "C++11\n";
//		break;
//	case STL_PROGRAMMING:
//		description = "STL Programming\n";
//		description += "1. Vector manipulation, all the functions that it has\n";
//		description += "2. Priority Queue\n";
//		description += "3. Set, multiset\n";
//		description += "4. Map, multimap\n";
//		break;
//	case MEMORY_POOL:
//		description = "Memory Pool\n";
//		break;
//	case NETWORK_PROGRAMMING_TECHS:
//		description = "Network programming techs\n";
//		break;
//	case TASK_MAX_NUM:
//		break;
//	default:
//		break;
//	}
//
//	printf("%s", description.c_str());
//}