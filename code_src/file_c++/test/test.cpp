#include<iostream>
using namespace std; 

struct llist
{   
    string Name ; 
    int id; 
    string Class ; 
    llist * next; 

};

llist* student[10000] = { nullptr };




int hash_function(int id)
{
    return id% 10000; 
}

void insert(  int id , string Name , string Class  )
{
    int hash_key = hash_function(id); 

    if( student[hash_key]  == nullptr)
    {
        llist * temp  = new llist ; 
        temp ->Class =Class; 
        temp -> Name= Name; 
        temp->id = id; 
        temp ->next = NULL ; 
        student[hash_key]= temp ;

    }
    else 
    {
         llist * temp  = new llist ; 
        temp ->Class =Class; 
        temp -> Name= Name;
        temp->id = id;  
        temp ->next = student[hash_key] ;
        student[hash_key] = temp ;  
    }

}

void infor(int id)
{   
    llist * temp = student[hash_function(id)]; 
    while( temp != nullptr && temp->id != id  )
    {
        temp =temp->next;
    }
    if( temp == nullptr)
    {
        
        cout<<"NA,NA"<<endl;
        return; 
    }
    else 
    {
        cout << temp->Name<<","<<temp->Class<<endl; 
    }
}

void Delete(int id)
{
    llist *temp = student[hash_function(id)];
    if (temp == NULL)
    {
        return ;
    }
    if (temp->id == id)
    {
        student[hash_function(id)] = temp->next;
    }
    else 
    {
        while (temp->next != NULL && temp->next->id != id)
        {
            temp = temp->next; 
        }
        if (temp->next == NULL)
        {
            temp = temp->next; 
        }
        else 
        {
            temp->next = temp->next->next ;
        }
    }
}

int main()
{   
    insert(1,"Tuan", "K61CS");

    insert(2,"Vinh","K43C"); 

    infor(3);
    
    infor(2);
    Delete(2);
    infor(2);
   
    

}

