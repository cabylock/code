#include<iostream>
using namespace std;

void merge( int a[], int l ,int p ,  int r )
{
   int left[p-l]; 
   int right[r-p+1];
   
   for(int i = 0 ; i< p; i++)
   {
      left[i] = a[i+l];
   }
   for(int j = 0 ; j< r-p+1 ; j++)
   {

      right[j] = a[j+p ]; 
   }
   int i = 0, j= 0 ; 
   int index = l ; 
   while( i< p-l && j <r-p+1)
   {
      if( left[i] < right[j])
      {
         a[index++] = left[i++];
      }
      else 
      {
         a[index++] = right[j++];
      }
   }
   while( i < p-l)
   {
      a[index++]  =left[i++];
   }
   while( j < r-p+1)
   {
      a[index++] = right[j++];
   }
   
}

void merge_sort(int a[], int l, int r )
{
   int p = (l+r)/2; 
   if( l< r )
   {  
      cout<< l<<" "<<p<<" "<<  r <<endl ; 
      merge_sort (a, l , p );
      merge_sort(a, p+1, r );
      merge(a, l , p, r);
   }

}

int main()
{

   int n ;cin >> n ;
   int a[n];
   for(int i = 0 ; i< n; i++)
   {
      cin >> a[i];
   }
   merge(a, 0 , 2 , 4 );
   for(auto i : a)
   {
      cout<< i <<" ";
   }


}