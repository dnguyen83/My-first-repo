#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>

/*
Intent
Given a language, define a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.
Map a domain to a language, the language to a grammar, and the grammar to a hierarchical object-oriented design.

Problem
A class of problems occurs repeatedly in a well-defined and well-understood domain. If the domain were characterized with a "language", then problems could be easily solved with an interpretation "engine".

Discussion
The Interpreter pattern discusses: defining a domain language (i.e. problem characterization) as a simple language grammar, representing domain rules as language sentences, and interpreting these sentences to solve the problem. The pattern uses a class to represent each grammar rule. And since grammars are usually hierarchical in structure, an inheritance hierarchy of rule classes maps nicely.

An abstract base class specifies the method interpret(). Each concrete subclass implements interpret() by accepting (as an argument) the current state of the language stream, and adding its contribution to the problem solving process.

Example
The Intepreter pattern defines a grammatical representation for a language and an interpreter to interpret the grammar. Musicians are examples of Interpreters. The pitch of a sound and its duration can be represented in musical notation on a staff. This notation provides the language of music. Musicians playing the music from the score are able to reproduce the original pitch and duration of each sound represented.
*/

class Interpreter {
public:
	Interpreter(); //ctor for client
	Interpreter(int i){}; //ctor for subclasses, to prevent infinite loop

	int interpret(char*); // interpret() for client
	virtual void interpret(char *input, int &total) // interpert( for subclasses)
	{
		// for internal use
		int index;
		index = 0;
		if (!strncmp(input, nine(), 2))
		{
			total += 9 * multiplier();
			index += 2;
		}
		else if (!strncmp(input, four(), 2))
		{
			total += 4 * multiplier();
			index += 2;
		}
		else
		{
			if (input[0] == five())
			{
				total += 5 * multiplier();
				index = 1;
			}
			else
				index = 0;
			for (int end = index + 3; index < end; index++)
				if (input[index] == one())
					total += 1 * multiplier();
				else
					break;
		}
		strcpy(input, &(input[index]));
	} // remove leading chars processed

protected:
	virtual char one(){return 'a';};
	virtual char* four(){return 0x000000;};
	virtual char five(){return 'a';};
	virtual char* nine(){return 0x000000;};
	virtual int multiplier(){return 0;};
private:
	Interpreter *thousands;
	Interpreter *hundreds;
	Interpreter *tens;
	Interpreter *ones;
};

class Thousand : public Interpreter {
public:
	Thousand(int) : Interpreter(1){}
protected:
	/*virtual*/ char one() {
		return 'M';
	}

	/*virtual*/ char* four(){
		return "";
	}
	/*virtual*/ char five(){
		return '\0';
	}

	/*virtual*/ char* nine(){
		return "";
	}

	/*virtual*/ int multiplier(){
		return 1000;
	}

private:
};

class Hundred : public Interpreter {
public:
	Hundred(int) : Interpreter(1){}
protected:
	/*virtual*/ char one() {
		return 'C';
	}

	/*virtual*/ char* four(){
		return "CD";
	}
	/*virtual*/ char five(){
		return 'D';
	}

	/*virtual*/ char* nine(){
		return "CM";
	}

	/*virtual*/ int multiplier(){
		return 100;
	}

private:
};

class Ten : public Interpreter {
public:
	Ten(int) : Interpreter(1){}
protected:
	/*virtual*/ char one() {
		return 'X';
	}

	/*virtual*/ char* four(){
		return "XL";
	}
	/*virtual*/ char five(){
		return 'L';
	}

	/*virtual*/ char* nine(){
		return "XC";
	}

	/*virtual*/ int multiplier(){
		return 10;
	}

private:
};

class One : public Interpreter {
public:
	One(int) : Interpreter(1){}
protected:
	/*virtual*/ char one() {
		return 'I';
	}

	/*virtual*/ char* four(){
		return "IV";
	}
	/*virtual*/ char five(){
		return 'V';
	}

	/*virtual*/ char* nine(){
		return "IX";
	}

	/*virtual*/ int multiplier(){
		return 1;
	}

private:
};

#endif //INTERPRETER_H