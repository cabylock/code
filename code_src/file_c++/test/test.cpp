#include<iostream>
using namespace std; 

struct llist
{   
    string Name ; 
    string Class ; 
    llist * next; 

};

llist* student[10000] = { NULL };




int hash_function(int data)
{
    return data% 10000; 
}

void insert(  int id , string Name , string Class  )
{
    int hash_key = hash_function(id); 

    if( student[hash_key]  == NULL)
    {
        llist * temp  = new llist ; 
        temp ->Class =Class; 
        temp -> Name= Name; 
        temp ->next = NULL ; 
        student[hash_key]= temp ;

    }
    else 
    {
         llist * temp  = new llist ; 
        temp ->Class =Class; 
        temp -> Name= Name; 
        temp ->next = student[hash_key] ;
        student[hash_key] = temp ;  
    }

}

void infor(int id)
{   
    if( student[hash_function(id)] == NULL)
    {
        
        cout<<"NA,NA"<<endl;
        return; 
    }
    cout<< student[hash_function(id)]->Name<<","
    <<student[hash_function(id)]->Class<<endl;

}

void Delete(int id)
{
    student[hash_function(id)]= student[hash_function(id)]->next; 
    
}

int main()
{   
    insert(1,"Tuan", "K61CS");

    insert(2,"Vinh","K43C"); 

    infor(3);

    insert(10001,"Vinh","jfjfjfj"); 

    infor(2);

    Delete(2);
    infor(2);
    infor(1);

}

