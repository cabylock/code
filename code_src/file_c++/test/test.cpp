#include<iostream>
using namespace std;

struct node 
{
    int data ; 
    node* next; 
};

class list_node 
{
    public: 
        node * head ; 
    list_node()
    {
        head =new node ; 
        head -> next =NULL ;
    }
    
    void insert(int x )
    {
        node * p  = head ; 
        while( p ->next  != NULL)
        {
            p = p->next;
        }
        node * a = new node ;
        a-> data =x; 
       a->next = NULL;
       p->next  =a ; 
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
                cout<< "empty";
            }
        }
        return p->data; ; 
    }

};

int main()
{   

    list_node a ; 
    a.insert(5); 
    a.insert(6) ;
    a.print_list();
    cout<< endl ;
    cout<< a.search(5) ;

}