#include<iostream>

using namespace std; 


void pr( int * z)
{
   ++* z  ; 
  
}

int main()
{

   int a = 6; 
   int *p =&a;

  pr( &p) ; 

   cout << *p ;

}