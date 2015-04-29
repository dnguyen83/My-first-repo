#ifndef _C_PLUS_PLUS_ELEVEN
#define _C_PLUS_PLUS_ELEVEN

#include "headers.h"

//constexpr int get_five() {return 5;}
//void constExpr();

// make unique implementation since c++11 doesn't have it
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args&& ...args)
{
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

void staticAssert() {
	static_assert(3 > 4, "Error description here, this will error at compile time");
}

#endif //end of _C_PLUS_PLUS_ELEVEN