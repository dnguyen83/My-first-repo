#ifndef COMPOSITE_H
#define COMPOSITE_H

/*
Intent
Compose objects into tree structures to represent whole-part hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.
Recursive composition
"Directories contain entries, each of which could be a directory."
1-to-many "has a" up the "is a" hierarchy

Problem
Application needs to manipulate a hierarchical collection of "primitive" and "composite" objects. Processing of a primitive object is handled one way, and processing of a composite object is handled differently. Having to query the "type" of each object before attempting to process it is not desirable.

Discussion
Define an abstract base class (Component) that specifies the behavior that needs to be exercised uniformly across all primitive and composite objects. Subclass the Primitive and Composite classes off of the Component class. Each Composite object "couples" itself only to the abstract type Component as it manages its "children".

Use this pattern whenever you have "composites that contain components, each of which could be a composite".

Child management methods [e.g. addChild(), removeChild()] should normally be defined in the Composite class. Unfortunately, the desire to treat Primitives and Composites uniformly requires that these methods be moved to the abstract Component class. See the "Opinions" section below for a discussion of "safety" versus "transparency" issues.

http://sourcemaking.com/design_patterns/composite

Composite design pattern
Identify the scalar/primitive classes and vector/container classes
Create an "interface" (lowest common denominator) that can make all concrete classes "interchangeable"
All concrete classes declare an "is a" relationship to the interface
All "container" classes couple themselves to the interface (recursive composition, Composite "has a" set of children up the "is a" hierarchy)
"Container" classes use polymorphism as they delegate to their children
*/

#include "headers.h"
using namespace std;
class Component {
public:
	virtual void traverse() = 0;
};

class Leaf: public Component {
// 1. scalar class 3. "isa" relationship
public :
	Leaf(int val) {
		m_value = val;
	}

	void traverse() {
		//printf("%d ",);
	}
private:
	int m_value;
};

class Composite: public Component {
public:
	void add(Component *ele) {
		children.push_back(ele);
	}

	void traverse() {
		for (int i = 0; i < children.size();) {
			children[i]->traverse();
		}
	}
private:
	vector<Component*> children;
};




/////////////////////////////////////////////



#endif