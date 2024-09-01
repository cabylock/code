#include<iostream>
using namespace std;

int main()
{  int l = 4;
   int r=4 ; 
   int a[4] ={ 1, 2, 4,6};
   int b[4]= { 3,5,8,9};

   int i = 0; int j =0;
   while( i< l || j<r)
   {  
      
      if( i>=l)
      {
         cout<<b[j]<<" ";
         j++;
      }
      else if ( j>=r)
      {
         cout<<a[i]<<" ";
         i++;
      }
      else 
      {

         if(a[i] < b[j])
         {
            cout<<a[i]<<" ";
            i++;
         }
         else
         {
            cout<<b[j]<<" ";
            j++;
         }
      }
   }



}