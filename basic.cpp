#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include"matrix.h"
#define t 1





int main()
{
 float **A_mat;

  A_mat=(float**)malloc(3*sizeof(float*));

  for(int i=0;i<3;i++)
    A_mat[i]=(float*)malloc(3*sizeof(float));

  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
  A_mat[i][j]=0;
    }
 
  matrix m(3,3);  
  m.con_to_mtrx(A_mat,3,3);

  m.show();


  
  float **A_mat1;

  A_mat1=(float**)malloc(3*sizeof(float*));

  for(int i=0;i<3;i++)
    A_mat1[i]=(float*)malloc(3*sizeof(float));
  A_mat1[0][0]=1;
  A_mat1[0][1]=t;
  A_mat1[0][2]=0;
  A_mat1[1][0]=0;
  A_mat1[1][1]=1;
  A_mat1[1][2]=0;
  A_mat1[2][0]=0;
  A_mat1[2][1]=0;
  A_mat1[2][2]=1;
  


   matrix m1(3,3);  
  m1.con_to_mtrx(A_mat1,3,3);

  m1.show();
  

  return 0;

}
  
