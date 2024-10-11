#include<iostream>
#include<vector>
#include<stack>

using namespace std ;
struct node 
{
        int data; node* next ;
};

int main()
{
   node * head = new node ; 
   head ->data = 5 ;
   head ->next =new node ;
   head->next->data = 4 ;
   head ->next ->next = NULL ;

    node *k = head; 
    k = k->next; 
    delete k ;

    node * p = head; 
    while( p != NULL)
    {
        cout<< p ->data <<" " ; 
        p = p ->next;
    }
  
}