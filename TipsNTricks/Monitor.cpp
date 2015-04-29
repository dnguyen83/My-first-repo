#include <iostream>

class CriticalS {
public:
	CriticalS() {
		std::cout << "Locking\n";
	}

	~CriticalS() {
		std::cout << "Unlocking\n";
	}
};

template<class F>
struct FunctionType;

template<class R, class Obj, class... Args>
struct FunctionType<R(Obj::*)(Args...)> {
	typedef R ReturnType;
};

template<class O>
class Monitor {
public:
	template<class F, class... Args>
	typename FunctionType<F>::ReturnType execute(const F& f, Args... args) {
		CriticalS cs;
		return (m_object.*f)(args...);
	}
private:
	O m_object;
};

class Producer {
public:

	void increment() {
		std::cout << "incrementing\n";
		++m_value;
	}
	void decrement() {
		std::cout << "decrementing\n";
		--m_value;
	}

	int get() {
		std::cout << "getting\n";
		return m_value;
	}

	void add(int value) {
		std::cout << "adding\n";
		m_value += value;
	}

	void print() { std::cout << "value is: " << m_value << std::endl; }

private:
	int m_value = 0;
};

//int main() {
//	Monitor<Producer> producer;
//	producer.execute(&Producer::increment);
//	producer.execute(&Producer::print);
//	return 0;
//}


/////////////////// Herbs version using C++11
// from: http://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2012-Herb-Sutter-Concurrency-and-Parallelism

template <class T>
class Monitor2 {
public:
	Monitor2(T t = T{})
		: m_object{ t }
	{}

	template<typename F>
	auto operator()(F f) -> decltype(f(m_object)) {
		CriticalS cs;
		return f(m_object);
	}
private:
	T m_object;
};

//class Producer {
//public:
//
//	void increment() {
//		std::cout << "incrementing\n";
//		++m_value;
//	}
//	void decrement() {
//		std::cout << "decrementing\n";
//		--m_value;
//	}
//
//	int get() {
//		std::cout << "getting\n";
//		return m_value;
//	}
//
//	void add(int value) {
//		std::cout << "adding\n";
//		m_value += value;
//	}
//
//	void print() { std::cout << "value is: " << m_value << std::endl; }
//
//private:
//	int m_value = 0;
//};
//
//int main() {
//	Monitor<Producer> prod;
//	prod([](Producer& producer) {
//		producer.add(10);
//		producer.increment();
//		producer.decrement();
//	});
//
//	return 0;
//}