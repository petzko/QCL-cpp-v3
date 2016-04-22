///*
// * SimLoop.hpp
// *
// *  Created on: Apr 11, 2016
// *      Author: petzko
// */
//
#ifndef SRC_SIM_SIMLOOP_HPP_
#define SRC_SIM_SIMLOOP_HPP_
#include "SimData.hpp"
#include "SimSettings.hpp"

void makeMaxwellVars(MB::SimSettings& set, MB::SimData& dat);
void makeBlochVars(MB::SimSettings& set, MB::SimData& dat);

void stepMaxwellVars(MB::SimSettings& set, MB::SimData& dat);
void stepBlochVars(MB::SimSettings& set, MB::SimData& dat);
void updateSolutions(MB::SimSettings& set, MB::SimData& dat);

void startSim(char* simFile,char* setFile,double* deph_times,int attempt);


#endif /* SRC_SIM_SIMLOOP_HPP_ */
