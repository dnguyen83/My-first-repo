#include "Preprocessor.h"
#include "headers.h"
#include "TestBed.h"
#include "TaskGenerator.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include "Memento.h"
#include <cstdarg>
#include "constexpr.h"
#include "misc.h"
#include <memory>
#include <set>
#include <tuple>
#include <algorithm>
#include <utility>
#include <tuple>
#include "roulette.h"
#include "make_unique.h"
#define MAX_NUMBER 10

using namespace TestBed;



int main()
{
	std::unique_ptr<int> integer = Dat::make_unique<int>(10);

	Roulette roulette;
	Data task;
	task.get(roulette.spin(task.size()));
	
	printf("Hello World\n");

	return 0;
}
