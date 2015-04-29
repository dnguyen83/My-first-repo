#ifndef ABSTRACT_FACTORY
#define ABSTRACT_FACTORY

/*
Provide an interface for creating families of related or dependent objects without specifying their concrete classes.
A hierarchy that encapsulates: many possible "platforms", and the construction of a suite of "products".
The new operator considered harmful.

If an application is to be portable, it needs to encapsulate platform dependencies. These "platforms" might include: windowing system, operating system, database, etc. Too often, this encapsulatation is not engineered in advance, and lots of #ifdef case statements with options for all currently supported platforms begin to procreate like rabbits throughout the code.

Clients never create platform objects directly, they ask the factory to do that for them.

This mechanism makes exchanging product families easy because the specific class of the factory object appears only once in the application - where it is instantiated. The application can wholesale replace the entire family of products simply by instantiating a different concrete instance of the abstract factory.

Example
The purpose of the Abstract Factory is to provide an interface for creating families of related objects, without specifying concrete classes. This pattern is found in the sheet metal stamping equipment used in the manufacture of Japanese automobiles. The stamping equipment is an Abstract Factory which creates auto body parts. The same machinery is used to stamp right hand doors, left hand doors, right front fenders, left front fenders, hoods, etc. for different models of cars. Through the use of rollers to change the stamping dies, the concrete classes produced by the machinery can be changed within three minutes.
*/

class House;
class Factory {
public:
	virtual ~Factory() {}

	virtual House* createWindow()=0;
	virtual House* createTires()=0;
	virtual House* createRoof()=0;
};

class MaisonetteFactory : public Factory {
public:
	~MaisonetteFactory(){}

	House* createWindow();
	House* createTires();
	House* createRoof();
};

class FlatFactory : public Factory {
public:
	~FlatFactory(){}

	House* createWindow();
	House* createTires();
	House* createRoof();
};

class House {
public:
	virtual ~House(){}

	virtual void whatAmI()=0;
};

class RoofMaisonette : public House{
public:
	virtual ~RoofMaisonette(){}

	void whatAmI();
};

class WindowMaisonette : public House{
public:
	virtual ~WindowMaisonette(){}

	void whatAmI();
};

class TiresMaisonette : public House{
public:
	virtual ~TiresMaisonette(){}

	virtual void whatAmI();
};

class RoofFlat : public House{
public:
	virtual ~RoofFlat(){}

	void whatAmI();
};

class WindowFlat : public House{
public:
	virtual ~WindowFlat(){}

	void whatAmI();
};

class TiresFlat : public House{
public:
	virtual ~TiresFlat(){}

	virtual void whatAmI();
};

#endif //ABSTRACT_FACTORY