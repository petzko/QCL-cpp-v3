///*
// * SimLoop.cpp
// *
// *  Created on: Apr 11, 2016
// *      Author: petzko
// */
//
//
//
//#include <sim_OPTICA_NOTL/SimData.hpp>
//#include <sim_OPTICA_NOTL/SimLoop.hpp>
//#include <sim_OPTICA_NOTL/SimSettings.hpp>
//#include "../matrix/matrix.hpp"
//
//#include "../solvers/RNFDSolver.hpp"
//#include "../solvers/MultistepDMSolver.hpp"
//
//#include "../common/utils.hpp"
//#include "../common/CONSTANTS.hpp"
//
//
//
//
//
//
//// allocating memory for a matlab array:
//// path to MATLAB LIBRARY -> do not forget to include the matlab so lib.
//// LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/MATLAB/R2016a/bin/glnxa64/
//// declaring & defining a matlab array: mxArray *e_field =  mxCreateDoubleMatrix(s.N_x, s.N_t/s.ct_plot, mxREAL);
//
////
//void write2Matlab(mxArray *var, const char *varname,const char *filename){
//
//	MATFile *pmat;
//	pmat = matOpen(filename,"u");
//
//	if(pmat == NULL){
//		pmat = matOpen(filename, "w");
//	}
//
//
//
//	if (pmat == NULL) {
//		printf("Error creating file %s\n", filename);
//		return;
//	}
//
//	matPutVariable(pmat, varname, var);
//	matClose(pmat);
//}
//
//
//
//void makeMaxwellVars(MB::SimSettings&  set, MB::SimData& dat){
//
//
//	// init u as a gaussian !
//	double tp = 1;
//	double x0 = 6*set.Ltot/7;
//	double argument = 0.f ;
//	dat.losses = -dat.c*dat.l0;
//	dat.factor = -_i*dat.c*dat.trace_rho;
//
//	for (int i = 0 ; i < set.N; i++ ){
//		argument = ((dat.dx*i-x0)/dat.c)/tp;
//		dat.SD0[dat.U][i] = exp(-argument*argument);
//		dat.SD1[dat.U][i] = exp(-argument*argument);
//		dat.K[i] = dat.losses;
//	}
//
//	dat.U_solver = new MB::RNFDSolver<_TYPE_>(set.N,dat.dx,true,dat.c,dat.SD1[dat.U]);
//	dat.V_solver = new MB::RNFDSolver<_TYPE_>(set.N,dat.dx,false,dat.c,dat.SD1[dat.V]);
//
//}
//
//void makeBlochVars(MB::SimSettings& set, MB::SimData& dat){
//
//	srand(time(NULL));
//	for(int i = 0 ; i < set.N; i++ ){
//
//		dat.SD0[dat.r110][i] = 1./3.;
//		dat.SD0[dat.r330][i] = 1./3.;
//		dat.SD0[dat.r220][i] = 1./3.;
//		dat.SD0[dat.rRES][i] = 0.;
//
//		dat.SD0[dat.r130][i] = 1e-15*((rand()/(1.0*RAND_MAX)+_i*(rand()/(1.0*RAND_MAX))));
//		dat.SD0[dat.n32p][i] = 1e-15*((rand()/(1.0*RAND_MAX)+_i*(rand()/(1.0*RAND_MAX))));
//		dat.SD0[dat.n32m][i] = 1e-15*((rand()/(1.0*RAND_MAX)+_i*(rand()/(1.0*RAND_MAX))));
//		dat.SD0[dat.n12p][i] = 1e-15*((rand()/(1.0*RAND_MAX)+_i*(rand()/(1.0*RAND_MAX))));
//		dat.SD0[dat.n12m][i] = 1e-15*((rand()/(1.0*RAND_MAX)+_i*(rand()/(1.0*RAND_MAX))));
//
//		if(set.shb > 0){
//			dat.SD0[dat.r13p][i] = 0.0;
//			dat.SD0[dat.r13m][i] = 0.0;
//			dat.SD0[dat.r11p][i] = 0.0;
//			dat.SD0[dat.r33p][i] = 0.0;
//			dat.SD0[dat.r22p][i] = 0.0;
//		}
//
//		if(i %100 == 0)
//			srand(time(NULL)+rand()*i);
//
//	}
//
//	dat.r110_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r110]);
//	dat.r330_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r330]);
//	dat.r220_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r220]);
//	dat.rRES_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.rRES]);
//
//	dat.r130_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r130]);
//	dat.n32p_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.n32p]);
//	dat.n32m_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.n32m]);
//	dat.n12p_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.n12p]);
//	dat.n12m_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.n12m]);
//
//	//
//	if(set.shb > 0){
//		dat.r11p_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r11p]);
//		dat.r33p_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r33p]);
//		dat.r22p_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r22p]);
//		dat.r13p_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r13p]);
//		dat.r13m_solver = new MB::MultistepDMSolver<_TYPE_>(set.nrSteps,set.N,dat.SD1[dat.r13m]);
//	}
//
//
//
//}
//
//void updateSolutions(MB::SimSettings& set, MB::SimData & dat){
//	MB::copyData(dat.SD1[0],dat.SD0[0],dat.Nvars*set.N);
//}
//void stepMaxwellVars(MB::SimSettings&  set, MB::SimData& dat){
//
//	_TYPE_ ftr = dat.factor*dat.dipR;
//	_TYPE_ bdry4V = dat.U_solver->makeStep(dat.SD0[dat.n32p],dat.SDRHS[dat.n32p],dat.K,dat.dt,dat.SD0[dat.U],ftr);
//	_TYPE_ bdry4U = dat.V_solver->makeStep(dat.SD0[dat.n32m],dat.SDRHS[dat.n32m],dat.K,dat.dt,dat.SD0[dat.V],ftr);
//
//	dat.U_solver->setBdry(bdry4U,0);
//	dat.V_solver->setBdry(bdry4V,set.N-1);
//
//
//}
//void stepBlochVars(MB::SimSettings& set, MB::SimData& dat){
//	//
//	size_t INJ = dat.INJ;
//	size_t ULL = dat.ULL;
//	size_t LLL = dat.LLL;
//	size_t RES = dat.RES;
//	size_t DEPOP = dat.DEPOP;
//	size_t r110 = dat.r110;
//	size_t r330 = dat.r330;
//	size_t r220 = dat.r220;
//	size_t rRES = dat.rRES;
//
//	//COHERENCES
//	size_t r130 = dat.r130;
//	size_t n32p = dat.n32p;
//	size_t n32m = dat.n32m;
//	size_t n12p = dat.n12p;
//	size_t n12m = dat.n12m;
//
//	size_t r11p = dat.r11p;
//	size_t r33p = dat.r33p;
//	size_t r22p = dat.r22p;
//	size_t r13p = dat.r13p;
//	size_t r13m = dat.r13m;
//	size_t V = dat.V;
//	size_t U = dat.U;
//
//
//	_TYPE_  LM;
//	/**
//	 * Which will be the most cache-efficient way to iterate throught those big data structures ?
//	 * 1) one large for loop -> less likely to be cache efficient since SD0 might not fit into memory
//	 * 		total array size of SD0 = N*sizeof(_TYPE_)*Nvar -> in Bytes
//	 * 		so for N = 3000 , _TYPE_ std::complex<double> and Nvar = 16 we have
//	 * 		size(SD0) = 3000*8*2*16/1E3 =768 KB
//	 * 		size(SDRHS) = another 768 KB
//	 * 		total 768x2 = 1536 kB! should comfortably fits in cache-memory (my PROCS have around 8000kB cache!
//	 */
//
//
//#pragma omp parallel
//#pragma omp for
//	for(size_t x =0 ; x < set.N ; x++){
//		//r110
//		dat.SDRHS[r110][x] = _i*dat.HTB[INJ][ULL]*(dat.SD0[r130][x]-CONJ(dat.SD0[r130][x]))+(dat.W[ULL][INJ] + dat.W[ULL][DEPOP])*dat.SD0[r330][x] + (dat.W[LLL][INJ]+dat.W[LLL][DEPOP])*dat.SD0[r220][x]+ (dat.W[RES][INJ]+dat.W[RES][DEPOP])*dat.SD0[rRES][x]- dat.G[INJ]*dat.SD0[r110][x];
//		LM  = dat.dipR*(CONJ(dat.SD0[U][x]*dat.SD0[n32p][x]) + CONJ(dat.SD0[V][x])*CONJ(dat.SD0[n32m][x]));
//		//r330
//		dat.SDRHS[r330][x] = _i*dat.HTB[INJ][ULL]*(CONJ(dat.SD0[r130][x]) - dat.SD0[r130][x]) +_i/2.0*(LM-CONJ(LM)) +dat.SD0[r110][x]*dat.W[INJ][ULL] + dat.SD0[r220][x]*dat.W[LLL][ULL] + dat.SD0[rRES][x]*dat.W[RES][ULL]- dat.G[ULL]*dat.SD0[r330][x];
//		//r220
//		dat.SDRHS[r220][x] = -_i/2.0*(LM-CONJ(LM)) + dat.SD0[r110][x]*dat.W[INJ][LLL]+ dat.SD0[r330][x]*dat.W[ULL][LLL] +dat.SD0[rRES][x]*dat.W[RES][LLL]- dat.G[LLL]*dat.SD0[r220][x];
//		//rRES0
//		dat.SDRHS[rRES][x] =  dat.SD0[r110][x]*dat.W[INJ][RES]+ dat.SD0[r330][x]*dat.W[ULL][RES]+ dat.SD0[r220][x]*dat.W[LLL][RES] - dat.G[RES]*dat.SD0[rRES][x];
//		// COHERENCES
//		// r130
//		dat.SDRHS[r130][x] = dat.dE13*dat.SD0[r130][x] + _i*dat.HTB[INJ][ULL]*(dat.SD0[r110][x]-dat.SD0[r330][x]) +_i/2.0*dat.dipR*(CONJ(dat.SD0[U][x])*dat.SD0[n12p][x] + CONJ(dat.SD0[V][x])*dat.SD0[n12m][x]);
//		//n32+
//		dat.SDRHS[n32p][x] = dat.dE32*dat.SD0[n32p][x] + _i/2.0*dat.dipR*( dat.SD0[U][x]*(dat.SD0[r330][x]-dat.SD0[r220][x])  + dat.SD0[V][x]*(dat.SD0[r33p][x]-dat.SD0[r22p][x]))- _i*dat.HTB[INJ][ULL]*dat.SD0[n12p][x];
//		//n32-
//		dat.SDRHS[n32m][x] = dat.dE32*dat.SD0[n32m][x] + _i/2.0*dat.dipR*( dat.SD0[V][x]*(dat.SD0[r330][x]-dat.SD0[r220][x]) + dat.SD0[U][x]*CONJ(dat.SD0[r33p][x]-dat.SD0[r22p][x]))- _i*dat.HTB[INJ][ULL]*dat.SD0[n12m][x];
//		//n12+
//		dat.SDRHS[n12p][x] = dat.dE12*dat.SD0[n12p][x] +_i/2.0*dat.dipR*(dat.SD0[U][x]*dat.SD0[r130][x] + dat.SD0[V][x]*dat.SD0[r13p][x]) - _i*dat.HTB[INJ][ULL]*dat.SD0[n32p][x];
//		//n32-
//		dat.SDRHS[n12m][x] = dat.dE12*dat.SD0[n12m][x] +_i/2.0*dat.dipR*(dat.SD0[V][x]*dat.SD0[r130][x] + dat.SD0[U][x]*dat.SD0[r13m][x]) - _i*dat.HTB[INJ][ULL]*dat.SD0[n32m][x];
//
//		if(set.shb > 0 ){
//			//r11+
//			dat.SDRHS[r11p][x] = _i*dat.HTB[INJ][ULL]*(dat.SD0[r13p][x]-CONJ(dat.SD0[r13m][x])) + (dat.W[ULL][INJ]+dat.W[ULL][DEPOP])*dat.SD0[r33p][x]+ (dat.W[LLL][INJ]+dat.W[LLL][DEPOP])*dat.SD0[r22p][x] - (dat.G[INJ]+dat.diffusion)*dat.SD0[r11p][x];
//			/// r33+
//			dat.SDRHS[r33p][x]  = _i*dat.HTB[INJ][ULL]*(CONJ(dat.SD0[r13m][x])-dat.SD0[r13p][x])+_i/2.0*dat.dipR*(CONJ(dat.SD0[V][x])*dat.SD0[n32p][x] - (dat.SD0[U][x]*CONJ(dat.SD0[n32m][x]))) +  dat.W[INJ][ULL]*dat.SD0[r11p][x] + dat.W[LLL][ULL]*dat.SD0[r22p][x] - (dat.G[ULL]+dat.diffusion)*dat.SD0[r33p][x];
//			// r22+
//			dat.SDRHS[r22p][x]  = -_i/2.0*dat.dipR*(CONJ(dat.SD0[V][x])*dat.SD0[n32p][x] - dat.SD0[U][x]*CONJ(dat.SD0[n32m][x])) + dat.W[INJ][LLL]*dat.SD0[r11p][x] + dat.W[ULL][LLL]*dat.SD0[r33p][x] - (dat.G[LLL]+dat.diffusion)*dat.SD0[r22p][x];
//			// r13+
//			dat.SDRHS[r13p][x] = (dat.dE13-dat.diffusion)*dat.SD0[r13p][x] + _i*dat.HTB[INJ][ULL]*(dat.SD0[r11p][x]-dat.SD0[r33p][x]) +_i/2.0*dat.dipR*CONJ(dat.SD0[V][x])*dat.SD0[n12p][x];
//			// r13-
//			dat.SDRHS[r13m][x]  = (dat.dE13-dat.diffusion)*dat.SD0[r13m][x] + _i*dat.HTB[INJ][ULL]*CONJ(dat.SD0[r11p][x]-dat.SD0[r33p][x]) + _i/2.0*dat.dipR*CONJ(dat.SD0[U][x])*dat.SD0[n12m][x];
//		}
//	}
//
//
//	dat.r110_solver->makeStep(dat.SDRHS[r110],dat.dt);
//	dat.r330_solver->makeStep(dat.SDRHS[r330],dat.dt);
//	dat.r220_solver->makeStep(dat.SDRHS[r220],dat.dt);
//	dat.rRES_solver->makeStep(dat.SDRHS[rRES],dat.dt);
//
//
//
//	dat.r130_solver->makeStep(dat.SDRHS[r130],dat.dt);
//	dat.n32p_solver->makeStep(dat.SDRHS[n32p],dat.dt);
//	dat.n32m_solver->makeStep(dat.SDRHS[n32m],dat.dt);
//	dat.n12p_solver->makeStep(dat.SDRHS[n12p],dat.dt);
//	dat.n12m_solver->makeStep(dat.SDRHS[n12m],dat.dt);
//
//	//
//	if(set.shb > 0){
//		dat.r11p_solver->makeStep(dat.SDRHS[r11p],dat.dt);
//		dat.r33p_solver->makeStep(dat.SDRHS[r33p],dat.dt);
//		dat.r22p_solver->makeStep(dat.SDRHS[r22p],dat.dt);
//		dat.r13p_solver->makeStep(dat.SDRHS[r13p],dat.dt);
//		dat.r13m_solver->makeStep(dat.SDRHS[r13m],dat.dt);
//	}
//
//
//
//
//
//
//}
//
//void startSim(char* simFile,char* setFile){
//
//	MB::SimSettings set(simFile,setFile);
//	set.initSimSettings();
//	MB::SimData dat;
//
//	dat.c = C0*1./(set.lch/set.tch)/set.nTHz;
//	std::cout <<"phase velocity: " << dat.c << "\n";
//
//	dat.T_R = 2*set.Ltot/dat.c; dat.f_R = 1/dat.T_R;
//
//	dat.hbar = HBAR/Q0/set.tch;
//
//	dat.INJ = 0; dat.ULL = 1;dat.LLL = 2; dat.RES = 3; dat.DEPOP = 4;
//	dat.NLVL = 5;
//
//	dat.E0 = (set.HTB[dat.ULL+dat.NLVL*dat.ULL]-set.HTB[dat.LLL+dat.NLVL*dat.LLL])/dat.hbar;
//	std::cout <<"Central Frequency (THz): " << dat.E0/2./M_PI << "\n";
//
//	dat.l0 = set.loss*100.0/(1/set.lch);
//	std::cout << "losses: " << dat.l0  << "\n";
//
//	dat.dx = set.Ltot/(set.N-1);
//	dat.dt =  dat.dx/dat.c;
//	std::cout << "timestep: " << dat.dt << "\n" ;
//	std::cout << "grid size: " << dat.dx << "\n" ;
//
//	dat.diffusion =4*dat.E0/(dat.c*dat.c)*set.D*1e2/(1/set.tch);
//	dat.zUL = set.zUL;
//	dat.dipR = 1;
//
//	double zUL2 = (dat.zUL*1e-9*Q0)*(dat.zUL*1e-9*Q0);
//	dat.Ncarriers = 5./3.*set.dN*(1e6)*set.Ld/set.Lp;
//	std::cout << "Carrier density! " << dat.Ncarriers << "\n";
//	dat.trace_rho = (dat.E0*1e12*dat.Ncarriers*set.Overlap*zUL2)/(EPS0*set.nTHz*C0*HBAR)/(1./set.tch/set.lch);
//	std::cout << "Trace: " << dat.trace_rho << "\n";
//
//	dat.G.resize(dat.NLVL);
//	dat.W.resize(dat.NLVL);
//	dat.HTB.resize(dat.NLVL);
//
//	for(size_t i = 0 ; i< dat.NLVL;i++){
//		dat.W[i].resize(dat.NLVL);
//		dat.HTB[i].resize(dat.NLVL);
//		for(size_t j = 0 ; j< dat.NLVL;j++){
//			dat.W[i][j] = set.Wmtx[j+i*dat.NLVL];
//			dat.HTB[i][j] = set.HTB[j+i*dat.NLVL]/dat.hbar; // rad/ps;
//		}
//	}
//
//	dat.G[dat.INJ] = dat.W[dat.INJ][dat.ULL]+ dat.W[dat.INJ][dat.LLL]+dat.W[dat.INJ][dat.RES];
//	dat.G[dat.ULL] = dat.W[dat.ULL][dat.INJ]+dat.W[dat.ULL][dat.LLL]+dat.W[dat.ULL][dat.DEPOP] + dat.W[dat.ULL][dat.RES];
//	dat.G[dat.LLL] =  dat.W[dat.LLL][dat.INJ]+dat.W[dat.LLL][dat.ULL]+dat.W[dat.LLL][dat.DEPOP] + dat.W[dat.LLL][dat.RES] ;
//	dat.G[dat.RES] =  dat.W[dat.RES][dat.INJ]+dat.W[dat.RES][dat.ULL]+dat.W[dat.RES][dat.LLL] +dat.W[dat.RES][dat.DEPOP] ;
//
//
//	/// Added Pure Dephasing
//	if(set.deph>0){
//		dat.gamma_13 = 0.5*(dat.G[dat.INJ]+dat.G[dat.ULL])+1/set.Tdeph_1; // dephsing of the resonant tunneling transition
//		dat.gamma_32 = 0.5*(dat.G[dat.ULL]+dat.G[dat.LLL])+1/set.Tdeph_2; // dephasing of the optical transision...
//		dat.gamma_12 = 0.5*(dat.G[dat.INJ]+dat.G[dat.LLL])+1/set.Tdeph_3; // dephasing of the latest transition
//	}else{
//		dat.gamma_13 = 0.5*(dat.G[dat.INJ]+dat.G[dat.ULL]); // dephsing of the resonant tunneling transition
//		dat.gamma_32 = 0.5*(dat.G[dat.ULL]+dat.G[dat.LLL]); // dephasing of the optical transision...
//		dat.gamma_12 = 0.5*(dat.G[dat.INJ]+dat.G[dat.LLL]); // dephasing of the latest transition
//	}
//
//	dat.E13 = (dat.HTB[dat.INJ][dat.INJ]-dat.HTB[dat.ULL][dat.ULL]); // rad/ps; 1->3 traisition freq
//	dat.E12 = (dat.HTB[dat.INJ][dat.INJ]-dat.HTB[dat.LLL][dat.LLL]); // rad/ps; 1->2 transition freq
//	dat.E32 = (dat.HTB[dat.ULL][dat.ULL]-dat.HTB[dat.LLL][dat.LLL]); // rad/ps  3->2 transition freq (optical transition)
//
//	dat.dE13 = -_i*dat.E13 - dat.gamma_13;
//	dat.dE32 = +_i*(dat.E0 - dat.E32) - dat.gamma_32;
//	dat.dE12 = +_i*(dat.E0 - dat.E12)- dat.gamma_12;
//
//	std::cout << "G: \n-> ";
//	for (int i = 0 ; i < dat.NLVL; i++)
//		std::cout << dat.G[i] << " ";
//
//	std::cout << "\n";
//	std::cout << "dE13-> " <<dat.dE13 << "\n";
//	std::cout << "dE32-> " <<dat.dE32 << "\n";
//	std::cout << "dE12-> " <<dat.dE12 << "\n";
//
//	/**
//	 *  set the indices!
//	 */
//
//	//populations
//	dat.r110= 0;
//	dat.r330 = 1 ;
//	dat.r220=2;
//	dat.rRES =3;
//
//	//COHERENCES
//	dat.r130=4;
//	dat.n32p = 5;
//	dat.n32m=6;
//	dat.n12p = 7;
//	dat.n12m=8;
//	dat.U = 9;
//	dat.V = 10;
//
//	if(set.shb>0){
//		//SHB POPS
//		dat.r11p = 9;
//		dat.r33p=10;
//		dat.r22p= 11;
//		//SHB COHERENCES
//		dat.r13p= 12;
//		dat.r13m=13;
//		dat.U = 14;
//		dat.V = 15;
//	}
//
//	dat.t = 0;
//	dat.N_t = 30000;
//	dat.iter_ctr = 0;
//	if(set.shb>0)
//		dat.Nvars = 16;
//	else
//		dat.Nvars = 11;
//
//
//
//
//
//	_TYPE_* tmpdata0 = (_TYPE_*)calloc(dat.Nvars*set.N,sizeof(_TYPE_));
//	dat.SD0  = (_TYPE_**) calloc(dat.Nvars,sizeof(_TYPE_*));
//	for (size_t i = 0 ; i < dat.Nvars ;i++)
//		dat.SD0[i] = tmpdata0 + i * set.N;
//
//	_TYPE_* tmpdata1 = (_TYPE_*)calloc(dat.Nvars*set.N,sizeof(_TYPE_));
//	dat.SD1 = (_TYPE_**) calloc(dat.Nvars,sizeof(_TYPE_*));
//	for (size_t i = 0 ; i < dat.Nvars ;i++)
//		dat.SD1[i] = tmpdata1 + i * set.N;
//
//	_TYPE_* tmpdataRHS = (_TYPE_*)calloc((dat.Nvars-2)*set.N,sizeof(_TYPE_));
//	dat.SDRHS = (_TYPE_**) calloc((dat.Nvars-2),sizeof(_TYPE_*));
//	for (size_t i = 0 ; i < (dat.Nvars-2) ;i++)
//		dat.SDRHS[i] = tmpdataRHS + i * set.N;
//
//
//	std::cout << "Number of simulation variables: <-" <<dat.Nvars <<"\n";
//	std::cout << "Total memory usage (SD0,SD1 & SDRHS): <-" <<(double) (dat.Nvars*sizeof(_TYPE_)*set.N*3)/1E3 << " KB\n";
//
//
//
//	//allocate memory for the losses array!
//	dat.K =  (_TYPE_*)calloc(set.N,sizeof(_TYPE_));
//
//	makeMaxwellVars(set,dat);
//	makeBlochVars(set,dat);
//	MB::copyData(dat.SD0[0],dat.SD1[0],dat.Nvars*set.N);
//
//	mxArray *record_U = mxCreateDoubleMatrix(1,dat.N_t,mxCOMPLEX);
//	mxArray *record_V = mxCreateDoubleMatrix(1,dat.N_t,mxCOMPLEX);
//	mxArray *record_POP1 = mxCreateDoubleMatrix(1,dat.N_t,mxREAL);
//	mxArray *record_POP3 = mxCreateDoubleMatrix(1,dat.N_t,mxREAL);
//	mxArray *record_POP2 = mxCreateDoubleMatrix(1,dat.N_t,mxREAL);
//	mxArray *record_POPRES = mxCreateDoubleMatrix(1,dat.N_t,mxREAL);
//
//	mxArray *record_POPSUM = mxCreateDoubleMatrix(1,dat.N_t,mxREAL);
//	size_t idx =  100;
//
//	long double tms = std::clock();
//	long double tme = std::clock();
//	long double numthreads;
//#pragma omp parallel
//	{
//		numthreads = omp_get_num_threads();
//	}
//
//	long double dur;
//	long double totaldur = 0 ;
//	while (dat.iter_ctr < dat.N_t){
//
//		stepBlochVars(set,dat);
//		stepMaxwellVars(set,dat);
//		updateSolutions(set,dat);
//
//		/**
//		 * store some data?
//		 */
//		*(mxGetPr(record_U)+dat.iter_ctr) = REAL(dat.SD1[dat.U][idx]);
//		*(mxGetPi(record_U)+dat.iter_ctr) = IMAG(dat.SD1[dat.U][idx]);
//
//		*(mxGetPr(record_V)+dat.iter_ctr) = REAL(dat.SD1[dat.V][idx]);
//		*(mxGetPi(record_V)+dat.iter_ctr) = IMAG(dat.SD1[dat.V][idx]);
//
//		*(mxGetPr(record_POP1)+dat.iter_ctr) = REAL(dat.SD1[dat.r110][idx]);
//		*(mxGetPr(record_POP3)+dat.iter_ctr) = REAL(dat.SD1[dat.r330][idx]);
//		*(mxGetPr(record_POP2)+dat.iter_ctr) = REAL(dat.SD1[dat.r220][idx]);
//		*(mxGetPr(record_POPRES)+dat.iter_ctr) = REAL(dat.SD1[dat.rRES][idx]);
//
//		*(mxGetPr(record_POPSUM)+dat.iter_ctr) = REAL(dat.SD1[dat.r110][idx]) +  REAL(dat.SD1[dat.r330][idx])+ REAL(dat.SD1[dat.r220][idx])+ REAL(dat.SD1[dat.rRES][idx]);
//
//		if (dat.iter_ctr % 1000 == 0){
//			std::cout << "Time @ iteration " << dat.iter_ctr << ": " << dat.t << "\n";
//			tme = std::clock()/numthreads;
//			dur = (tme-tms)/CLOCKS_PER_SEC;
//			tms = std::clock()/numthreads;
//			std::cout << " -> calculation time (sec):" << dur << "\n";
//			totaldur+=dur;
//			std::cout << "pop sum: -> "<< *(mxGetPr(record_POPSUM)+dat.iter_ctr) << "\n";
//		}
//		dat.iter_ctr++ ;
//		dat.t += dat.dt;
//	}
//
//	tme = std::clock()/numthreads;
//	dur = (tme-tms)/CLOCKS_PER_SEC;
//	totaldur+=dur;
//
//	write2Matlab(record_U,"U","out_file.mat");
//	write2Matlab(record_V,"V","out_file.mat");
//	write2Matlab(record_POPSUM,"popsum","out_file.mat");
//	write2Matlab(record_POP1,"pop1","out_file.mat");
//	write2Matlab(record_POP3,"pop3","out_file.mat");
//	write2Matlab(record_POP2,"pop2","out_file.mat");
//	write2Matlab(record_POPRES,"popres","out_file.mat");
//
//	std::cout<<"MainLoop Completed!" << "\n";
//	std::cout << "Simulation time: " <<  dat.t <<" (ps) \n";
//	std::cout << " -> calculation real time: (sec) " <<  totaldur <<"\n";
//
//
//}
//
