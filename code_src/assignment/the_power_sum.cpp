#include<iostream>
#include<math.h>
using namespace std;

int solution(int x, int n, int maxpow)
{     int count = 0 ;
      for(int i = maxpow;  i >0; i--)
      {
            int val = x - pow(i,n) ;
            if(val == 0)
            {
                  count ++  ;
            }
            else if(val > 0)
            {
                   count += solution(val,n,i-1) ;
            }
            else
            {
                  
            }
      }
      return count;
}


int powerSum(int X, int N) 
{  
      return solution(X,N,pow(X,1.0/N)) ;
   
}

int main()
{
   int X, N ;
   cin >> X >> N ;
   cout << powerSum(X,N) << endl ;
   
   return 0 ;


}