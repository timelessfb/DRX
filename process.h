#pragma once
#include <vector>
#include <iostream>

#include "state.h"

#define state_num 7
#define iter 10

using namespace std;
class process
{
private:
	double Arr;
	static vector<int> Type_hit_count;
	//static vector<double> Type_total_time;
	int Np;
	//system parameter,don't modify
	double Lamda;
	double T0;
	double Ton;
	double Ts;
	double Tl;
	double Tpo;
	double Tp;
	int N;
	static const int iteration = iter;
public:
	friend class state;
	process(double lamda, double t0, double ton, double ts, double tl, double tpo, double tp, int n, int np);
	~process() {};
	void process_exe(state& s);
	void display();
};


