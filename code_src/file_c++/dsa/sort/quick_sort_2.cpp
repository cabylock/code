#include<iostream>
using namespace std;

void quick(int a[], int l, int r)
{
   int pivot = a[(l+r)/2];
   int i = l; int j = r;
   while( i<= j)
   {
      while( a[i] < pivot) i++;
      while( a[j] > pivot) j--;
      if( i <= j)
      {
         swap( a[i], a[j]);
         i++;
         j--;
      }
   }
   //j là vị trí cuối cùng của phần tử nhỏ hơn pivot
   //i là vị trí đầu tiên của phần tử lớn hơn pivot
   if( l < j) quick(a, l, j); 
   if( i < r) quick(a, i, r);
}


int main()
{     // 1 4 5 6 2 205 1 4 9 10
      //1 4 5 6 2 4 1 205 9 10
   int n =10 ;
   int a[n]= { 1 ,4 ,5 ,6 ,9 ,205 ,1 ,4 ,2,10};
   quick(a, 0, n-1);
   for( auto i : a )
   {
      cout<< i<<" ";
   }


}