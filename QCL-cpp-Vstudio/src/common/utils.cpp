/*
 * utils.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: petzko
 */

#include "..\common\utils.hpp"

#ifdef _MATLAB_SUPPORT_

	#include <mat.h>
	#include <mex.h>
	#include <matrix.h>

	void write2Matlab(mxArray *var, const char *varname,const char *filename){

		MATFile *pmat;
		pmat = matOpen(filename,"u");
		if(pmat == NULL){
			pmat = matOpen(filename, "w");
		}



		if (pmat == NULL) {
			printf("Error creating file %s\n", filename);
			return;
		}

		matPutVariable(pmat, varname, var);
		matClose(pmat);
	}
#endif 



