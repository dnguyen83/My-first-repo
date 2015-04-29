#ifndef COMMAND_H
#define COMMAND_H
#include "headers.h"
/*
Intent
Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.
Promote "invocation of a method on an object" to full object status
An object-oriented callback

Problem
Need to issue requests to objects without knowing anything about the operation being requested or the receiver of the request.

Discussion
Command decouples the object that invokes the operation from the one that knows how to perform it. To achieve this separation, the designer creates an abstract base class that maps a receiver (an object) with an action (a pointer to a member function). The base class contains an execute() method that simply calls the action on the receiver.

All clients of Command objects treat each object as a "black box" by simply invoking the object's virtual execute() method whenever the client requires the object's "service".

A Command class holds some subset of the following: an object, a method to be applied to the object, and the arguments to be passed when the method is applied. The Command's "execute" method then causes the pieces to come together.

Sequences of Command objects can be assembled into composite (or macro) commands.

Structure
The client that creates a command is not the same client that executes it. This separation provides flexibility in the timing and sequencing of commands. Materializing commands as objects means they can be passed, staged, shared, loaded in a table, and otherwise instrumented or manipulated like any other object.

Command objects can be thought of as "tokens" that are created by one client that knows what need to be done, and passed to another client that has the resources for doing it.

Example
The Command pattern allows requests to be encapsulated as objects, thereby allowing clients to be parameterized with different requests. The "check" at a diner is an example of a Command pattern. The waiter or waitress takes an order or command from a customer and encapsulates that order by writing it on the check. The order is then queued for a short order cook. Note that the pad of "checks" used by each waiter is not dependent on the menu, and therefore they can support commands to cook many different items.

Rules of thumb
Chain of Responsibility, Command, Mediator, and Observer, address how you can decouple senders and receivers, but with different trade-offs. Command normally specifies a sender-receiver connection with a subclass.
Chain of Responsibility can use Command to represent requests as objects.
Command and Memento act as magic tokens to be passed around and invoked at a later time. In Command, the token represents a request; in Memento, it represents the internal state of an object at a particular time. Polymorphism is important to Command, but not to Memento because its interface is so narrow that a memento can only be passed as a value.
Command can use Memento to maintain the state required for an undo operation.
MacroCommands can be implemented with Composite.
A Command that must be copied before being placed on a history list acts as a Prototype.
Two important aspects of the Command pattern: interface separation (the invoker is isolated from the receiver), time separation (stores a ready-to-go processing request that's to be stated later).

*/
using namespace std;
class Person;

class Command
{
public:
	Command(Person *obj = 0, void(Person:: *meth)() = 0)
	{
		m_object = obj; // the argument's name is "meth"
		m_method = meth;
	}
	void execute();
private:
	// 1. Create a class that encapsulates an object and a member function
	// a pointer to a member function (the attribute's name is "method")
	Person *m_object; //    
	void(Person::*m_method)();
};

class Person
{
public:
	Person(string n, Command c): cmd(c)
	{
		name = n;
	}
	void talk()
	{
		// "this" is the sender, cmd has the receiver
		printf("%s is talking", name.c_str());
		cmd.execute(); // ask the "black box" to callback the receiver
	}
	void passOn()
	{
		printf("%s is passing on", name.c_str());

		// 4. When the sender is ready to callback to the receiver,
		// it calls execute()
		cmd.execute(); 
	}
	void gossip()
	{
		printf("%s is gossiping", name.c_str());
		cmd.execute();
	}
	void listen()
	{
		printf("%s is listening", name.c_str());
	}
private:
	string name;

	// cmd is a "black box", it is a method invocation
	// promoted to "full object status"
	Command cmd; 
};
#endif // end of COMMAND_H