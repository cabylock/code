#include<iostream>

using namespace std;

int main()
{
   int a[10]= { 1 ,4 ,5 ,6 ,9 ,205 ,1 ,4 ,2,10};
   // vòng lặp i  chạy từ 1 đến n-1
   // các phần tử từ 0 đến i-1 đã được sắp xếp
   // nếu  a[i] < a[j] thì dịch phải a[j] và gán a[j+1] = a[i]
   // sau đó gán a[j+1] = a[i]

   for( int i =1 ;i < 10; i++)
   {
        int temp = a[i] ;
        int j = i-1;
        while( j>=0 && temp < a[j]) // j>=0 trường hợp j = 0
        {
         a[j+1]= a[j];
         j--;
        }
        a[j+1] = temp;
   }
   for( int i =0 ; i< 10 ; i++)
   {
      cout<<a[i]<<" ";
   }

}