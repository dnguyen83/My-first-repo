#ifndef STRATEGY_H
#define STRATEGY_H
#include <string>

// this is a good link of using strategy to change the way a list 
// is sorted
// http://anandpandia.blogspot.co.uk/2012/07/strategy-design-pattern.html

using namespace std;
class Strategy01;
class StringType {
public:
	StringType() : m_strategy(0){}
	~StringType();
	enum Type {
		APPEND = 1,
		CUT
	};
	void doIt(string words, int type);
private:
	Strategy01* m_strategy;
};

// first method of strategy using inheritance
// this basically allows the client to define which strategy to use
class Strategy01 {
public:
	void format(string words);
private:
	virtual void strategy(string words) = 0; //this can be defined by inherited classes to change the way it works
	string m_words;
};

class append : public Strategy01 {
private:
	/*virtual*/ void strategy(string words);
};

class cut : public Strategy01 {
private:
	/*virtual*/ void strategy(string words);
};







////////////////////////////////////////
// This is another method of doing it, by passing in a function pointer instead of inheritance
class Strategy02 {
public:
	Strategy02(void (*method)(string word)) : m_method(method) {}
	void doIt(string words);
private:
	void (*m_method)(string word);
};
#endif //STRATEGY_H