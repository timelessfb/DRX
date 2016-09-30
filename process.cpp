#include "process.h"

process::process(double lamda, double t0, double ton, double ts, double tl, double tpo, double tp, int n, int np)
{
	Lamda = lamda;
	T0 = t0;
	Ton = ton;
	Ts = ts;
	Tl = tl;
	Tpo = tpo;
	Tp = tp;
	N = n;
	Np = np;
	//cout << Np << endl;
}

vector<int> process::Type_hit_count(state_num, 0);
//vector<double>process::Type_total_time(state_num, 0);


void process::process_exe(state& s) 
{
	//cout << Np << endl;
	//Np = 0;
	while (Np <= iteration) 
	{
		//cout << Np << endl;
		//process &p = *this;
		s.transtion(*this);
		//s.transtion(p);
	}
}

void process::display() 
{
	for (int i= 0; i < state_num; i++) 
	{
		cout << Type_hit_count[i]<<endl;
	}
}

