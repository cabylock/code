#include<iostream>
using namespace std; 

struct llist
{   
    string Name ; 
    int id; 
    string Class ; 
    llist * next; 

};

struct student
{
    int id; 
    string Name ; 
    string Class ; 
};

class bucket 
{
    private:
    llist* school[10000] = { NULL };

    int hash_function(int id)
    {
        return id% 10000; 
    }
    public: 

    void insert(  int id , string Name , string Class  )
    {
        int hash_key = hash_function(id); 

        if( school[hash_key]  == NULL)
        {
            llist * temp  = new llist ; 
            temp ->Class =Class; 
            temp -> Name= Name; 
            temp->id = id; 
            temp ->next = NULL ; 
            school[hash_key]= temp ;

        }
        else 
        {
            llist * temp  = new llist ; 
            temp ->Class =Class; 
            temp -> Name= Name;
            temp->id = id;  
            temp ->next = school[hash_key] ;
            school[hash_key] = temp ;  
        }

    }

    void infor(int id)
    {   
        llist * temp = school[hash_function(id)]; 
        while( temp != NULL && temp->id != id  )
        {
            temp =temp->next;
        }
        if( temp == NULL)
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
        llist *temp = school[hash_function(id)];
        if (temp == NULL)
        {
            return ;
        }
        if (temp->id == id)
        {
            school[hash_function(id)] = temp->next;
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


};

class openaddress
{
    public:
    student school[10000] ={0} ;
    // id = -1 : empty, id = 0 : deleted
    int hash_function(int id)
    {
        return id% 10000; 
    }
    public: 

    void insert(  int id , string Name , string Class  )
    {
        int key = hash_function(id); 

        if( school [key].id <= 0 )
        {   
            school[key].id = id;
            school[key].Name = Name;
            school[key].Class = Class;

        }
        else 
        {   
            int count = 0;
            while( school[key].id > 0 )
            {
                key = hash_function(key + 1);   count ++ ; 
                if (count == 10000)
                {
                    return;
                }

            }
            school[key].id = id;
            school[key].Name = Name;
            school[key].Class = Class;

        }
    }

    void infor(int id)
    {   
        int key = hash_function(id); 
        int count = 0;
        while( school[key].id != id && school[key].id >= 0 )
        {
            key = hash_function(key + 1);
            count++;
            if (count == 10000)
            {
                cout<<"NA,NA"<<endl;// not found
                return;
            }
        }
        cout << school[key].Name<<","<<school[key].Class<<endl;
    }

    void Delete(int id)
    {
        int key = hash_function(id); 
        int count = 0;
        while( school[key].id != id && school[key].id >= 0 )
        {
            key = hash_function(key + 1);
            count++;
            if (count == 10000)
            {
                return;// not found
            }

        }
        if( school[key].id <= 0)
        {
            return; 
        }
        else 
        {
            school[key].id = 0;
        }
    }

};


int main()
{       
    openaddress a; 
    a.insert(1,"Tuan", "K61CS");


    a.insert( 3,"Hai","K61CS");
    
    a.infor(1);
    a.Delete(1);
    
    
    a.infor(3);

   

}

