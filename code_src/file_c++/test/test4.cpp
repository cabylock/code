#include<iostream>
using namespace std; 

class heap
{
	private: 
		int data[100];
		int n  = 0 ; 

	public: 

	int len()
	{
		return  n ; 

	}
	void swim(int index)
	{
		if( index  == 0)
		{
			return ; 
		}
		else 
		{
			int parent = (index -1)/2 ;
			if( data[parent] > data[index])
			{
				swap( data[parent], data[index]); 
			}

			swim( parent); 

		}
	}

	void sink( int index)
	{
		int left = 2 * index +1; 
		int right = 2 * index + 2 ; 
		int index_min = index; 
		if( left < n  && data[left] < data[index_min])
		{
			index_min = left;
		}
		if( right < n  && data[right]< data[index_min] )
		{
			index_min =right; 
		}
		if( index_min != index)
		{
			swap(data[index], data[index_min]); 
			sink(index_min); 
		}
		
	
	}

	void add(int val)
	{
		data[n++] = val ; 
		swim(n-1) ;
	}

	void erase()
	{
		if( n == 0)
		{
			cout <<"empty! "; 
			 return ;
		}
		swap( data[0], data[--n]); 
		
		sink(0); 
	}

	void print_() {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

};

class graph : heap
{
	// Add graph-related members and methods here
	public:
		int x; int y; 
	

};

int adj[100][100];


int dijkstra(int start, int destination)
{

}



int main()
{
	int v,e; cin >> v >> e; 
	for ( int i = 0 ; i< e ; i++)
	{
		int x,  y ,  z; 
		cin >> x >> y >> z; 
		adj[x][y]= z;
		adj[y][x]= z; 
		
	}
	



}

