#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

#include <iostream>
#include <string>

using namespace std;


template <class T> double scalar_difference(T x, T y)
{
	return abs(x.getScalarValue() - y.getScalarValue());
}

template <class T> bool equals(T x, T y)
{
	return (x == y);
}


#endif
