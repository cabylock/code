#include<iostream>
#include<string> 
using namespace std ; 


void solve( int n1, int n2 , string a, string b, int time )
{
  char res[n1+n2]={0}; 
   
    for(int i = 0 ; i< n2 ; i++)
    {
      if(time -i>0)
      { 
        int step = time - i ; 
        if( n1 + i -step  < i )
        {
          res[i]  = b[i];
        }
        else
        res[n1+ i -step ] = b[i];
      }
      else 
      {
        res[n1 + i]=b[i];
      }
    }
    for(int i = 0 ; i< n1 ; i++)
    { 
      if( time - i > 0)
      {
        int step = time -i ; 
        if( n1- i-1 +step  < n1 +n2 -1 -i   )
        {
          res[n1 - i -1 +step]  = a[i];
        }
        else 
        res[n1 +n2 -i -1] = a[i];
      }
      else 
      {
        res[n1-i-1 ]  =a[i];
      }
    }
    for(int i = 0 ; i< n1+n2 ; i++)
    {
      cout<< res[i] ;
    }
    cout<< endl; 

}

int main()
{    
  int n1, n2 , t; 
  string a, b; 
  while( cin >> n1 >> n2 >> t )
  {
    cin >> a >> b ;
    
    solve(n1 , n2 , a, b, t );
  }
    

}