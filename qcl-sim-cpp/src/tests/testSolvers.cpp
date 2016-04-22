/*
 * testSolvers.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: petzko
 */


#include "testSolvers.hpp"
#include "../solvers/MultistepDMSolver.hpp"
#include <math.h>

double f(double t){return log(t+1) + sin(t);}
double f_t(double t){return (1.0/(t+1) + cos(t));}


void testDMsolver(){

	double error = 0;
	double tEnd = 1.5;
	double dt = 1E-1;
	int attempt = 1;
	int max_attempts = 8;
	double * glob_err = new double[max_attempts];


	for(int attempt = 0; attempt < max_attempts; attempt++){

		dt = dt/2;
		unsigned int N_t = (int) tEnd/dt;
		unsigned int nr_steps = 5;

		double* sol_new = new double[1];
		sol_new[0] =f(0.);
		double* sol_old = new double[1];
		sol_old[0] = f(0.);

		double* sol_num_all = new double[N_t];
		double* sol_a_all = new double[N_t];
		unsigned int N = 1;

		MB::MultistepDMSolver<double> solver(nr_steps,N,sol_new);

		sol_num_all[0] = sol_new[0];
		sol_a_all[0] = f(0.);

		double t = dt ;
		for(int iter = 1 ; iter < N_t ; iter ++ ){
			double tmp = f_t(t);

			solver.makeStep(&(tmp),dt);
			sol_num_all[iter] = solver.getLatestSolution()[0];
			sol_a_all[iter] = f(t);
			sol_old[0] = sol_new[0];
			t+=dt;
			std::cout << "error i: " << abs(sol_a_all[iter]-sol_num_all[iter]) <<" ";
		}
	}
}
