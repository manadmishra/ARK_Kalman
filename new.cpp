#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include"matrix.h"
using namespace std;
float vel=0.3,dt=0.03,r=0,theta=45;
float timeIndex,m_a1,m_a2,m_a3,c_a1,c_a2,c_a3,tau1,tau2,tau3;
float a1,a2,a3,a1d,a2d,a3d,a1dd,a2dd,a3dd;
float new_a1d, new_a2d, new_a3d;
float TIME=0;
matrix A(3,3);
matrix B(3,3);
matrix C=matrix::identity(3);  //initialize them as 6×6 identity matrices
matrix Q=matrix::identity(3);
matrix R=matrix::identity(3);
matrix y(3,1);
matrix K(3,3);
matrix x(3,1);
matrix state(3,1);
matrix action(3,1);
matrix lastState(3,1);
matrix P=matrix::identity(3);
matrix p=matrix::identity(3);
matrix measurement(3,1);

void kalman(){
lastState=state;
state[0][0]=c_a1;
state[1][0]=c_a2;
state[2][0]=c_a3;

measurement[0][0]=m_a1;
measurement[1][0]=m_a2;
measurement[2][0]=m_a3;

action[0][0]=tau1;
action[1][0]=tau2;
action[2][0]=tau3;

matrix temp1(3,3);
matrix temp2(3,3);
matrix temp3(3,3);
matrix temp4(3,1);
/************ Prediction Equations*****************/
X_mat = A_mat*lastState + A_mat*action;
p = A_mat*P*A_mat.transpose + Q_mat;
/************ Update Equations **********/
temp4=(H_mat*p*H_mat.transpose+R)
K = p*H_mat*temp4.inv;

y=H_mat*state;

state = X_mat + K*(y-H_mat*lastState);

P = (identity(3) – K*H_mat)*p;

a1=state[0][0];
a2=state[1][0];
a3=state[2][0];
a1d=state[3][0];
a2d=state[4][0];
a3d=state[5][0];
}



int main()
{
  float **A_mat,**X_mat,**H_mat,**P_mat,**Q_mat;

  A_mat=(float**)malloc(3*sizeof(float*));

  for(int i=0;i<3;i++)
    A_mat[i]=(float*)malloc(3*sizeof(float));

  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
	A_mat[i][j]=0;
    }
 
  A_mat[1][1]=1;
  A_mat[0][0]=1;
  A_mat[2][2]=1;
  A_mat[0][1]=dt;

 
  matrix A(3,3);  
 A =  A.con_to_mtrx(A_mat,3,3);

  A.show();


  X_mat=(float**)malloc(3*sizeof(float*));

  for(int i=0;i<3;i++)
    X_mat[i]=(float*)malloc(1*sizeof(float));

  for(int i=0;i<3;i++)
    {
      for(int j=0;j<1;j++)
	X_mat[i][j]=0;
    }

  X_mat[1][0]=vel;
  X_mat[0][0]=r;
  X_mat[2][0]=theta;
 
  

  matrix X(3,1);  
  X = X.con_to_mtrx(X_mat,3,1);

  X.show();


  H_mat=(float**)malloc(3*sizeof(float*));

  for(int i=0;i<3;i++)
    H_mat[i]=(float*)malloc(3*sizeof(float));

  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
	{
	  if(i==j)
	    H_mat[i][j]=1;	
	  else H_mat[i][j]=0;
	}
    }

  matrix H(3,3);  
  H = H.con_to_mtrx(H_mat,3,3);

  H.show();


  P_mat=(float**)malloc(3*sizeof(float*));

  for(int i=0;i<3;i++)
    P_mat[i]=(float*)malloc(3*sizeof(float));

  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
	{
	  if(i==j)
	    P_mat[i][j]=50;	
	  else P_mat[i][j]=0;
	}
    }

  matrix P(3,3);  
  P = P.con_to_mtrx(P_mat,3,3);

  P.show();


  Q_mat=(float**)malloc(3*sizeof(float*));

  for(int i=0;i<3;i++)
    Q_mat[i]=(float*)malloc(3*sizeof(float));

  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
	{
	  if(i==j)
	    Q_mat[i][j]=0;	
	  else Q_mat[i][j]=0;
	}
    }

  Q_mat[2][2]=20;
  matrix Q(3,3);  
  Q = H.con_to_mtrx(Q_mat,3,3);

  Q.show();

 
state[0][0]=0.1;
state[1][0]=0.1;
state[2][0]=0.1;
lastState=state;

//initKalman();
char buffer[500];
ifstream readFile (“DATA.txt”); // this is where I read my data since I am proccessing it all offline

while (!readFile.eof()){
readFile.getline (buffer,500);
sscanf(buffer, “%f %f %f %f %f %f %f %f %f %f “,&timeIndex,&m_a1,&m_a2,&m_a3,&c_a1,&c_a2,&c_a3,&tau1,&tau2,&tau3);

kalman();
/*differentiation();
//integrate();

/*this is where I log the results to and/or print it to the screen */
FILE *file=fopen(“filterOutput.txt”, “a”);
fprintf(file,”%f %f %f %f %f %f %f %f %f %f \n”,TIME,a1,a2,a3,a1d,a2d,a3d,tau1,tau2,tau3);
fprintf(stderr,”%f %f %f %f %f %f %f %f %f %f \n”,TIME,a1,a2,a3,a1d,a2d,a3d,tau1,tau2,tau3);
fclose(file);
}
return 1;
} s

  return 0;

}
  
