#include <iostream>
using namespace std;

class matrix
{ 
   int **p, m, n; 
public: 
   matrix(int row, int col) 
   { 
      m = row; 
      n = col; 
      p = new int*[m]; 
      for (int i = 0; i < m; ++i)
      {
	 p[i] = new int[n];
	 for (int j = 0; j < n; ++j)
	    p[i][j] = 0;
      }
   }
   
//    ~matrix() 
//    { 
//       delete [] p;
//    }
   
   void accept() 
   { 
      cout<<"Enter matrix elements: "; 
      for(int i = 0; i < m; i++) 
      { 
	 for(int j = 0; j < n; j++) 
	 { 
	    cin >> p[i][j]; 
	 } 
      } 
   }
   
   void display() 
   { 
      cout <<"The matrix is:\n";
      for(int i = 0; i < m; i++) 
      { 
	 for(int j = 0; j < n; j++) 
	 { 
	    cout << p[i][j] <<" "; 
	 }
	 cout <<endl;
      } 
   }
   
   matrix& operator+ (matrix& lhs, const matrix& m1)
   {
      return (*this += m1);
   }
   
   matrix& operator* (const matrix& m1)
   {
      return (*this *= m1);
   }
   
   matrix& operator+= (const matrix& rhs)
   {
      for(int i = 0; i < m; i++)
      {
	 for(int j = 0; j < n; j++)
	 {
	    p[i][j] += rhs.p[i][j]; 
	 } 
      }      
      return *this;
   }
   
   matrix& operator*= (const matrix& T)
   {
      if(n == T.m)
      {
	 for(int i = 0; i < T.m; ++i)
	 {
	    for(int k = 0; k < n; ++k)
	    {
		 p[i][k] *= T.p[k][i];
	    }
	 }
      }
      
      return *this;
   }
   
   matrix& operator= (const matrix& T)
   {
      p = T.p;
      n = T.n;
      m = T.m;
      
      return *this;
   }
   
};


int main()
{
   matrix rf(3,3), ff(3,3);
   rf.accept();
   cout << "\nrf\n";
   rf.display();
   
   ff.accept();
   cout << "\nff\n";
   ff.display();
   
   cout << "\nff = ff + rf\n";
   ff = ff + rf;
   ff.display();
   
   cout << "\nff = (rf * ff)\n";
   ff = (rf * ff);
   ff.display();
   
   cout << "\nrf += ff\n";
   rf += ff;
   rf.display();
}