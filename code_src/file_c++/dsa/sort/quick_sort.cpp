#include<iostream>

using namespace std;

int pivot( int a[] , int l , int r)
{  // 1 9 1 3 
   int i = l ;  //i là vị trí đổi chỗ 
   int pivot = a[r]; // chọn pivot là phần tử cuối của đoạn 
   for ( int j = l ; j <r  ; j++)
   {
      if(a[j]  <= pivot  ) // nếu > pivot thì ko đổi  => i +1 luôn là vị trí thỏa mãn để đổi với a[j]
      {                    // nếu <= thì tự đổi với chính minh => ko thay đổi j 
         swap( a[j], a[i]);
         i ++ ;
      }
   }
   swap( a[ i], a[r]); // đổi pivot vào giữa đoạn
   return i ; // trả về vị trí pivot 

}

void quicksort( int a[], int l , int r )
{
   if( l < r ) // l =r có 1 phần tử thì ko cần 
   {  
      int p = pivot(a, l, r );
      quicksort( a,l, p-1 ); // nếu cho quicksort(a, l, p) thì khi đoạn có 2 phần tử thì p = vị trí thứ 2 
                           // p không đổi  => lặp vô hạn 
      quicksort( a, p+1 , r);
   }

}

int main()
{
   int a[11]= { 1 ,4 ,5 ,2000,6 ,9 ,205 ,1 ,4 ,2,10};

   quicksort( a, 0 , 10 );
   for ( auto i : a )
   {
      cout << i <<" ";
   }

}