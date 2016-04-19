/*
 * utils.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: petzko
 */

#include <common/utils.hpp>

//std::ostream& operator<<(std::ostream& out, complex double nr) {
//
//	out << "(" << creal(nr) << ";" << cimag(nr) << ")";
//	return out;
//}
//
//std::ostream& operator<<(std::ostream& out, complex float nr) {
//	out << "(" << creal(nr) << ";" << cimag(nr) << ")";
//	return out;
//}



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




