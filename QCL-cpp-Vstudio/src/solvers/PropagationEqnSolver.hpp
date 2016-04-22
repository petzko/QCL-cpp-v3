/*
 * PropagationEqnSolver.hpp
 *
 *  Created on: Apr 7, 2016
 *      Author: petzko
 */

#ifndef SRC_SOLVERS_PROPAGATIONEQNSOLVER_HPP_
#define SRC_SOLVERS_PROPAGATIONEQNSOLVER_HPP_
#include "../common/utils.hpp"

namespace MB{

template<typename _Tp>
class PropagationEqnSolver{

public:
	virtual _Tp makeStep(_Tp const * F, _Tp const* F_t, _Tp const *K, double dt,_Tp const * U0,const _Tp& ftr) = 0;
	virtual void setBdry(_Tp val,unsigned int flag)= 0;
	virtual	_Tp* setLatestSolution(_Tp* sol)= 0;
	virtual ~PropagationEqnSolver(){;}

};


}



#endif /* SRC_SOLVERS_PROPAGATIONEQNSOLVER_HPP_ */
