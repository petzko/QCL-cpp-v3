///*
// * matrix.cpp
// *
// *  Created on: Feb 4, 2015
// *      Author: petz
// */
//
//#include "matrix/matrix.hpp"
//
//
//
//
//
//template<typename _Tp>
//Matrix<_Tp>& Matrix<_Tp>::operator=(const Matrix<_Tp>& arg) {
//
//	if(this == &arg)
//		return *this;
//
//	if (_i2-_i1 != arg._i2-arg._i1 	|| _j2-_j1 != arg._j2-arg._j1) {
//		MB_OUT_ERR(" copy assignment operator! Mtx dimensions mismatch!",__FILE__,__LINE__);
//		throw std::length_error("Matrix Dimensions do not aggree.");
//	}
//	std::vector<int> slice = arg.getSliceVector();
//
//	int N = _j2-_j1+1;
//
//	switch (gettype<_Tp>()){
//	case FLT:
//		for (int i = _i1; i<= _i2;i++)
//			cblas_scopy(N, (float*) arg.getMtxData()[i+(arg._i1-_i1)] + arg._j1, 1,(float*) this->getMtxData()[i]+ _j1, 1);
//		break;
//
//	case DBL:
//		for (int i = _i1; i<= _i2;i++)
//			cblas_dcopy(N, (double*) arg.getMtxData()[i+(arg._i1-_i1)]+arg._j1, 1, (double*) this->getMtxData()[i]+_j1, 1);
//		break;
//	case CPLX_FLOAT:
//		for (int i = _i1; i<= _i2;i++)
//			cblas_ccopy(N, (void*) ((COMPLEXFLOAT*)arg.getMtxData()[i+(arg._i1-_i1)]+arg._j1), 1,(void*) ((COMPLEXFLOAT*)this->getMtxData()[i]+_j1), 1);
//		break;
//	case CPLX_DOUBLE:
//
//		for (int i = _i1; i<= _i2;i++)
//			cblas_zcopy(N, (void*) ((COMPLEXDOUBLE*) arg.getMtxData()[i+(arg._i1-_i1)]+arg._j1), 1, (void*) ((COMPLEXDOUBLE*) this->getMtxData()[i]+_j1), 1);
//		break;
//	default:
//		throw std::domain_error(
//				"Unsupported data type for matrix copy operation");
//	}
//	return *this;
//
//}
//
////overload the addition operator -> A lot of copying is done at the end!
//template<typename _Tp>
//Matrix<_Tp> Matrix<_Tp>::operator+(const Matrix<_Tp>& arg) const {
//
//	if (_i2-_i1 != arg._i2-arg._i1
//			|| _j2-_j1 != arg._j2-arg._j1) {
//		MB_OUT_ERR(" copy assignment operator! Mtx dimensions mismatch!",__FILE__,__LINE__);
//		throw std::length_error("Matrix Dimensions do not aggree.");
//	}
//	std::vector<int> slice = arg.getSliceVector();
//
//	//the below operation invokes the copy constructor!
//	// the result matrix will be of size
//	// (_i2-_i1 + 1) x (_j2 - _j1 + 1) , i.e. the size of the current slice of this and arg!
//
//	Matrix<_Tp> res = arg; // res is not sliced !
//
//	COMPLEXDOUBLE alpha_d = 1.;
//	COMPLEXFLOAT  alpha_f = 1.;
//	int N = _j2-_j1+1;
//
//	switch (gettype<_Tp>()) {
//	case FLT:
//		for(int i = _i1; i <= _i2; i++)
//			cblas_saxpy(N, 1.0, (float*) (this->getMtxData()[i]+_j1),	1, (float*) res.getMtxData()[i-_i1], 1);
//
//		break;
//	case DBL:
//		for(int i = _i1; i <= _i2; i++)
//			cblas_daxpy(N, 1.0, (double*) (this->getMtxData()[i]+_j1),1, (double*) res.getMtxData()[i-_i1], 1);
//		break;
//	case CPLX_FLOAT:
//		for(int i = _i1; i <= _i2; i++)
//			cblas_caxpy(N, (void*) &alpha_f,(void*) ((COMPLEXFLOAT*) (this->getMtxData()[i]+_j1)), 1,(void*) (COMPLEXFLOAT*) res.getMtxData()[i-_i1], 1);
//		break;
//	case CPLX_DOUBLE:
//		for(int i = _i1; i <= _i2; i++)
//			cblas_zaxpy(N, (void*) &alpha_d,(void*) ( (COMPLEXDOUBLE*)(this->getMtxData()[i]+_j1)), 1,(void*) (COMPLEXDOUBLE*) res.getMtxData()[i-_i1], 1);
//		break;
//	default:
//		throw std::domain_error(
//				"Unsupported data type for matrix-matrix addition!");
//
//	}
//	return res;
//}
//
////overload the subtraction operator
//template<typename _Tp>
//Matrix<_Tp> Matrix<_Tp>::operator-(const Matrix<_Tp>& arg) {
//
//	if (_i2-_i1 != arg._i2-arg._i1
//			|| _j2-_j1 != arg._j2-arg._j1) {
//		MB_OUT_ERR(" copy assignment operator! Mtx dimensions mismatch!",__FILE__,__LINE__);
//		throw std::length_error("Matrix Dimensions do not aggree.");
//	}
//
//	Matrix<_Tp> res = ((_Tp) -1.) * arg;
//	return (*this) + res;
//}
