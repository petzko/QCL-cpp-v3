/*
 * MultiStepDMSolver.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: petzko
 */

#include "MultistepDMSolver.hpp"
#include <stdlib.h>

template<typename _Tp>
MB::MultistepDMSolver<_Tp>::MultistepDMSolver(unsigned int nrSteps,unsigned int nrPts,_Tp* SD1): _MAXSTEPS(5) {

	assert(nrSteps>=1);
	assert(nrSteps <= _MAXSTEPS); // check if nrSteps is in order!

	_m = nrSteps; _N = nrPts;


	_data = (_Tp**) calloc(_m,sizeof(_Tp*));
	for (int i = 0 ; i < _m ;i++)
		_data[i] = (_Tp*) calloc(_N,sizeof(_Tp));

	_coefs = getCoeffs(1,_m);
	_SD1 = SD1;
	_iterCtr = 1;
}


template<typename _Tp>
void MB::MultistepDMSolver<_Tp>::makeStep(_Tp const * rhs, double dt){

	//assign rhs to first position in data array
	copyData<_Tp>(rhs, _data[0],_N);

	//step
	for (int k = 0; k < _m ; k++)
#pragma omp parallel
#pragma omp for
		for(int i = 0 ; i < _N; i++)
			_SD1[i] = _SD1[i] +(_Tp)( dt*_coefs[k])*_data[k][i];


	_iterCtr++;
	if(_iterCtr<=_m)
		_coefs = getCoeffs(_iterCtr,_m);

	/*	Let the physical storage space look as follows
	 *
	 *  +++++++++++++++++++++++++
	 *  data[0] -> |_______________________|
	 *  data[1] -> |_______________________|
	 *  data[2] -> |_______________________|
	 *  data[3] -> |_______________________|
	 *
	 *  circularly shift the pointers of the data MTX by setting the
	 *  data[0] -> data[_m-1]; data[1] -> data[0] ; data[2] = data[1] ... data[_m-1] = data[_m-2];
	 *  the second last pointer to the data pointed to by
	 *
	 */

	_Tp* tmp = _data[_m-1];
	for(int k = _m-1; k >= 1; k--){
		_data[k] = _data[k-1];
	}
	_data[0] = tmp;

}

template<typename _Tp>
_Tp* MB::MultistepDMSolver<_Tp>:: getLatestSolution(){
	return this->_SD1;
}

template<typename _Tp>
_Tp*  MB::MultistepDMSolver<_Tp>::setLatestSolution(_Tp* newsol){
	if (newsol == this->_SD1)
		return NULL;
	_Tp* tmp = this->_SD1;
	this->_SD1 = newsol;

	return tmp;

}
template<typename _Tp>
MB::MultistepDMSolver<_Tp>::~MultistepDMSolver(){

	if(_data != NULL){
		for (int i = 0; i < _m; i++){
			if(_data[i] !=NULL)
				free(_data[i]);
		}
		free(_data);
	}


}

template<typename _Tp>
std::vector<double> MB::MultistepDMSolver<_Tp>::getCoeffs(unsigned int step,unsigned int mStep){
	if (step > this->_MAXSTEPS || step <= 0 ){
		MB_OUT_ERR("getCoeffs(..)! Maximum number of steps exceeds the given step argument or is (leq) than 0! ",__FILE__,__LINE__);
		throw std::domain_error("step param outside of the allowed domain!");
	}
	assert(step <= mStep);
	std::vector<double> cfs(mStep);// automatically initialized with zeros!

	switch (step){
	case 1:
		cfs[0] =  1.f;
		break;
	case 2:
		cfs[0] =3.f/2.f; cfs[1]= -1.f/2.f;
		break;
	case 3:
		cfs[0] = 23.f/12.f; cfs[1] =  -4.f/3.f ; cfs[2] = 5.f/12.f ;
		break;
	case 4:
		cfs[0] = 55.f/24.f;cfs[1] = -59.f/24.f; cfs[2] = 37.f/24.f; cfs[3] = -3.f/8.f;
		break;
	case 5:
		cfs[0] = 1901.f/720.f; cfs[1] =  -1387.f/360.f; cfs[2] = 109.f/30.f; cfs[3] =  -637.f/360.f; cfs[4] = 251.f/720.f;
		break;
	default:
		MB_OUT_ERR("getCoeffs(..)! How did you manage to sneak in a wrong value here?",__FILE__,__LINE__);
		throw std::domain_error("step param outside of the allowed domain!");
		break;
	}
	return cfs;

}

template class MB::MultistepDMSolver< COMPLEXFLOAT >;
template class MB::MultistepDMSolver< COMPLEXDOUBLE >;
