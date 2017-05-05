#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "matrix.h"
#include <unistd.h>
//#define vel 0.3
#define dt .02
#define x 0
#define y 0
#define PI 3.141592654
#define theta PI/4


float vel=0.3;

float** initialize(int row, int col)
{
	float **a ;
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
	float **F_mat, **H_mat , **P_mat , **R_mat , **Q_mat  , **X_mat , **S_mat, **Z_mat , **K_mat;
	
	F_mat = initialize(4,4);
	H_mat = initialize(4,4);
	P_mat = initialize(4,4);
	Q_mat = initialize(4,4);
	X_mat = initialize(4,1);
	S_mat = initialize(4,4);
	R_mat = initialize(4,4);
	Z_mat = initialize(4,4);
	K_mat = initialize(4,4);


	F_mat[0][0] = 1;
	F_mat[0][2] = dt;
	F_mat[1][1] = 1;
	F_mat[1][3] = dt;
	F_mat[2][2] = 1;
	F_mat[3][3] = 1;

	H_mat[0][0] = 1;
	H_mat[1][1] = 1;

	P_mat[0][0] = 50;
	P_mat[1][1] = 50;
	P_mat[2][2] = .3;
	P_mat[3][3] = .3;


	Q_mat[2][2] = .0019739698;
	Q_mat[3][3] = .0324408797;

	X_mat[0][0] = x;
	X_mat[1][0] = y;
	X_mat[2][0] = vel*cos(theta);
	X_mat[3][0] = vel*sin(theta);

	R_mat[0][0] = .3;
	R_mat[1][1] = .3;

	matrix F(4,4) , H(4,4) , P(4,4) , R(4,4) , Q(4,4) , X(4,1) , S(4,4) , Z(4,4) , K(4,4); 

	F = F.con_to_mtrx(F_mat , 4 ,4);
	H = H.con_to_mtrx(H_mat , 4, 4);
	P = P.con_to_mtrx(P_mat , 4 ,4);
	R = R.con_to_mtrx(R_mat ,4,4);
	Q = Q.con_to_mtrx(Q_mat ,4 ,4);
	X = X.con_to_mtrx(X_mat , 4,1);
	S = S.con_to_mtrx(S_mat , 4 ,4);
	Z = Z.con_to_mtrx(Z_mat , 4 ,4);
	K = K.con_to_mtrx(K_mat ,4 ,4);

	float flag = 0 , temp = 1 ; 

	std::cout << "Q col" << Q.getcol() << "Q row" << Q.getrow();
	std::cout << "F col" << F.getcol() << "F row" << F.getrow();
	std::cout << "P col" << P.getcol() << "p row" << P.getrow();

	while(flag <= 20)
	{
		flag = temp*dt;

		std::cout << "New X" << "\n";
      	X.show();
      	std::cout << "PPPPPPPPPPPPPP" << "\n";
      	P.show();

     
    
      
      
      	//matrix S(3,3);
   
      	if((flag == (int)flag) && ((int)flag%5 == 0))
      	{

      		// A1=A.transpose();
	        std::cout << "NOISE NOISE NOISE NOISE!!!!!";

	       	P=(F*P)*F.transpose() + Q;
	        X=F*X;
	       // break;

        	flag+=0.8;

    	}
    	else
  		{

        	P=(F*P)*F.transpose();
    		X=F*X;
		}


		/*Z = H*X + W;
    
     	S = H*(P*H.transpose()) + R;
     
     	K = P*H.transpose()*S.inv();
     	X = X + K*(Z - H*X);
     	P = (I - K*H)*P;*/
		usleep(700000);
		temp++;

	
	}


	std::cout << X_mat[3][0];






	return 0;
}