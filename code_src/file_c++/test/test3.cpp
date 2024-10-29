#include<iostream>

using namespace  std; 

struct node 
{
   int data; 
   node * next; 
}; 

void   insert(node * root, int data, int index)
{
      if( root == NULL)
      {
         root = new node; 
         root -> data = data;
         root -> next = NULL ; 
         
      }
      else 
      {
           index  -- ; 
           node * p = root; 
         while( index -- )
         {
            p = p -> next; 
         }
         node * temp = p ->next; 
         p-> next = new node; 
         p->next ->data = data ; 
         p->next -> next = temp ; 
         


      }
}

void add(node * &  root , int data)
{
   node * p = root ; 
    if( root == NULL)
      {
         root = new node(); 
         root -> data = data;
         root -> next = NULL ; 
         return ; 
      }
   while(  p -> next != NULL)
   {
      p = p ->next; 
   }
   p ->next =new node; 
   p->next ->data = data; 
   p->next -> next = NULL ;
}


void erase( node * & root, int index)
{
   node * p  = root; 
   if( index == 1)
   {
      root = root ->next;
      return  ;
   }
   index -- ; 
   while(  -- index )
   {
      p = p ->next; 
   } 
   p ->next = p ->next ->next; 
   
}


void print_( node  * root )
{
   node * p = root  ;  
   while( p != NULL)
   {
      cout << p  ->  data <<" "; 
      p = p -> next; 
   }
}


int main()
{
   node * root = NULL ; 

   add( root , 2) ; 
   add ( root , 4);
   insert( root, 5, 1);
   insert(root, 7, 1);
 
   print_(root ); 

}


