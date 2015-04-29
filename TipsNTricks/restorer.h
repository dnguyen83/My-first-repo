#pragma once

template < class T >
class temp_value {
public:
	temp_value(T& var) : _var(var), _original(var) {}
	~temp_value()        { _var = _original; }
private:
	T&  _var;
	T   _original;
	temp_value(const temp_value&);
	temp_value& operator=(const temp_value&);
};