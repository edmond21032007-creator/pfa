/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your numericzal results */

double f(double t){
	return sin(t*t);
}

int main(){
	QuadFormula qf;
	double T1;
	/*setQuadFormula(&qf, "right");
	T1 = integrate_dx(f, -1, 4, 0.1, &qf);
	printf("right: %lf\n", T1);
	setQuadFormula(&qf, "middle");
	T1 = integrate_dx(f, -1, 4, 0.1, &qf);
	printf("middle: %lf\n", T1);
	setQuadFormula(&qf, "left");
	T1 = integrate_dx(f, -1, 4, 0.1, &qf);
	printf("left: %lf\n", T1);
	setQuadFormula(&qf, "trapezes");
	T1 = integrate_dx(f, -1, 4, 0.1, &qf);
	printf("trapezes :%lf\n", T1);
	setQuadFormula(&qf, "simpson");
	T1 = integrate_dx(f, -1, 4, 0.1, &qf);
	printf("simpson:%lf\n", T1);*/
	setQuadFormula(&qf, "gauss3");
	T1 = integrate(f, -1, 10, 50, &qf);
	printf("gauss3: %lf\n", T1);
	setQuadFormula(&qf, "gauss3");
	T1 = integrate_dx(f, -1, 10, 0.1, &qf);
	printf("gauss3_dx: %lf\n", T1);
  return 0;
}
