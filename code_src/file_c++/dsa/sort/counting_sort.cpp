#include<iostream>

using namespace std;

int main()
{
   int a[10]= { 1 ,4 ,5 ,6 ,9 ,205 ,1 ,4 ,2,10};
   // đếm số lần xuất hiện của các phần tử trong mảng
   // sau đó in ra 
   // mảng lớn quá thì không thể sử dụng counting sort
   // mảng có giá trị âm thì không thể sử dụng counting sort

   int b[205+1] = {0};
   for( int i =0 ; i< 10; i++)
   {
      b[a[i]]++; // đếm số lần bằng mảng đếm 
   }

   for( int i =0 ; i< 205+1; i++)
   {
      if(b[i] > 0) // check có phần tử đó ko 
      {
         for( int j =0 ; j< b[i]; j++)
         {
            cout<<i<<" "; // in ra nhưng mảng a ko thay đổi 
         }
      }
   }





}