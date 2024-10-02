#include<iostream>
#include<string> 
using namespace std ; 
int main()
{    
  int t ;cin >> t; 
  while( t --)
  {
    int n1,n2,time ; 
    cin >> n1 >> n2 >>time ; 
    string a; string b; 
    cin >> a >> b; 
    char res[n1+n2]; 
   
    for(int i = 0 ; i< n2 ; i++)
    {
      if(time -i>0)
      { 
        int step = time - i ; 
        if( n1 - i -step  < 0 )
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
        if( n1- i-1 +step  < n1 +n2   )
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


}