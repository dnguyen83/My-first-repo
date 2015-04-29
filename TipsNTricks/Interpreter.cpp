#include "Interpreter.h"

#include "Interpreter.h"

Interpreter::Interpreter() {
	thousands = new Thousand(1);
	hundreds = new Hundred(1);
	tens = new Ten(1);
	ones = new One(1);
}

int Interpreter::interpret(char *input) {
	int total;
	total = 0;
	thousands->interpret(input, total);
	hundreds->interpret(input, total);
	tens->interpret(input, total);
	ones->interpret(input, total);
	if(strcmp(input, "")) {
		return 0;
	}

	return total;
}