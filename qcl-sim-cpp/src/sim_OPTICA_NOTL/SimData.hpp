/////*
//// * SimData.hpp
//// *
//// *  Created on: Apr 8, 2016
//// *      Author: petzko
//// */
////
//#ifndef SRC_SIM_SIMDATA_HPP_
//#define SRC_SIM_SIMDATA_HPP_
//
//#include <string>
//#include "../matrix/matrix.hpp"
//#include "../common/utils.hpp"
//
//#include "../solvers/PropagationEqnSolver.hpp"
//#include "../solvers/DMSolver.hpp"
//
//
//
//namespace MB{
//
//struct SimData{
//
//	double c,T_R,f_R,hbar;
//	size_t INJ,ULL,LLL,RES,DEPOP;
//	size_t NLVL;
//
//	double E0,l0;
//	double dx,dt;
//
//	double diffusion;
//	double zUL, Ncarriers,trace_rho;
//	double t;
//	size_t iter_ctr;
//	size_t N_t;
//
//	std::vector< std::vector<double> > W;
//	std::vector< std::vector<double> > HTB;
//	std::vector<double>  G;
//
//	double losses;
//	double dipR = 1;
//	COMPLEXDOUBLE factor;
//
//	COMPLEXDOUBLE dE32;
//	COMPLEXDOUBLE dE13;
//	COMPLEXDOUBLE dE12;
//
//
//	COMPLEXDOUBLE E13 ; // rad/ps; 1->3 traisition freq
//	COMPLEXDOUBLE E12; // rad/ps; 1->2 transition freq
//	COMPLEXDOUBLE E32; // rad/ps  3->2 transition freq (optical transition)
//
//	COMPLEXDOUBLE gamma_13;
//	COMPLEXDOUBLE gamma_32;
//	COMPLEXDOUBLE gamma_12;
//
//
//
//	// SIMULATION DATA -> store all simulation arrays in an SD MATRIX! SD0 for the previous time step sim data
//	// and SD1 for the latest time step data and SDRHS for the RHS data of the von Neumann eqn;
//
//	_TYPE_** SD0  = NULL;
//	_TYPE_** SD1  = NULL;
//	_TYPE_** SDRHS  = NULL;
//
//	//populations
//	size_t r110,r330,r220,rRES;
//
//	//COHERENCES
//	size_t r130,n32p,n32m, n12p,n12m;
//
//	//SHB POPS
//	size_t r11p,r33p,r22p;
//	//SHB COHERENCES
//	size_t r13p,r13m;
//
//	size_t U; size_t V ;
//
//	// num of vars if SHB is on -> 16
//	// else Nvars = 11;
//
//	// num of vars if SHB  is off!
//	size_t Nvars = 11;
//
//	//wave eqn. solvers!
//	MB::PropagationEqnSolver<_TYPE_>* U_solver  = NULL;
//	MB::PropagationEqnSolver<_TYPE_>* V_solver  = NULL;
//
//	// loss variable
//	_TYPE_* K;
//
//	////	 bloch solvers!
//	MB::DMSolver<_TYPE_>* r110_solver = NULL;
//	MB::DMSolver<_TYPE_>* r330_solver = NULL;
//	MB::DMSolver<_TYPE_>* r220_solver = NULL;
//	MB::DMSolver<_TYPE_>* rRES_solver = NULL;
//
//	MB::DMSolver<_TYPE_>* r11p_solver = NULL;
//	MB::DMSolver<_TYPE_>* r33p_solver = NULL;
//	MB::DMSolver<_TYPE_>* r22p_solver = NULL;
//
//	MB::DMSolver<_TYPE_>* r130_solver = NULL;
//	MB::DMSolver<_TYPE_>* n32p_solver = NULL;
//	MB::DMSolver<_TYPE_>* n32m_solver = NULL;
//	MB::DMSolver<_TYPE_>* n12p_solver = NULL;
//	MB::DMSolver<_TYPE_>* n12m_solver = NULL;
//
//	MB::DMSolver<_TYPE_>* r13p_solver = NULL;
//	MB::DMSolver<_TYPE_>* r13m_solver = NULL;
//
//
//	~SimData(){
//
//
//		// clear up simulation data
//		if (SD1 != NULL){
//			if (SD1[0] != NULL)
//				free(SD1[0]);
//			free(SD1);
//		}
//
//		// clear up simulation data
//		if (SD0 != NULL){
//			if (SD0[0] != NULL)
//				free(SD0[0]);
//			free(SD0);
//		}
//
//		std::cout << "Free Completed \n";
//
//
//
//		// clear up simulation data
//		if (SDRHS != NULL){
//			if (SDRHS[0] != NULL)
//				free(SDRHS[0]);
//			free(SDRHS);
//		}
//
//
//
//		// clear up data
//		if (K != NULL){
//			free(K);
//		}
//
//
//
//
//		if(r110_solver != NULL)
//			delete r110_solver;
//		if(r330_solver != NULL)
//			delete r330_solver;
//		if(r220_solver != NULL)
//			delete r220_solver;
//		if(rRES_solver != NULL)
//			delete rRES_solver;
//
//		if(r11p_solver != NULL)
//			delete r11p_solver;
//		if(r33p_solver != NULL)
//			delete r33p_solver;
//		if(r22p_solver != NULL)
//			delete r22p_solver;
//
//		if(r130_solver != NULL)
//			delete r130_solver;
//		if(n32p_solver != NULL)
//			delete n32p_solver;
//		if(n32m_solver != NULL)
//			delete n32m_solver;
//		if(n12p_solver != NULL)
//			delete n12p_solver;
//		if(n12m_solver != NULL)
//			delete n12m_solver;
//		if(r13p_solver != NULL)
//			delete r13p_solver;
//		if(r13m_solver != NULL)
//			delete r13m_solver;
//		if(U_solver != NULL)
//			delete U_solver;
//		if(V_solver != NULL)
//			delete V_solver;
//		std::cout << "SimData OUT! "<< "\n";
//	}
//
//};
//
//
//}
//#endif /* SRC_SIM_SIMDATA_HPP_ */