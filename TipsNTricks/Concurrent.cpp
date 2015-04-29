#include <queue>
#include <thread>
#include <vector>
#include <future>
#include <string>
#include <iostream>
#include <memory>

// from: http://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2012-Herb-Sutter-Concurrency-and-Parallelism

// to enable void calls and non void clals
template<typename Fut, typename F, typename T>
void set_value(std::promise<Fut>& p, F& f, T& t) {
	p.set_value(f(t));
}

template<typename F, typename T>
void set_value(std::promise<void>& p, F& f, T& t) {
	f(t);
	p.set_value();
}

template<class T>
class Concurrent {
public:

	Concurrent(T t_ = T{})
	: t{t_}
	{}

	~Concurrent() {
		m_queue.push([=]{
			done = true;
		});

		thd.join();
	}

//	template<typename F>
//	auto operator()(F func)const->std::future<decltype(func(t))>{
//		auto p = std::make_shared<std::promise<decltype(func(t))>>();
//		auto ret = p->get_future();
//		m_queue.push([=]{
//			set_value(*p, func, t);
//		});
//
//		return ret;
//	}

private:
	mutable T t;
	mutable std::queue<std::function<void()>> m_queue;
	bool done = false;
	std::thread thd;
};

//Example to call it
//
//int how() {
//	Concurrent<std::string> s = "start\n";
//
//	auto f = s([](std::string& s){
//		s += std::to_string(42) + " " + std::to_string(43);
//		return std::string("**** set: ") + s;
//	});
//
//	std::cout << f.get() << std::endl;
//	return 0;
//}