#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <vector>
#include <sstream>

// does a string contain another string
inline bool contains(const std::string &s1, const std::string &s2) {
	return s1.find(s2) != std::string::npos;
}

// remove trailing whitespace
inline std::string &rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

// remove leading whitespace
inline std::string &ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// remove whitespace from both ends
inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}

// split a string based on a delimeter and return the result (you pass an existing vector for the results)
// vector holds all the separated strings based on number of separators in original string
inline std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

// same as above, but returns a vector for you
inline std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	return split(s, delim, elems);
}

// does a string end with another string
inline bool endswith(const std::string &s, const std::string &ending) {
	return ending.length() <= s.length() && s.substr(s.length() - ending.length()) == ending;
}

// does a string begin with another string  
inline bool beginswith(const std::string &s, const std::string &start) {
	return s.compare(0, start.length(), start) == 0;
}
