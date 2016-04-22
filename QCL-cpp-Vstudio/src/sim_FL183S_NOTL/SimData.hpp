///*
// * SimData.hpp
// *
// *  Created on: Apr 8, 2016
// *      Author: petzko
// */
//
#ifndef SRC_SIM_SIMDATA_HPP_
#define SRC_SIM_SIMDATA_HPP_

#include <string>
#include "..\matrix\matrix.hpp"
#include "..\common\utils.hpp"

#include "..\solvers\PropagationEqnSolver.hpp"
#include "..\solvers\DMSolver.hpp"



namespace MB{

struct SimData{

	double c,T_R,f_R,hbar;
	size_t INJ,ULL,LLL,DEPOP,POP1,POP2;
	size_t NLVL;

	double E0,l0;
	double dx,dt;

	double diffusion;
	double zUL, Ncarriers,trace_rho;
	double t;
	size_t iter_ctr;
	size_t N_t;

	std::vector< std::vector<double> > W;
	std::vector< std::vector<double> > HTB;
	std::vector<double>  G;

	double losses;
	double dipR ;
	COMPLEXDOUBLE factor;

	COMPLEXDOUBLE dE32;
	COMPLEXDOUBLE dE13;
	COMPLEXDOUBLE dE12;


	COMPLEXDOUBLE E13 ; // rad/ps; 1->3 traisition freq
	COMPLEXDOUBLE E12; // rad/ps; 1->2 transition freq
	COMPLEXDOUBLE E32; // rad/ps  3->2 transition freq (optical transition)

	COMPLEXDOUBLE gamma_13;
	COMPLEXDOUBLE gamma_32;
	COMPLEXDOUBLE gamma_12;



	// SIMULATION DATA -> store all simulation arrays in an SD MATRIX! SD0 for the previous time step sim data
	// and SD1 for the latest time step data and SDRHS for the RHS data of the von Neumann eqn;

	_TYPE_** SD0;
	_TYPE_** SD1;
	_TYPE_** SD_t;

	//populations
	size_t r110,r330,r220;

	//COHERENCES
	size_t r130,n32p,n32m, n12p,n12m;

	//SHB POPS
	size_t r11p,r33p,r22p;
	//SHB COHERENCES
	size_t r13p,r13m;
	// indices of the rows in our storage mtrices where the additional population vectors are to be found!
	size_t rPOP1, rPOP2;


	size_t U; size_t V ;


	// num of vars if SHB is on -> 17/12 if  is off!
	size_t Nvars;

	//wave eqn. solvers!
	MB::PropagationEqnSolver<_TYPE_>* U_solver  ;
	MB::PropagationEqnSolver<_TYPE_>* V_solver  ;

	// loss variable
	_TYPE_* K;

	
	MB::DMSolver<_TYPE_>* r110_solver ;
	MB::DMSolver<_TYPE_>* r330_solver; 
	MB::DMSolver<_TYPE_>* r220_solver ;
	MB::DMSolver<_TYPE_>* pop1_solver ;
	MB::DMSolver<_TYPE_>* pop2_solver ;

	MB::DMSolver<_TYPE_>* r11p_solver ;
	MB::DMSolver<_TYPE_>* r33p_solver ;
	MB::DMSolver<_TYPE_>* r22p_solver ;

	MB::DMSolver<_TYPE_>* r130_solver ;
	MB::DMSolver<_TYPE_>* n32p_solver ;
	MB::DMSolver<_TYPE_>* n32m_solver ;
	MB::DMSolver<_TYPE_>* n12p_solver ;
	MB::DMSolver<_TYPE_>* n12m_solver ;

	MB::DMSolver<_TYPE_>* r13p_solver ;
	MB::DMSolver<_TYPE_>* r13m_solver ;

#ifdef _MATLAB_SUPPORT_
	Engine* m_Engine; // matlab engine in question. 
	mxArray *U_x;  // vector holding the forward field
	mxArray *V_x; // vector holding the backward field
	mxArray *Ymod; // this is used for phase compensation
#endif 

	~SimData(){


#ifdef _MATLAB_SUPPORT_
		engClose(m_Engine);
		mxDestroyArray(U_x); 
		mxDestroyArray(V_x); 
		#ifdef _DISP_COMPENSATE_
				mxDestroyArray(Ymod);
		#endif 
#endif 


		// clear up simulation data
		if (SD1 != NULL){
			if (SD1[0] != NULL)
				free(SD1[0]);
			free(SD1);
		}

		// clear up simulation data
		if (SD0 != NULL){
			if (SD0[0] != NULL)
				free(SD0[0]);
			free(SD0);
		}

		std::cout << "Free Completed \n";



		// clear up simulation data
		if (SD_t != NULL){
			if (SD_t[0] != NULL)
				free(SD_t[0]);
			free(SD_t);
		}



		// clear up data
		if (K != NULL){
			free(K);
		}




		if(r110_solver != NULL)
			delete r110_solver;
		if(r330_solver != NULL)
			delete r330_solver;
		if(r220_solver != NULL)
			delete r220_solver;

		if(pop1_solver != NULL)
			free(pop1_solver);

		if(pop2_solver != NULL)
			free(pop2_solver);


		if(r11p_solver != NULL)
			delete r11p_solver;
		if(r33p_solver != NULL)
			delete r33p_solver;
		if(r22p_solver != NULL)
			delete r22p_solver;

		if(r130_solver != NULL)
			delete r130_solver;
		if(n32p_solver != NULL)
			delete n32p_solver;
		if(n32m_solver != NULL)
			delete n32m_solver;
		if(n12p_solver != NULL)
			delete n12p_solver;
		if(n12m_solver != NULL)
			delete n12m_solver;
		if(r13p_solver != NULL)
			delete r13p_solver;
		if(r13m_solver != NULL)
			delete r13m_solver;
		if(U_solver != NULL)
			delete U_solver;
		if(V_solver != NULL)
			delete V_solver;
		std::cout << "SimData OUT! "<< "\n";
	}

};


}
#endif /* SRC_SIM_SIMDATA_HPP_ */
