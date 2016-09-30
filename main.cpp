#include <iostream>
#include "process.h"
#include "state.h"

using namespace std;

int main() 
{
	process p(1.0 / 30, 0.02, 0.08, 0.16, 0.32, 0.001, 2.560, 1, 0);
	state s(0, 0.02, 1);
	p.process_exe(s);
	p.display();
	while (1);
	return 0;
}


