#include<iostream>

using namespace std;

int main()
{
      int n ;cin >> n;
      int a[n];   int ps[n+1]; ps[0] = 0;

      int value[n][n];

      for(int i = 0; i < n; i++)
      {
            
            cin >> a[i];
            ps[i+1] = ps[i] + a[i];
            
      }

      int max = 0 ; 

      for(int i = 0; i < n; i++)
      {
            for(int j = i; j < n; j++)
            {
                 if( i == j )
                 {
                  value[i][j] = 0;

                 }
                else 
                {
                 value[j][i] = (ps[j] - ps[i])*a[j] + value[j-1][i];
                   if(value[j][i] > max)
                   {
                     max = value[j][i];
                   }
                }
            }
      }
      
   
      
      cout << max << endl;

}




