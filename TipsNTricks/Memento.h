#ifndef MEMENTO_H
#define MEMENTO_H

#include "headers.h"

/*
Intent
Without violating encapsulation, capture and externalize an object's internal state so that the object can be returned to this state later.
A magic cookie that encapsulates a "check point" capability.
Promote undo or rollback to full object status.

Problem
Need to restore an object back to its previous state (e.g. "undo" or "rollback" operations).

Discussion
The client requests a Memento from the source object when it needs to checkpoint the source object's state. The source object initializes the Memento with a characterization of its state. The client is the "care-taker" of the Memento, but only the source object can store and retrieve information from the Memento (the Memento is "opaque" to the client and all other objects). If the client subsequently needs to "rollback" the source object's state, it hands the Memento back to the source object for reinstatement.

An unlimited "undo" and "redo" capability can be readily implemented with a stack of Command objects and a stack of Memento objects.

The Memento design pattern defines three distinct roles:

Originator - the object that knows how to save itself.
Caretaker - the object that knows why and when the Originator needs to save and restore itself.
Memento - the lock box that is written and read by the Originator, and shepherded by the Caretaker.

Example
The Memento captures and externalizes an object's internal state so that the object can later be restored to that state. This pattern is common among do-it-yourself mechanics repairing drum brakes on their cars. The drums are removed from both sides, exposing both the right and left brakes. Only one side is disassembled and the other serves as a Memento of how the brake parts fit together. Only after the job has been completed on one side is the other side disassembled. When the second side is disassembled, the first side acts as the Memento.

Rules of thumb
Command and Memento act as magic tokens to be passed around and invoked at a later time. In Command, the token represents a request; in Memento, it represents the internal state of an object at a particular time. Polymorphism is important to Command, but not to Memento because its interface is so narrow that a memento can only be passed as a value.
Command can use Memento to maintain the state required for an undo operation.
Memento is often used in conjunction with Iterator. An Iterator can use a Memento to capture the state of an iteration. The Iterator stores the Memento internally.

Memento design pattern
Discussion. A memento is an object that stores a snapshot of the internal state of another object. It can be leveraged to support multi-level undo of the Command pattern. In this example, before a command is run against the Number object, Number's current state is saved in Command's static memento history list, and the command itself is saved in the static command history list. Undo() simply "pops" the memento history list and reinstates Number's state from the memento. Redo() "pops" the command history list. Note that Number's encapsulation is preserved, and Memento is wide open to Number.
*/

class Memento {
public:
	Memento(int val) : m_state(val)
	{}

private:
	friend class Number;
	int m_state;
};

class Number {
public:
	Number(int num) : m_num(num)
	{};

	void dubble();
	void half();
	int getValue();
	Memento *createMemento();
	void reinstateMemento(Memento *memento);
private:
	int m_num;
};

class Command {
public:
	typedef void(Number::*Action)();
	Command(Number* receiver, Action action) : m_receiver(receiver),
												m_action(action)
	{}

	virtual void execute();

	static void undo();

	static void redo();
protected:
	Number* m_receiver;
	Action m_action;

	static Command* s_commandList[20];
	static Memento* s_mementoList[20];
	static int m_numCommands;
	static int m_highWater;
};

#endif // endof MEMENTO_H