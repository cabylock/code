#include<iostream>
using namespace std;

void heapify_down(int a[], int n , int index)
{  // dùng cho xóa phần tử lớn nhất bằng cách swap với node 0 và sau đó heapify_down lại
   int largest_index = index ;//node cha
   int l = 2*index +1 ;//node con trái
   int r = 2 *index +2; //node con phải

   if( a[l] > a[largest_index] && l <n) // tìm node lớn nhất trong 3 ndoe
   {
      largest_index = l;
   }
   if ( a[r] > a[largest_index] && r < n )
   {
      largest_index = r ;
   }
   if( index != largest_index) // tại sao phải khác node cha? => vì sẽ gọi lại index =node cha
   {
   swap( a[index], a[largest_index]);
   heapify_down(a, n, largest_index);// gọi lại hàm với node con vì node con có thể bé hơn node con của nó
   }

}

void heapify_up( int a[], int n , int index)
{
   int parent = (index-1)/2;//node cha
   if( a[parent] < a[index] && parent >= 0) // nếu node cha nhỏ hơn node con thì swap
   {
      swap( a[parent], a[index]);
      heapify_up( a, n, parent);// gọi lại hàm với node cha vì node cha có thể lớn hơn node cha của nó
   }
   
}


int main()
{  int n = 10;
  int a[n]= { 1 ,4 ,5 ,6 ,9 ,205 ,1 ,4 ,2,10};
  
  for( int i = 1; i < n ; i++)
   {
       heapify_up(a, n, i);
   }
   for ( int i = n/2 -1 ; i >= 0 ; i--)
   {
      heapify_down(a, n, i);
   }


   for( auto i : a )
   {
      cout<< i<<" ";
   }

}