#pragma once
#include "String.h"
#include <iostream>
class Log
{
	size_t id;
	String action;
public:
	Log();
	Log(size_t, String);
	~Log() = default;
	friend std::ostream& operator<<(std::ostream&, const Log&);
};

