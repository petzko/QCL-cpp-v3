/*
 * RNFDSolver.hpp
 *
 *  Created on: Apr 7, 2016
 *      Author: petzko
 */

#ifndef SRC_SOLVERS_RNFDSOLVER_HPP_
#define SRC_SOLVERS_RNFDSOLVER_HPP_

#include "PropagationEqnSolver.hpp"


namespace MB{
template<typename _Tp>
class RNFDSolver: public PropagationEqnSolver<_Tp>{

private:
	int _N;
	double _dx;
	bool p_direction;
	double _c;
	_Tp* _U1;

public:

	RNFDSolver(unsigned int N, double dx, bool direction, double velocity, _Tp* U1);

	_Tp makeStep(_Tp const * F, _Tp const* F_t, _Tp const *K, double dt,_Tp const * U0,const _Tp& ftr) ;

	/**
	 * set the boundary of the wave vector!
	 * @param val -> of type _Tp is the value to be set at the boundary.
	 * @param flag -> of type int is the index of the element at which the boundary is to be set
	 */
	void setBdry(_Tp val,unsigned int flag);
	_Tp* setLatestSolution(_Tp* sol);
	virtual ~RNFDSolver();



};

}


#endif /* SRC_SOLVERS_RNFDSOLVER_HPP_ */
