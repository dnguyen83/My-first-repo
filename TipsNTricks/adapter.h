#ifndef ADATPER_H
#define ADATPER_H

/*
Adapter design pattern demo
Discussion. LegacyRectangle's interface is not compatible with the system that would like to reuse it. An abstract base class is created that specifies the desired interface. An "adapter" class is defined that publicly inherits the interface of the abstract class, and privately inherits the implementation of the legacy component. This adapter class "maps" or "impedance matches" the new interface to the old implementation.

Intent
Convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.
Wrap an existing class with a new interface.
Impedance match an old component to a new system

Problem
An "off the shelf" component offers compelling functionality that you would like to reuse, but its "view of the world" is not compatible with the philosophy and architecture of the system currently being developed.

Discussion
Reuse has always been painful and elusive. One reason has been the tribulation of designing something new, while reusing something old. There is always something not quite right between the old and the new. It may be physical dimensions or misalignment. It may be timing or synchronization. It may be unfortunate assumptions or competing standards.

It is like the problem of inserting a new three-prong electrical plug in an old two-prong wall outlet – some kind of adapter or intermediary is necessary.

Adapter is about creating an intermediary abstraction that translates, or maps, the old component to the new system. Clients call methods on the Adapter object which redirects them into calls to the legacy component. This strategy can be implemented either with inheritance or with aggregation.

Adapter functions as a wrapper or modifier of an existing class. It provides a different or translated view of that class.

The Adapter could also be thought of as a "wrapper".
*/

class OldTriangle {
public:
	OldTriangle(){}
	void draw() {printf("this is old draw innit\n");}
private:
};

class NewTriangle {
	virtual void draw()=0;
};

class TriangleAdapter : public NewTriangle, private OldTriangle{
public:
	void draw() {
		printf("new draw calling old..");
		OldTriangle::draw();
	}
private:
};


#endif //ADATPER_H