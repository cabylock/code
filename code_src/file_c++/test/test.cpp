#include<iostream>
using namespace std;

struct node 
{
    int data ; 
    node* next; 
};

class list_node 
{
    private: 
        node * head ; 
    public: 
    list_node()
    {
        head =new node ; 
        head ->data = 0 ; 
        head -> next =NULL ;
        //head = NULL; 
    }
    
    void insert_tail(int x )
    {
        node * p  = head ; 
        while( p ->next  != NULL)
        {
            p = p->next;
        }
        node * a = new node ;
        a-> data =x; 
       a->next = NULL;
       p  -> next =a ; 
    }
    void insert(int x, int index  )
    {
       node * p = head ; 
       index -- ;
       while(index -- )
       {
          if( p == NULL)
          {
            return ; 
          }
          p = p ->next;
       }
       node * a = new node ; 
       a->data = x; 
       a->next =p ->next ;
        p ->next =a  ;
        
    }


    int search(int x )
    {   
        int pos = 0 ; 
        node * p = head ; 
        while( p != NULL )
        {
            if( p-> data == x)
            {
                return pos ; 
            }
            p= p->next; 
            pos++ ;
        }
        return false; 
    }
    void print_list()
    {
        node *p = head; 
        
        while( p!= NULL)
        {
            cout<< p->data << " ";
            p=p->next;
        }
    }
    int get_val(int x ) 
    {   
        node* p = head; 
        while( x --)
        {
            if( p != NULL)
            {
                p = p->next;
            }
            else 
            {
                return  -1 ;
                
            }
        }
        return p->data; ; 
    }

};

int main()
{   

    list_node a ; 
    a.insert_tail(5); 
    a.insert_tail(6) ;
    a.insert(7, 1);
    a.print_list();
    cout<< endl ;
    cout<< a.get_val(2) ;

}