#ifndef STATE_H
#define STATE_H

#include "headers.h"
/*
Intent
Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.
An object-oriented state machine
wrapper + polymorphic wrappee + collaboration

Problem
A monolithic object's behavior is a function of its state, and it must change its behavior at run-time depending on that state. Or, an application is characterixed by large and numerous case statements that vector flow of control based on the state of the application.

Discussion
The State pattern is a solution to the problem of how to make behavior depend on state.

Define a "context" class to present a single interface to the outside world.
Define a State abstract base class.
Represent the different "states" of the state machine as derived classes of the State base class.
Define state-specific behavior in the appropriate State derived classes.
Maintain a pointer to the current "state" in the "context" class.
To change the state of the state machine, change the current "state" pointer.
The State pattern does not specify where the state transitions will be defined. The choices are two: the "context" object, or each individual State derived class. The advantage of the latter option is ease of adding new State derived classes. The disadvantage is each State derived class has knowledge of (coupling to) its siblings, which introduces dependencies between subclasses.

A table-driven approach to designing finite state machines does a good job of specifying state transitions, but it is difficult to add actions to accompany the state transitions. The pattern-based approach uses code (instead of data structures) to specify state transitions, but it does a good job of accomodating state transition actions.

Structure
The state machine's interface is encapsulated in the "wrapper" class. The wrappee hierarchy's interface mirrors the wrapper's interface with the exception of one additional parameter. The extra parameter allows wrappee derived classes to call back to the wrapper class as necessary. Complexity that would otherwise drag down the wrapper class is neatly compartmented and encapsulated in a polymorphic hierarchy to which the wrapper object delegates.

Example
The State pattern allows an object to change its behavior when its internal state changes. This pattern can be observed in a vending machine. Vending machines have states based on the inventory, amount of currency deposited, the ability to make change, the item selected, etc. When currency is deposited and a selection is made, a vending machine will either deliver a product and no change, deliver a product and change, deliver no product due to insufficient currency on deposit, or deliver no product due to inventory depletion.

Rules of thumb
State objects are often Singletons.
Flyweight explains when and how State objects can be shared.
Interpreter can use State to define parsing contexts.
Strategy has 2 different implementations, the first is similar to State. The difference is in binding times (Strategy is a bind-once pattern, whereas State is more dynamic).
The structure of State and Bridge are identical (except that Bridge admits hierarchies of envelope classes, whereas State allows only one). The two patterns use the same structure to solve different problems: State allows an object's behavior to change along with its state, while Bridge's intent is to decouple an abstraction from its implementation so that the two can vary independently.
The implementation of the State pattern builds on the Strategy pattern. The difference between State and Strategy is in the intent. With Strategy, the choice of algorithm is fairly stable. With State, a change in the state of the "context" object causes it to select from its "palette" of Strategy objects.
*/

class State;
class Machine {
public:
	Machine();
	void setCurrent(State* s);

	void on();
	void off();
private:
	class State* m_state;
};

class State {
public:
	virtual void on(Machine* m);
	virtual void off(Machine* m);
private:
};

class OFF : public State{
public:
	void on(Machine* m);
};

class ON : public State{
public:
	void off(Machine* m);
};

#endif //end of STATE_H