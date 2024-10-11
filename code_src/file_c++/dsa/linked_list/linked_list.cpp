#include<iostream>
using namespace std; 

struct node
{
   int data;
   node* next;
};

class linked_list
{
   public:
   node*head; 
   linked_list()
   {  //constructor
      head = NULL ;
   }
   // thêm vào cuối 
   void insert_tail (int data)
   {
      node * p = head ;
      if( p == NULL) // kiểm tra rỗng 
      {
         head = new node ; 
         head ->data = data;
         head ->next = NULL; 
      }
      else 
      {
         while( p ->next != NULL)
         {
             p = p ->next;
         }
         p->next =new node ;
         p->next->data = data;
         p->next->next = NULL ;
      }
   }
   // thêm  vào vị trí xác định 
   void insert_index(int data, int index)
   {  
      if(index == 0)// trường hợp thêm vào đâu
      {
         insert_head(data);
         return ; 
      }
      node *p = head ; 
      for(int i = 0 ; i< index -1 && p != NULL ; i++)
      {
         p = p->next;
      }
       if(p == NULL)
         {
            cout<< "invalid index "; return ;
         }
      node* temp = new node ; 
      temp ->data = data ;
      temp ->next = p->next;
      p->next = temp ; 

   }

   // thêm vào đầu 
   void insert_head(int data)
   {
      node *p = head; 
      head = new node ; 
      head ->data =data; 
      head ->next = p ; 
   }

   // kiểm tra rỗng 
   void is_empty()
   {
      cout<<( head == NULL)<<" " ;
   }
   // tìm kiếm 
   void search(int data)
   {     
      int res = 0;  // tính từ vị trí 0 ; 
      node * p = head ; 
      while( p != NULL)
      {
        if(p ->data == data)
        {
         cout<< res <<" " ;
         return ;
        } 
         p = p ->next ; 
         res ++ ;
      }
      cout<<"Not found" ; 
   }

   // duyệt 
   void print_()
   {
      node * p = head ; 
      while( p != NULL)
      {
         cout<< p->data <<" "; 
         p= p->next; 
      }
   }

   // truy xuất 
   void index(int index)
   {  
      node *p = head; 
      while( index -- )
      {
         if( p ->next == NULL)
         {
            cout<<"invalid index" <<"\n";
            return ; 
         }
         p = p ->next;
      }
      cout<< p ->data<<" " ;
   }

   void delete_head()
   {  if( head != NULL) // trường hợp 0 node 
      head= head ->next;
   }
   void delete_tail()
   {  
      if(head == NULL) return ; // trường hợp 0 node 
      node *p = head; 
      if( p ->next == NULL) // trường hợp 1 node 
      {
         head = NULL ;
      }
      while( p ->next ->next !=NULL )
      {
         p = p->next;
      }
      p -> next =NULL ;
   }
   void delete_index(int index) 
   {
      node *p = head; 
      if(index == 0) // trường hợp xóa đầu 
      {
        delete_head();
         return ;
      }
      for(int i = 0 ; i<= index -1  && p != NULL ;i ++)
        {
         p = p->next;
        }
        if( p == NULL) 
        {
         cout<< "invalid index "; return ;
        }
        if( p ->next == NULL) // trường hợp node cuối 
        {
         delete_tail();return ;
        }
      p ->next = p->next->next;
   }

};


int main()
{
   linked_list a ; 
   a.insert_head(6);
   
   a.insert_tail(5) ;
   a.insert_tail(3) ;
   // a.insert_index(4 ,4);
   
   a.delete_index(2);
   a.print_();
}

