#pragma once
#include <string>

template<typename T>
std::string make_string(const T& data) {
	std::ostringstream stream;
	stream << data;
	return stream.str();
}