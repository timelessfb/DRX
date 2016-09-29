#pragma once

#include <random>

#include "process.h"

using namespace std;

class state 
{
private:
	int type;
	double term;
	int num;
	friend class process;///////////other declare?
public:
	state(int Type, double Term);
	~state() {};
	void transtion(process &p);
};