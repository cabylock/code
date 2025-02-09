#include<iostream>
using namespace std; 

struct node 
{
        int data; 
        node * left ; 
        node * right ; 
};

node * insert(node * root , int data)
{
        if( root == NULL)
        {
                node * a =new node;
                a->data = data;
                a->left = NULL;
                a->right = NULL;
                return a; 
        }
        else 
        {
                if( root -> data > data)
                {
                        root->left= insert(root -> left, data);
                }
                else 
                {
                        root->right = insert( root->right, data);
                }
        }
        return root;
}

void print_(node *  root)
{       
        if( root == NULL)
        {
                return ;
        }
        print_(root->left);
        cout<< root->data <<" ";
        print_(root->right);
}

node* erase(node * root, int data)
{       
        if( root == NULL)
        {
                return NULL;
        }
        if( root->data == data )
        {
              if( root ->right == NULL & root ->left == NULL)
              {
                return NULL; 
              }
              else if ( root -> left == NULL)
              {
                root->right = root->right ->right;
              }
              else if( root ->right == NULL)
              {
                root->left = root ->left ->left; 
              }
              else 
              {
                node * p =root->left;
                while( p ->right != NULL)
                {
                        p= p ->right;
                }
                swap( p->data, root->data);
                root->left=  erase(root->left,data);
              }           
        }
        else if( root -> data > data)
        {
                root->left = erase(root->left, data);
        }

        





        return root;

}



int main()
{
        node * tree ; 
        tree =NULL;
        tree =  insert(tree, 5);
        tree =insert(tree, 10);
        tree = insert(tree , 3);
        tree= erase(tree, 5);
        print_(tree);
}