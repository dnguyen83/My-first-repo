#ifndef TEST_BED_H
#define TEST_BED_H
#include <string.h>
//#include <Windows.h>

using namespace std;
namespace TestBed {

	class Person;
	class Command {
	public:
		Command(Person* obj = 0, void(Person:: *method)() = 0) : m_person(obj), m_method(method) {}
		void execute() {(m_person->*m_method)();}
	private:
		Person* m_person;
		void(Person:: *m_method)();
	};
}

#endif // TEST_BED_H