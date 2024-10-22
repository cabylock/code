#include<iostream>
#include<map>
using namespace std; 




int main()
{
   map<float,int> a; 
   
   for(int i = -20; i<= 20 ; i++)
   {
      a[(3/4*i)] ++;
      a[2*i] ++ ;
   }

   for( int i = 10; i<=10; i++)
   {
      cout<< a[i]
   }



}