#include<iostream>
using namespace std;

void heapify(int a[], int n , int index)
{  //maxheap
   int l = index *2 +1; // node con trái 
   int r = index *2 +2; // node con phải 
   int largest_index = index; // index là node cha 
   if( l < n && a[l] > a[largest_index])// so sánh 2 node con với node cha
   {
      largest_index = l ;
   }
   if( r < n && a[r] >a[largest_index] ) // có thể để dấu "<" => minheap
   {
      largest_index = r ; 
   }
   if( largest_index != index) // tại sao cần != node cha 
   {                           // nếu ko sẽ lại gọi heapify với index cũ 
      swap( a[largest_index], a[index]);

      heapify(a,n, largest_index);// khi đảo node to nhất lên trên sẽ thay đổi node dưới 
      // có thể node index(cha) bé hơn node con của largest_index(con của con )
   }

}

int main()
{  int n = 10;
  int a[n]= { 1 ,4 ,5 ,6 ,9 ,205 ,1 ,4 ,2,10};

   for( int i = n/2 -1; i>=0 ; i--)// tại sao lại là n/2 -1 ? 
   {                               // vì là node cuối cùng có node con 
      heapify(a,n,i);
   }
   for(auto i : a)
   {
      cout<< i<<" ";
   }

}