#include <matrix/matrix.hpp>
#include <common/CONSTANTS.hpp>
//#include <sim_OPTICA_NOTL/SimLoop.hpp>
#include <sim_FS183S_NOTL/SimLoop.hpp>
#include <iostream>

#include "tests/testSolvers.hpp"
using namespace std;
using namespace MB;
#include <complex>

//void testComplex(){
//
//	std::complex<double> d (1,1);
//	std::cout << d*10.0 <<" " << d/10.0 <<" "<< d+10.0<<" "<< d-10.0 + _i<<"\n";
//
//	std::cout << d*10.0 <<" " << d/10.0 <<" "<< d+10.0 <<" "<< d-10.0 +_i <<"\n";
//
//}

#define NATTEPMTS 3


int main() {


	char* simFname  = "/home/petzko/workspace/qcl-sim-ptrArithmetic/qcl-sim-cpp/inputdata/FL183S.sim";
	char* setFname  = "/home/petzko/workspace/qcl-sim-ptrArithmetic/qcl-sim-cpp/inputdata/FL183S.set";
	int attempt = 1;
	// high 1-3 dephasing, normal 1-3 dephasing, low 1.3 dephasing!
	double dephtimes[NATTEPMTS][NATTEPMTS] = {{0.175, 1.25,1.25},{1.0, 1.25,1.25},{10.,  1.25,1.25}};
	for (int i = 0; i < NATTEPMTS ; i++)
		startSim(simFname,setFname,dephtimes[i],i);

	std::cout<<"Goodbye world\n";

}

