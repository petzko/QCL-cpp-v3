#include "RNFDSolver.hpp"

#include <omp.h>

template<typename _Tp>
MB::RNFDSolver<_Tp>::RNFDSolver(unsigned int N, double dx, bool direction, double velocity, _Tp* U1){

	this->_N = N;
	this->_dx = dx;
	this-> p_direction = direction;
	this->_c  = velocity;
	this->_U1 = U1;
}

template<typename _Tp>
_Tp MB::RNFDSolver<_Tp>::makeStep(_Tp const * F, _Tp const* F_t, _Tp const *K, double dt,_Tp const * U0,const _Tp& ftr) {

	if(this->_c*dt != this->_dx){
		MB_OUT_ERR("RNFDsolver make step failed! Magic time step not selected!",__FILE__,__LINE__);
		throw std::domain_error("Magic time step requirement violated!");
	}



	double dt_2 = ((dt*dt)/2.);

	if(p_direction){

#pragma omp parallel for
		for(int x = 1 ; x < _N; x++){
			_Tp E_x = (U0[x]-U0[x-1])/_dx;
			_Tp F_x = (F[x]- F[x-1])/_dx;
			_U1[x] = U0[x-1] +dt*(ftr*F[x]+K[x]*U0[x]) +dt_2*(ftr*F_t[x]-_c*ftr*F_x -2*_c*K[x]*E_x + K[x]*ftr*F[x]+K[x]*K[x]*U0[x]);
		}
	}else{
#pragma omp parallel for
		for(int x = 0 ; x < _N-1; x++){
			_Tp E_x = (U0[x+1] - U0[x])/_dx;
			_Tp F_x = ( F[x+1] -  F[x])/_dx;
			_U1[x] = U0[x+1] + dt*(ftr*F[x]+K[x]*U0[x])+dt_2*(ftr*F_t[x]+_c*ftr*F_x +2*_c*K[x]*E_x + K[x]*ftr*F[x]+K[x]*K[x]*U0[x]);
		}
	}
	_Tp res;
	if(p_direction )
		res = _U1[_N-1];
	else
		res = _U1[0];

	return res;

}

template<typename _Tp>
void  MB::RNFDSolver<_Tp>::setBdry(_Tp val,unsigned int flag){
	if (flag <0 || flag >= _N){
		MB_OUT_ERR(" setBdry(:)! Boundary location flag outside allowed domain.",__FILE__,__LINE__);
		throw std::domain_error("Check boundary flag? ") ;
	}
	this->_U1[flag] = val;
}

template<typename _Tp>
_Tp* MB::RNFDSolver<_Tp>::setLatestSolution(_Tp* sol){

	if (sol == _U1)
		return NULL;
	_Tp* res = _U1;
	_U1 =sol ;
	return res;
}

template<typename _Tp>
MB::RNFDSolver<_Tp>::~RNFDSolver(){
	;
}


template class MB::RNFDSolver< COMPLEXDOUBLE >;
