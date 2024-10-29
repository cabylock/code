#include<iostream>
using namespace std ;

struct node 
{
   int data  ; 
   node* next ;
};

class queue
{
   public:
      node* head  = NULL ;
   void push(int data)
   {
      node* temp = new node ;
      temp ->data = data ;
      temp ->next = head; 
      head = temp ;
   }

   void pop()
   {
      if( head!= NULL)
      {  
         
         head = head ->next ;return ;
      }
      cout<< "empty"<<" ";
   }
   void front()
   {
      if(head != NULL)
      {
         cout<<head ->data<<endl;return ;
      }
      cout<<"empty"<<" ";
   }
   void is_empty()
   {
      cout<<(head == NULL);
   }

};

int main()
{
   queue q;
  
  q.push(5);

   q.pop();
   q.front();
}
