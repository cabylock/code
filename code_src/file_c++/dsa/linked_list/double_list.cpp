#include<iostream>

using namespace std; 

struct node 
{
   int data; 
   node  * next; 
   node * pre; 
};

class db_list
{
   public : 
   node* head = NULL ;
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
   //truy xuất 
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
   // thêm vào cuối 
   void insert_tail(int data)
   {
      node * p = head; 
      if( p  ==NULL) // trường hợp 0 node 
      {
         head= new node ; 
         head ->pre = NULL ;
         head ->next = NULL;
         head ->data =data;
         return   ; 
      }
      while( p ->next != NULL)
      {
         p = p->next;
      }
      p->next =new node; 
      p->next -> data =data;
      p->next ->pre = p ;
      p->next ->next = NULL;

   }
   //thêm vào đầu 
   void insert_head(int data)
   {
      node* p = head ; 
      head = new node;
      head ->data = data;
      head ->pre = NULL ;
      head ->next = p ; 
      if(p != NULL) // thêm vào node không rỗng
      p->pre = head; 
   }
   // thêm vào vị trí  index
   void insert_index (int  data, int index)
   {
      if(index == 0)
      {
         insert_head(data);
      }
      else 
      {  
         
         node *p = head; 
         
         for(int i = 0 ; i< index -1 && p != NULL; i++)
         {
            p = p->next; 
         }
         if(p == NULL)
         {
            cout<< "invalid index "; return ;
         }
         node * temp = new node; 
         temp ->pre= p ;
         temp->data = data;
         temp ->next = p->next;
         p->next =temp ;
      }
   }
   // xóa ở đầu 
   void delete_head()
   {  
      if(head != NULL) // trường hợp 0 node
      head= head -> next;
   }
   // xóa ở cuối 
   void delete_tail()
   {  
      if(head == NULL) return; //trường hợp rỗng
      node *p = head; 
      if( p->next == NULL) // trường hợp 1 node
      {
         head = NULL;
         return ;
      }
      while( p ->next != NULL)
      {
         p= p->next;
      }
      p->pre ->next= NULL;
   }
   //xóa ở vị trí index 
   void delete_index(int index)
   {
      if(index == 0)
      {
         delete_head();
      }
      else 
      {  
         node* p = head; 
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
         p->pre->next = p ->next;
         p->next->pre = p->pre; 
      }
   }
   //kiểm tra rỗng 
   void is_empty()
   {
      cout<< ( head ==NULL)<<" " ; 
   }
   void print_()
   {
      node* p = head; 
      while( p != NULL)
      {
         cout<< p->data<< " " ; 
         p= p->next;
      }
   }
   
};

int main()
{

   db_list a ;
   a.insert_head(6);
   a.insert_index(5,1);
   a.insert_tail(7);
   a.insert_head(4);
   

   a.search(8 );
   a.print_();

}

