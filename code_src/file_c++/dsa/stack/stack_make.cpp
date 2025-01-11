#include<iostream>
using namespace std; 

struct node 
{
   int data;
   node* next; 
   node* pre;
};
class stack_make
{
   public:
      node * peek = NULL ;
   void push(int data)
   {
      node * temp = new node ;
      temp ->data = data ;
      temp ->pre = peek ;
      if(peek != NULL)
      {
         peek ->next = temp ;
      }
      peek = temp ;

   }
   void pop()
   {
      if(peek != NULL)
      {
        
         peek = peek ->pre ;
         if(peek != NULL) //  stack  rỗng -> không làm gì  
         peek ->next = NULL ;
         return ;
      }
      cout<<"empty"<<" ";
   }
   void top()
   {
      if( peek != NULL)
      {
         cout<<peek ->data<<endl;return ;
      } 
      cout<<"empty"<<" ";
   }
   void is_empty()
   {
      cout<< (peek == NULL);
   }
   
};


int main()
{
   stack_make st;
 
   
   st.pop();
   st.top();
}