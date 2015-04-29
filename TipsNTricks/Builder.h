#ifndef BUILDER_H
#define BUILDER_H
#include "headers.h"
#include <string>

/*
--Description--
- Separate the construction of a complex object from its representation
so that the same construction process can create different representations.

Problem: An application needs to create the elements of a complex aggregate. The specification for the aggregate exists on secondary storage and one of many representations needs to be built in primary storage

The "builder" creates part of the complex object each time it is called and maintains all intermediate state. When the product is finished, the client retrieves the result from the "builder".

Affords finer control over the construction process. Unlike creational patterns that construct products in one shot, the Builder pattern constructs the product step by step under the control of the "director".

Example
The Builder pattern separates the construction of a complex object from its representation so that the same construction process can create different representations. This pattern is used by fast food restaurants to construct children's meals. Children's meals typically consist of a main item, a side item, a drink, and a toy (e.g., a hamburger, fries, Coke, and toy dinosaur). Note that there can be variation in the content of the children's meal, but the construction process is the same. Whether a customer orders a hamburger, cheeseburger, or chicken, the process is the same. The employee at the counter directs the crew to assemble a main item, side item, and toy. These items are then placed in a bag. The drink is placed in a cup and remains outside of the bag. This same process is used at competing restaurants.
*/

class Profile {
public:
	void setLanguage(const char* language);
	char* getLanguage();

	void setCountry(const char* country);
	char* getCountry();

	void setName(const char* name);
	char* getName();

	void printProfile();
private:
	std::string m_platform;
	std::string m_name;
	std::string m_language;
	std::string m_country;
};

class Builder {
public:
	Builder();
	virtual void setLanguage(char* language)=0;
	virtual void setCountry(char* country)=0;
	virtual void setName(char* name)=0;
	Profile* getProfile(){return m_profile;}
protected:
	Profile* m_profile;
};

class PS4Profile : public Builder {
public:
	void setLanguage(char* language);
	void setCountry(char* country);
	void setName(char* name);
private:
};

class PSVitaProfile : public Builder {
public:
	PSVitaProfile();
	void setLanguage(char* language);
	void setCountry(char* country);
	void setName(char* name);
private:
};

#endif // BUILDER_H