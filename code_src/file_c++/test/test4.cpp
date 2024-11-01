#include<iostream>

using namespace std; 

int n = 0 ; int a[100]; 

void swim_up ( int index)
{
	if( index == 0)
	{
		return;
	}
	if( a[index] < a[(index-1)/2] ) 
	{
		int temp = a[index]; 
		a[index] = a[(index-1)/2] ;
		a[(index-1)/2] = temp ;
		swim_up((index-1)/2);
	}

}

void insert(int data)
{	
	a[n++] = data; 
	swim_up(n-1); 
}

void sink_down(int index)
{
	int left= 2*index+1; 
	int right = 2*index +2; 
	int min_i = index;
	if( left <n)
	{
		if( a[min_i] > a[left])
		{
			min_i = left; 
		}
	}
	if( right < n )
	{
		if( a[min_i] > a[right ])
		{
			min_i = right ; 
		}
	}
	if( min_i != index)
	{
		int temp  =a[index] ; 
		a[index] = a[min_i] ; 
		a[min_i] = temp ;
		sink_down(min_i) ; 
	}

}

void erase()
{	
	int temp = a[n-1] ; 
	a[n-1] =a[0]; 
	a[0] = temp ; 

	n -- ; 
	sink_down(0); 
}


void heapsort()
{
	while( n>0 )
	{
		cout << a[0] <<" "; 
		erase() ; 
	}

}


int main()
{
	 insert(95);
    insert(61);
    insert(83);
    insert(53);
    insert(39);
    insert(72);
    insert(16);
    insert(24);
    insert(48);
	 
	 erase();
	heapsort();
}


