#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<cstring>

#include<bits/stdc++.h>
using namespace std;


struct linked_list
{
    int data;
    linked_list* next;
};


int main()
{   
  
      linked_list* head ;
      head = new linked_list;
      if(head != NULL)
      {
          cout<<"Memory not allocated";
          return 0;
      }
   
}