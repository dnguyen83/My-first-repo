#ifndef OBSERVER_H
#define OBSERVER_H
#include "headers.h"

class Observer;
class Subject {
public:
	void attach(Observer* listener);
	void unattach(Observer* listener);
	void notify(const char* stuff);
private:
	std::vector <class Observer*> m_listeners;
};

class Observer {
public:
	Observer(const char* name) : m_name(name) {}
	void setSubject(Subject* subj);
	virtual void update(const char* words)=0;
protected:
	Subject* m_subject;
	std::string m_name;
};

class Student : public Observer {
public:
	Student(const char* name) : Observer(name)
	{}

	void update(const char* words) {printf("%s heard you saying: %s", m_name.c_str(), words);}
};

#endif //OBSERVER_H