#ifndef SRC_SOLVERS_DMSOLVER_HPP_
#define SRC_SOLVERS_DMSOLVER_HPP_
#include "../matrix/matrix.hpp"
#include "../common/utils.hpp"

namespace MB{

template<typename _Tp>

class DMSolver{

public:
	virtual void makeStep( _Tp const * rhs, double dt) = 0;
	virtual _Tp* getLatestSolution() = 0;
	virtual _Tp* setLatestSolution(_Tp* newsol)= 0;
	virtual ~DMSolver(){;} ;
};

}
#endif /* SRC_SOLVERS_DMSOLVER_HPP_ */