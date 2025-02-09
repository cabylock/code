#include<iostream>
using namespace std;

struct node 
{
   int data; 
   node *left;
   node *right;
   int height;

};

int height(node * n)
{  
   if( n == NULL)
   {
      return 0;
   }
   return n->height;
}

node* right_rotate(node * root)
{
   node * temp = root->left;
   root->left = temp->right;
   temp->right = root;
   root->height = 1 + max(height(root->left), height(root->right))   ;
   temp->height = 1 + max(height(temp->left), height(temp->right));


   return temp;
}

node *left_rotate(node * root)
{
   node* temp = root->right;
   root->right = temp ->left;
   temp->left = root;
   root->height = 1 + max(height(root->left), height(root->right));
   temp->height = 1 + max(height(temp->left), height(temp->right));

   return temp;

}

node* rotate(node * root,int data)
{
   // balance = left -right 
   int balance = height(root->left) - height(root->right);
   //left left
   if(balance >1  && height(root->left->left) >= height(root->left->right))
   {
      return right_rotate(root);
   }
   //right right

   if( balance <-1 && height ( root ->right ->right ) >= height(root->right->left))
   {
      return left_rotate(root);
   }

   //left right
   if( balance >1  && height(root->left->right)  > height(root->left->left)  )
   {
     root->left= left_rotate(root->left);
       return right_rotate(root);
   }

   // right left 
   if( balance <-1 &&height ( root ->right ->right ) < height(root->right->left))
   {
      root->right = right_rotate(root->right);
      return left_rotate(root);
   }
   return root;
}


node* insert(node * root, int data)
{
   if( root == NULL) // chưa có node nào
   {
     node* a = new node; 
     a->data = data;
     a->left = NULL;
      a->right = NULL;
      a->height = 1;
         return a;
   }
   else 
   {
      if( root->data > data) //sang bên phải
      {
         root->left = insert(root->left, data);
      }
      else // sang bên trái
      {
         root->right = insert(root->right, data);
      }
   }
   root->height = 1 + max(height(root->left), height(root->right));
   
   root = rotate(root, data); //xoay lại cây
   return root;

}

node * erase(node * root, int data)
{  
   if( root == NULL)// node rỗng
   {
      return NULL;
   }
   if( data < root->data) //tìm bên trái
   {
      root->left = erase(root->left, data);
   }
   else if( data > root->data) //tìm bên phải 
   {
      root->right = erase(root->right, data);
   }
   else // tìm thấy 
   {
      if( root->left == NULL && root->right == NULL) // node lá
      {
         return NULL;
      }
      else if( root->left == NULL) //node 1 con
      {
         return root->right;
      }
      else if( root->right == NULL) //node 1 con
      {
         return root->left;
      }
      else //node 2 con
      {
         node * temp = root->right;
         while( temp->left != NULL)
         {
            temp = temp->left;
         }
         root->data = temp->data;
         root->right = erase(root->right, temp->data);
      }
   }
   root->height = 1 + max(height(root->left), height(root->right));
   
   root = rotate(root, data); // xoay lại cây 


   return root;

}


void bfs( node* root)
{
   node* q[100];
   int i = 0 ;
   int j = 0 ;
   if(root == NULL)
   {
      return ;
   }
   q[j++] = root;

   
   while( i < j)
   {
      node * temp = q[i++];
      if( temp->left != NULL)
      {
         q[j++] = temp->left;
      }
      if( temp->right != NULL)
      {
         q[j++] = temp->right;
      }
   }
  
   for(int k = 0 ; k < j ; k++)
   {
      cout<< q[k]->data <<" ";
   }
   cout<<endl;

}

int main()
{

   node * root= NULL; 

   root = insert(root, 1);
   root = insert(root, 2);
   root= insert(root, 3);
   root = insert(root, 4);
   root = insert(root, 5);
   root = insert(root, 6);
   root = insert(root, 7);
   root = insert(root, 8);
   root = insert(root, 9);
   root = insert(root, 10);

   
   bfs(root);
   root= erase (root, 5);
   root= erase (root, 8);
   bfs(root);
}






