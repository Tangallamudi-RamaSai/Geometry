#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"libs/matfun.h"
int main()
{
	int k=2;
	int m=2;//matrix row
	int n=1;//matrix column


	//Creating Matrix P,Q,R
	double **a=createMat(m,n);
	double **b=createMat(m,n);
	double **P=createMat(m,n);
	double **Q=createMat(m,n);
	double **R=createMat(m,n);


	//Load matrix from .dat file
	a=loadMat("a.dat",m,n);
	b=loadMat("b.dat",m,n);

	//calculating P,Q
	P=Matadd(Matscale(a,m,n,2),b,m,n);
	Q=Matsub(a,Matscale(b,m,n,3),m,n);
	
	//section formula R=(Q-k*P)/(1-k)
	R=Matscale(Matsub(Q,Matscale(P,m,n,k),m,n),m,n,1/1-k);


	//Printing Matrix
	printf("a=\n");
	printMat(a,m,n);
	printf("b=\n");
	printMat(b,m,n);
	printf("P=\n");
	printMat(P,m,n);
	printf("Q=\n");
	printMat(Q,m,n);
	printf("R=\n");
	printMat(R,m,n);
}
