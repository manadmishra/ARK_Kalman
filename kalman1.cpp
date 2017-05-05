#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "matrix.h"
#include <unistd.h>
#define vel 0.3
#define dt .02


float vel=0.3,dt=0.02,r=0,theta=45;

float** initialize(float **a , int row, int col)
{

	a=(float**)malloc(row*sizeof(float*));

	for(int i=0 ; i < row ; i++)
    	a[i]=(float*)malloc(col*sizeof(float));

	for(int i=0 ; i < row ; i++)
    {
    	for(int j=0;j < col ; j++)
			a[i][j]=0;
    }
    
   return a;
} 

int main(int argc, char const *argv[])
{
	float **F_mat, **H_mat , **P_mat , **R_mat , **Q_mat  , **X_mat , **S_mat, **Z_mat;
	F_mat = initialize(F_mat , 4,4);
	H_mat = initialize(H_mat , 4,4);
	P_mat = initialize(P_mat , 4,4);
	Q_mat = initialize(Q_mat , 4,4);
	X_mat = initialize(X_mat , 3,1);
	R_mat = initialize(R_mat , 4,4);
	Z_mat = initialize(Z_mat , 4,4);



	return 0;
}