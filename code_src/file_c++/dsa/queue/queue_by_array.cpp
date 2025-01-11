#include<iostream>

using namespace std;

int queu[100];
int front  = -1 ; 
int rear = -1 ; 

void push(int x)
{	
	if( (rear +1)%100 ==front )
	{
		cout<< "full" <<endl; return; 
	}
	rear ++;
	rear= (rear % 100) ; 
	
	queu[rear] = x; 
}

void peek()
{	
	if( front == rear)
	{cout<< "empty" <<endl ; 
		return ;
	}

	cout<< queu[front+1]<<endl;
}
void pop()
{	
	if( rear == front)
	{	
		rear = -1;
		front = -1; 
		cout<<" empty" << endl; 
	}
	front ++ ; 
	front = (front % 100);

}
void isempty()
{
	front == rear ? cout<< "empty" << endl : cout<< "no_empty"<<endl ;
}



int main()
{	
	isempty();
	push(5);
	push(8); 
	isempty();
	peek(); 
	pop();

	peek();
}



