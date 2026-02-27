



#define INTEGRATION_C

#include "integration.h"

//double wk[];
//double xk[];

bool setQuadFormula(QuadFormula* qf, char* name)
{
	if(strcmp(name,"left")==0){


		strcpy(qf-> name, name);

		qf->wk[0] = 1;
		qf->xk[0]=0;
		return true;
	
	}
	else if(strcmp(name,"right")==0){
		strcpy( qf-> name, name);
		//double wk[] = {1};
		//double xk[] = {1};
		qf->wk[0] = 1;
		qf->xk[0] = 1;
		qf->n = 0;
		return true;
	}
	else if(strcmp(name,"middle")==0){
		strcpy( qf-> name, name);
	//	double wk[] = {1};
	//	double xk[] = {1/2};
		qf->wk[0] = 1;
		qf->xk[0] = (double) 1/2;
		qf->n = 0;
		return true;
	}
	else if(strcmp(name,"trapezes")==0){
		strcpy( qf-> name, name);
		//double wk[]={1/2,1/2};
		//double xk[] = {0,1};
		qf->wk[0] = (double) 1/2;
		qf->wk[1] = (double) 1/2;
		qf->xk[0] = 0;
		qf->xk[1] = 1;
		qf->n = 1;
		return true;
	}


	else if(strcmp(name,"simpson")==0){
		strcpy(qf->name,name);

		qf->wk[0]=(double) 1/6;
		qf->wk[1]=(double) 2/3;
		qf->wk[2]=(double) 1/6;

		qf->xk[0]=(double) 0;
		qf->xk[1]=(double) 1/2;
		qf->xk[2]=(double) 1;

		qf->n=2;
		return true;
	}


	else if(strcmp(name,"gauss2")==0){
		strcpy(qf->name,name);

		qf->wk[0]=(double) 1/2;
		qf->wk[1]=(double) 1/2;
		//qf->wk[2]=(double) 1/6;

		qf->xk[0]=(double) 1/2-1/(2*sqrt(3));
		qf->xk[1]=(double) 1/2+1/(2*sqrt(3));
		//qf->xk[2]=(double) 1;

		qf->n=1;
		return true;
	}

	else if(strcmp(name,"gauss3")==0){
		strcpy(qf->name,name);

		qf->wk[0]=(double) 5/18;
		qf->wk[1]=(double) 4/9;
		qf->wk[2]=(double) 5/18;

		qf->xk[0]=(double) 1/2*(1-sqrt((double) 3/5));
		qf->xk[1]=(double) 1/2;
		qf->xk[2]=(double) 1/2*(1+sqrt((double) 3/5));

		qf->n=2;
		return true;
	
	}
	return false;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
	printf("Quadratic formula: %s\n", qf->name);
	/* Print everything else that may be useful */
}


/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
   */
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{	

	double start= a;
	double pas = (b-a)/N;
	//double end= a+pas;
	double tot = 0;

	for(int j = 0;j<N;j++){

	 	double aire_rec=0;
		for(int i =0; i<=qf->n;i++){
			aire_rec+= qf->wk[i]*f(start+qf->xk[i]*pas);
		}
		aire_rec *= pas;
		tot+=aire_rec;
		start+=pas;

	}

	return tot;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
	
	double start= a;
	double pas = dx;
	//double end= a+pas;
	double tot = 0;
	int N = (b-a)/dx;

	for(int j = 0;j<N;j++){

	 	double aire_rec=0;
		for(int i =0; i<=qf->n;i++){
			aire_rec+= qf->wk[i]*f(start+qf->xk[i]*pas);
		}
		aire_rec *= pas;
		tot+=aire_rec;
		start+=pas;

	}

	return tot;
//	return 0.0;
}


