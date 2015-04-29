#ifndef PERFECT_FORWARDING_H
#define PERFECT_FORWARDING_H

#include <iostream>
#include <memory>
#include <utility>
#include <array>

//struct A {
//	A(int&& n) { std::cout << "rvalue overload, n=" << n << "\n"; }
//	A(int& n)  { std::cout << "lvalue overload, n=" << n << "\n"; }
//};
//
//class B {
//public:
//	template<class T1, class T2, class T3>
//	B(T1&& t1, T2&& t2, T3&& t3) :
//		a1_{ std::forward<T1>(t1) },
//		a2_{ std::forward<T2>(t2) },
//		a3_{ std::forward<T3>(t3) }
//	{
//	}
//
//private:
//	A a1_, a2_, a3_;
//};
//
//template<class T, class U>
//std::unique_ptr<T> make_unique1(U&& u)
//{
//	return std::unique_ptr<T>(new T(std::forward<U>(u)));
//}
//
//template<class T, class... U>
//std::unique_ptr<T> make_unique(U&&... u)
//{
//	return std::unique_ptr<T>(new T(std::forward<U>(u)...));
//}
//
//int main()
//{
//	auto p1 = make_unique1<A>(2); // rvalue
//	int i = 1;
//	auto p2 = make_unique1<A>(i); // lvalue
//
//	std::cout << "B\n";
//	auto t = make_unique<B>(2, i, 3);
//}




//The simplest is to use an lvalue - reference:
//
//template <typename A, typename B, typename C>
//void f(A& a, B& b, C& c)
//{
//	E(a, b, c);
//}
//But this fails to handle temporary values : f(1, 2, 3); , as those cannot be bound to an lvalue - reference.
//
//The next attempt might be :
//
//template <typename A, typename B, typename C>
//void f(const A& a, const B& b, const C& c)
//{
//	E(a, b, c);
//}
//Which fixes the above problem, but flips flops.It now fails to allow E to have non - const arguments :
//
//int i = 1, j = 2, k = 3;
//void E(int&, int&, int&); f(i, j, k); // oops! E cannot modify these
//The third attempt accepts const - references, but then const_cast's the const away:
//
//template <typename A, typename B, typename C>
//void f(const A& a, const B& b, const C& c)
//{
//	E(const_cast<A&>(a), const_cast<B&>(b), const_cast<C&>(c));
//}
//This accepts all values, can pass on all values, but potentially leads to undefined behavior :
//
//const int i = 1, j = 2, k = 3;
//E(int&, int&, int&); f(i, j, k); // ouch! E can modify a const object!
//A final solution handles everything correctly...at the cost of being impossible to maintain.You provide overloads of f, with all combinations of const and non - const:
//
//template <typename A, typename B, typename C>
//void f(A& a, B& b, C& c);
//
//template <typename A, typename B, typename C>
//void f(const A& a, B& b, C& c);
//
//template <typename A, typename B, typename C>
//void f(A& a, const B& b, C& c);
//
//template <typename A, typename B, typename C>
//void f(A& a, B& b, const C& c);
//
//template <typename A, typename B, typename C>
//void f(const A& a, const B& b, C& c);
//
//template <typename A, typename B, typename C>
//void f(const A& a, B& b, const C& c);
//
//template <typename A, typename B, typename C>
//void f(A& a, const B& b, const C& c);
//
//template <typename A, typename B, typename C>
//void f(const A& a, const B& b, const C& c);
//N arguments require 2N combinations, a nightmare.We'd like to do this automatically.
//
//(This is effectively what we get the compiler to do for us in C++11.)
//
//In C++11, we get a chance to fix this.One solution modifies template deduction rules on existing types, but this potentially breaks a great deal of code.So we have to find another way.
//
//The solution is to instead use the newly added rvalue - references; we can introduce new rules when deducing rvalue - reference types and create any desired result.After all, we cannot possibly break code now.
//
//If given a reference to a reference(note reference is an encompassing term meaning both T& and T&&), we use the following rule to figure out the resulting type :
//
//"[given] a type TR that is a reference to a type T, an attempt to create the type �lvalue reference to cv TR� creates the type �lvalue reference to T�, while an attempt to create the type �rvalue reference to cv TR� creates the type TR."
//
//Or in tabular form :
//
//TR   R
//
//T&   &->T&  // lvalue reference to cv TR -> lvalue reference to T
//T&   &&->T&  // rvalue reference to cv TR -> TR (lvalue reference to T)
//T&&  &->T&  // lvalue reference to cv TR -> lvalue reference to T
//T&&  &&->T&& // rvalue reference to cv TR -> TR (rvalue reference to T)
//Next, with template argument deduction : if an argument is an lvalue A, we supply the template argument with an lvalue reference to A.Otherwise, we deduce normally.This gives so - called universal references.
//
//Why is this useful ? Because combined we maintain the ability to keep track of the value category of a type : if it was an lvalue, we have an lvalue - reference parameter, otherwise we have an rvalue - reference parameter.
//
//In code :
//
//template <typename T>
//void deduce(T&& x);
//
//int i;
//deduce(i); // deduce<int&>(int& &&) -> deduce<int&>(int&)
//deduce(1); // deduce<int>(int&&)
//The last thing is to "forward" the value category of the variable.Keep in mind, once inside the function the parameter could be passed as an lvalue to anything :
//
//void foo(int&);
//
//template <typename T>
//void deduce(T&& x)
//{
//	foo(x); // fine, foo can refer to x
//}
//
//deduce(1); // okay, foo operates on x which has a value of 1
//That's no good. E needs to get the same kind of value-category that we got! The solution is this:
//
//static_cast<T&&>(x);
//What does this do ? Consider we're inside the deduce function, and we've been passed an lvalue.This means T is a A&, and so the target type for the static cast is A& &&, or just A&.Since x is already an A&, we do nothing and are left with an lvalue reference.
//
//When we've been passed an rvalue, T is A, so the target type for the static cast is A&&. The cast results in an rvalue expression, which can no longer be passed to an lvalue reference. We've maintained the value category of the parameter.
//
//Putting these together gives us "perfect forwarding" :
//
//template <typename A>
//void f(A&& a)
//{
//	E(static_cast<A&&>(a));
//}
//When f receives an lvalue, E gets an lvalue.When f receives an rvalue, E gets an rvalue.Perfect.
//
//And of course, we want to get rid of the ugly. static_cast<T&&> is cryptic and weird to remember; let's instead make a utility function called forward, which does the same thing:
//
//std::forward<A>(a);
//// is the same as
//static_cast<A&&>(a);
#endif