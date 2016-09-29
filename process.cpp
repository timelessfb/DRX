#include "process.h"

process::process(double lamda, double t0, double ton, double ts, double tl, double tpo, double tp, int n, int np)
{
	double Lamda = lamda;
	double T0 = t0;
	double Ton = ton;
	double Ts = ts;
	double Tl = tl;
	double Tpo = tpo;
	double Tp = tp;
	int N = n;
	int Np = np;
}

vector<int> process::Type_hit_count(state_num, 0);
//vector<double>process::Type_total_time(state_num, 0);


void process::process_exe(state& s) 
{
	while (Np <= iteration) 
	{
		process &p = *this;
		//s.transtion(*this);
		s.transtion(p);
	}
}

void process::display() 
{
	for (int i= 0; i < state_num; i++) 
	{
		cout << Type_hit_count[i]<<endl;
	}
}

