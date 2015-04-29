#ifndef CHAING_OF_RESPONSIBILITY_H
#define CHAING_OF_RESPONSIBILITY_H
#include "headers.h"

/*
Intent
Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.
Launch-and-leave requests with a single processing pipeline that contains many possible handlers.
An object-oriented linked list with recursive traversal.

Problem
There is a potentially variable number of "handler" or "processing element" or "node" objects, and a stream of requests that must be handled. Need to efficiently process the requests without hard-wiring handler relationships and precedence, or request-to-handler mappings.

Discussion
Encapsulate the processing elements inside a "pipeline" abstraction; and have clients "launch and leave" their requests at the entrance to the pipeline.

The pattern chains the receiving objects together, and then passes any request messages from object to object until it reaches an object capable of handling the message. The number and type of handler objects isn't known a priori, they can be configured dynamically. The chaining mechanism uses recursive composition to allow an unlimited number of handlers to be linked.

Chain of Responsibility simplifies object interconnections. Instead of senders and receivers maintaining references to all candidate receivers, each sender keeps a single reference to the head of the chain, and each receiver keeps a single reference to its immediate successor in the chain.

Make sure there exists a "safety net" to "catch" any requests which go unhandled.

Do not use Chain of Responsibility when each request is only handled by one handler, or, when the client object knows which service object should handle the request.

Example
The Chain of Responsibility pattern avoids coupling the sender of a request to the receiver by giving more than one object a chance to handle the request. ATM use the Chain of Responsibility in money giving mechanism.

Rules of thumb
Chain of Responsibility, Command, Mediator, and Observer, address how you can decouple senders and receivers, but with different trade-offs. Chain of Responsibility passes a sender request along a chain of potential receivers.
Chain of Responsibility can use Command to represent requests as objects.
Chain of Responsibility is often applied in conjunction with Composite. There, a component's parent can act as its successor.

*/

class Base {
public:
	Base();
	void setNext(Base* n);
	void add(Base* n);
	virtual void handle(int i);
protected:
	Base* m_next;
};

class H1 : public Base {
public:
	void handle(int i);
};

class H2 : public Base {
public:
	void handle(int i);
};

#endif // end of CHAING_OF_RESPONSIBILITY_H