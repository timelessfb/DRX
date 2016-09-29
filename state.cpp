#include "state.h"

state::state(int Type, double Term) 
{
	type = Type;
	term = Term;
}

void state::transtion(process& p) 
{
	/*
	default_random_engine generator;
	poisson_distribution<double> distribution(p.Lamda);
	double xx;
	xx = distribution(generator);
	*/
	default_random_engine generator;
	poisson_distribution<int> distribution(30);
	int yy = distribution(generator);;
	double xx;
	xx = yy;
	xx = xx / 900;
	switch (this->type)
	{
	case 0:
	{
		p.Type_hit_count[this->type] += 1;
		if (num > 0 && p.Arr < term) 
		{
			p.Np++;
			p.Arr = p.Arr + xx;   ///////////////////////
			type = 0;
			term = p.Arr + p.T0;
			num -= 1;
		}
		else 
		{
			type = 1;
			if (num = 0) 
			{
				term = p.Arr + xx + p.Ton;
				p.Np++;
			}
			else 
			{
				term += p.Ton;
			}
		}
		break;
	}
	case 1:
	{
		p.Type_hit_count[this->type] += 1;
		if (p.Arr < term) 
		{
			while (p.Arr < term) 
			{
				p.Arr += xx;
				p.Np++;
				p.Type_hit_count[this->type] += 1;
				if (p.Np >= p.iteration)
					break;//////////////////
			}
			type = 0;
			num = p.N;
			term = p.Arr + p.Tpo + p.T0;
		}
		else
		{
			type = 2;
			term = term + p.Ts - p.Ton;
		}
		break;
	}
	case 2:
	{
		p.Type_hit_count[this->type] += 1;
		while (p.Arr < term) 
		{
			p.Arr += xx;
			if (p.Np >= p.iteration)
				break;
			p.Np++;
			p.Type_hit_count[this->type] += 1;
		}
		p.Np--;
		p.Arr -= xx;////////////
		term += p.Ton;
		type = 3;
		break;
	}
	case 3:
	{
		p.Type_hit_count[this->type] += 1;
		if (p.Arr < term) 
		{
			while (p.Arr < term) 
			{
				p.Arr += xx;
				p.Np++;
				p.Type_hit_count[this->type] += 1;
				if (p.Np >= p.iteration)
					break;//////////////////
			}
			type = 0;
			num = p.N;
			term = p.Arr + p.Tpo + p.T0;
		}
		else
		{
			type = 4;
			term = term + p.Tl - p.Ton;
		}
		break;
	}
	case 4:
	{
		p.Type_hit_count[this->type] += 1;
		while (p.Arr < term)
		{
			p.Arr += xx;
			if (p.Np >= p.iteration)
				break;
			p.Np++;
			p.Type_hit_count[this->type] += 1;
		}
		p.Np--;
		p.Arr -= xx;////////////
		term += p.Tpo;
		type = 5;
		break;
	}
	case 5:
	{
		p.Type_hit_count[this->type] += 1;
		if (p.Arr < term)
		{
		while (p.Arr < term)
		{
			p.Arr += xx;
			p.Np++;
			p.Type_hit_count[this->type] += 1;
			if (p.Np >= p.iteration)
				break;//////////////////
		}
			type = 0;
			num = p.N;
			term = p.Arr + p.Tpo + p.T0;
		}
		else
		{
			type = 6;
			term = term + p.Tp;
		}
		break;
		
	}
	case 6:
	{
		p.Type_hit_count[this->type] += 1;
		while (p.Arr < term)
		{
			p.Arr += xx;
			if (p.Np >= p.iteration)
			break;
			p.Np++;
			p.Type_hit_count[this->type] += 1;
		}
			p.Np--;
			p.Arr -= xx;////////////
			term += p.Tpo;
			type = 5;
		break;
	}
	}
}


