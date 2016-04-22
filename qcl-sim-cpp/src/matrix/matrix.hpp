#ifndef _MATRIX_
#define _MATRIX_

#include <common/utils.hpp>

/***************************************************************
 * Usual 2D matrix of size dimI x dimJ
 ***************************************************************/
namespace MB {

template<typename _Tp>
void copyData( _Tp const * cFROM, _Tp * cTO, size_t LEN) {
	switch (gettype<_Tp>()){
	case FLT:
			cblas_scopy(LEN, (float*) cFROM, 1,(float*) cTO, 1);
		break;
	case DBL:
			cblas_dcopy(LEN, (double*)cFROM, 1, (double*) cTO, 1);
		break;
	case CPLX_FLOAT:
			cblas_ccopy(LEN, (void*) cFROM, 1,(void*) cTO, 1);
		break;
	case CPLX_DOUBLE:
			cblas_zcopy(LEN, (void*) cFROM, 1, (void*) cTO, 1);
		break;
	default:
		throw std::domain_error(
				"Unsupported data type for matrix copy operation");
	}
	cblas_zcopy(LEN, (void*) cFROM, 1, (void*) cTO, 1);

}

}

#endif
