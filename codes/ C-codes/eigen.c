#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"matfun.h"
//#include"coeffs-mat.h"
//#include"matfun.h"
int main() {
    int m = 2;  // You can set the dimensions of your matrix
    int n = 3;

// Create a matrix
	double **G_v = createMat(m, n);
	double **C_m= createMat(3,3);
	double **C_mid= createMat(3,3);
	double **R_o=createMat(2,2);
	double **C_mid_dir= createMat(3,3);
	double **C_alt= createMat(3,3);
	double **C_in= createMat(3,3);
	double **cont_mat= createMat(3,3);
	double **i_con= createMat(3,3);

// Reading matrix data from .dat file
G_v=loadMat("vert.dat",m,n);
C_m=loadMat("C.dat",3,3);
C_mid=loadMat("C_mid.dat",3,3);
C_mid_dir=loadMat("C_mid_dir.dat",3,3);
R_o=loadMat("R.dat",2,2);
C_alt=loadMat("C_alt.dat",3,3);
C_in=loadMat("C_in.dat",3,3);

	
double **h=createMat(2,1);  
h[0][0]=G_v[0][0]-G_I[0][0];    h[1][0]=G_v[1][0]-G_I[0][1];
double **V=createMat(2,2);
V[0][0]=1;      V[0][1]=0;      V[1][0]=0;       V[1][1]=1;
double **u=createMat(2,1);
u[0][0]=G_I[0][0]-G_I[0][0];    u[1][0]=G_I[0][1]-G_I[0][1];
double **f=createMat(1,1);
f[0][0]=sqrt(pow(G_I[0][0]-G_i[0][0],2)+pow(G_I[0][1]-G_i[1][0],2));
f[0][0]=-f[0][0]*f[0][0];
double **gh=Matadd(Matadd(Matmul(Matmul(transposeMat(h,2,1),V,1,2,2),h,1,2,1), Matscale( Matmul(transposeMat(u,2,1),h,1,2,1),1,1,2) ,1,1),f,1,1);
double **sigmat=Matsub(Matmul(Matadd(Matmul(V,h,2,2,1),u,2,1),transposeMat(Matadd(Matmul(V,h,2,2,1),u,2,1),2,1),2,1,2) ,Matscale(V,2,2,gh[0][0]) ,2,2);





double **E_val=Mateigval(sigmat);
double **P=Mateigvec(sigmat);
double **u1=createMat(2,1);
u1[0][0]=sqrt(fabs(E_val[1][0]));  u1[1][0]=sqrt(fabs(E_val[0][0]));
double **u2=createMat(2,1);
u2[0][0]=sqrt(fabs(E_val[1][0]));  u2[1][0]=-sqrt(fabs(E_val[0][0]));


double **m1=Matmul(P,u1,2,2,1);
double **m2=Matmul(P,u2,2,2,1);

double **mu1n=Matmul(transposeMat(m1,2,1),Matadd(Matmul(V,h,2,2,1),u,2,1),1,2,1);  
double **mu1d=Matmul(transposeMat(m1,2,1),Matmul(V,m1,2,2,1),1,2,1);
double mu1=-mu1n[0][0]/mu1d[0][0];

double **mu2n=Matmul(transposeMat(m2,2,1),Matadd(Matmul(V,h,2,2,1),u,2,1),1,2,1);  
double **mu2d=Matmul(transposeMat(m2,2,1),Matmul(V,m2,2,2,1),1,2,1);
double mu2=-mu2n[0][0]/mu2d[0][0];

double **t1=createMat(2,1); double **t2=createMat(2,1);
t1[0][0]=mu1*m1[0][0]; t1[1][0]=mu1*m1[1][0];
t2[0][0]=mu2*m2[0][0]; t2[1][0]=mu2*m2[1][0];

double **E=Matadd(h,t1,2,1);
double **F=Matadd(h,t2,2,1);
	E[0][0]=E[0][0]+G_I[0][0];	E[1][0]=E[1][0]+G_I[0][1];
	F[0][0]=F[0][0]+G_I[0][0];	F[1][0]=F[1][0]+G_I[0][1];


// Printing matrices . 	
printf("\n Vectors \n");
printf("vertices matrix= \n");
printMat(G_v,2,3);

printf("Eigen vector \n");
printf("Incentre = \n");
printMat(G_I,1,2);
printf("contact points = \n");
printMat(G_i,2,3);
printf(" h = \n");
printMat(h,2,1);
printf("V = \n");
printMat(V,2,2);
printf("u = \n");
printMat(u,2,1);
printf("iradius = \n");
printMat(f,1,1);
printf("gh = \n");
printMat(gh,1,1);
printf("sigmat = \n");
printMat(sigmat,2,2);
printf("Eigen values = \n");
printMat(E_val,2,1);
printf("Eigen vectors = \n");
printMat(P,2,2);
//printf("gauss mat = \n");
//printMat(ga,2,2);
printf("u1 = \n");
printMat(u1,2,1);
printf("u2 = \n");
printMat(u2,2,1);
printf("m1 = \n");
printMat(m1,2,1);
printf("m2 = \n");
printMat(m2,2,1);
printf("E = \n");
printMat(E,2,1);
printf("F = \n");
printMat(F,2,1);
printf("%lf",sqrt(abs(E_val[1][0])));
}



