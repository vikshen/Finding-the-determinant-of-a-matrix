#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long determinant(vector< vector<long long> > m) {
  // TODO: Return the determinant of the square matrix passed in
  long long n = m.size();
  vector<vector<long long>> temp(n, vector<long long> (n));
  long long i, j, k, p, q, det=0;
  if(n==1)
    return m[0][0];
  else if(n==2)
    return m[0][0]*m[1][1]-m[0][1]*m[1][0];
  else
  {
     for(i=0;i<n;i++)
     {
       p=0;
       q=0;
       for(j=1;j<n;j++)
       {
         for(k=0;k<n;k++)
         {
           if(i==k)
             continue;
           temp[p][q]=m[j][k];
           q++;
           
         }
         p++;
         q=0;
       }
       det=det+(m[0][i]*pow(-1,i)*determinant(temp));
     }
     return det;
  }
}
