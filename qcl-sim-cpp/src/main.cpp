#include <matrix/matrix.hpp>
#include <sim/SimSettings.hpp>
#include <common/CONSTANTS.hpp>
#include <sim/SimLoop.hpp>
#include <iostream>

using namespace std;
using namespace MB;




int main() {


	char* simFname  = "/home/petzko/workspace/qcl-sim-cpp/Debug/OPTICAMAIN.sim";
	char* setFname  = "/home/petzko/workspace/qcl-sim-cpp/Debug/12-1-off.set";

	startSim(simFname,setFname);

	std::cout << "\n";
	std::cout<<"Goodbye world\n";

}

