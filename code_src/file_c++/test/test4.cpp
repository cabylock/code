#include<iostream>
using  namespace std; 

void prin1(int * p )
{
	cout << *p ;  cout <<" " << p<<endl;  ; 
}
void print2( int *& p )
{
	cout  << *p << " " <<  p <<endl ;
}

int main()
{
	int a =  4; 
	int * p  = & a; 
	cout << & a <<endl ; 
	prin1(p); 
	print2(p);

}