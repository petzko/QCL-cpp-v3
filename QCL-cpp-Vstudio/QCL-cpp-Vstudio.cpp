

#include "src\common\CONSTANTS.hpp"
#include  "src\common\utils.hpp"

#include <iostream>

#include <complex>
#include <iostream>

#include "src\sim_FL183S_NOTL\SimLoop.hpp"

using namespace std;
using namespace MB;


#define NATTEPMTS 3


int main() {


	char* simFname  = "FL183S.sim"; 
	char* setFname  = "FL183S.set";
	
	int attempt = 1;
	double dephtimes[NATTEPMTS]= {0.4, 1.25,1.25};
	omp_set_num_threads(16); 

	startSim(simFname,setFname,dephtimes,11);

	std::cout<<"Goodbye world\n";

}

