#include<bits/stdc++.h>
using namespace std;


struct linked_list
{
    int data;
    linked_list* next;
};


void printLinkedList(linked_list* head) 
{
    while( head  != NULL)
    {
        cout<< head->data << endl;
        head = head->next;
    }
}

int main()
{
      int n ;cin >> n ;
      linked_list* head ; 
      head = new linked_list;
      head->next = NULL;
      linked_list* tail = head;
      
      for(int i = 0 ; i< n ; i++)
      {
         int x ; cin >>x ; 
         tail->data = x;
         if(i == n-1) break;
         tail->next = new linked_list;
         tail = tail->next;
         tail->next = NULL;
       
        
      }
      

      printLinkedList(head);





}