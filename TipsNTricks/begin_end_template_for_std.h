#pragma once

template< typename T, std::size_t sz >
inline T* begin(T(&array)[sz]) { return array; }

template< typename T, std::size_t sz >
inline T* end(T(&array)[sz]) { return array + sz; }