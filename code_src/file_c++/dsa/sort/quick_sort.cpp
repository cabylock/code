#include<iostream>

using namespace std;

int hoare(int a[], int l, int r )
{ 
  int pivot = a[(l+r)/2]; // chọn pivot là phần tử giữa của đoạn
  int i = l;int j = r;
  while( i <= j )
  {
    while( a[i] < pivot ) i++;// tìm phần tử >= pivot bên trái
    while( a[j] > pivot ) j--;// tìm phần tử <= pivot bên phải
    if( i <= j )
    {
      swap( a[i], a[j]);//ko quan trọng pivot bị đổi chỗ 
      i++;
      j--;
    }
  }
   return i;// vị trí pivot mới -> đoạn [l, i-1] < pivot cũ <= [i, r] 
}


int lomuto( int a[] , int l , int r) // phân hoạch lomuto => pivot = end element
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
      int p = hoare(a, l, r );
      quicksort( a,l, p-1 ); // nếu cho quicksort(a, l, p) thì khi đoạn có 2 phần tử thì p = vị trí thứ 2 
                           // p không đổi  => lặp vô hạn 
      quicksort( a, p , r);// nếu dùng lomuto => quicksort( a, p+1, r) / quicksort( a, p, r-1) do phần tử pivot đã đúng vị trí
                           // nếu dùng hoare => quicksort( a, p, r) do pivot chưa đúng vị trí
   }

}

int main()
{
   int a[11]= { 1 , 10 , 4 ,5 , 9 ,19, 8,14, 7,6,8};
   // int b[4] = { 1, 9, 1, 3};
   quicksort( a, 0, 10);
   for ( auto i : a )
   {
      cout << i <<" ";
   }

}