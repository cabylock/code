#include<iostream>

using namespace std;

void merge(int a[], int l , int m , int r )
{  
   int n1 = m-l+1;// độ dai mảng trái
   int n2 = r-m; // độ dài mảng phải
   int L[n1], R[n2]; // tạo 2 mảng trái phải để lưu giá trị 
   for(int i = 0; i < n1; i++)
   {
      L[i] = a[l+i];// copy vào mảng trái 
   }
   for(int i = 0; i < n2; i++)
   {
      R[i] = a[m+1+i]; // copy vào mảng phải
   }
   int i = 0; // vị trí của mảng trái
   int j = 0; // vị trí mảng phải 
   int k = l; // k : vị trí để điền giá trị từ mảng L,R vào 
   while(i < n1 && j < n2) // trộn đến khi nào 1 trong 2 mảng hết
   {                         // nếu phần tử nào nhỏ hơn thì đưa vào mảng a
      if(L[i] <= R[j])
      {
         a[k] = L[i];
         i++;
      }
      else
      {
         a[k] = R[j];
         j++;
      }
      k++;
   }
   while(i < n1) // trường hợp một mảng hết một mảng còn 
   {
      a[k] = L[i];
      i++;
      k++;
   }
   while(j < n2)
   {
      a[k] = R[j];
      j++;
      k++;
   }
}

void merge_sort(int a[], int l, int r)
{
   if(l < r)
   {
      int m = (l+r)/2;
      merge_sort(a,m+1,r);
      merge_sort(a,l,m);
      // [l, m] [m+1, r] đã được sắp xếp
      merge(a,l,m,r); //=> trộn 2 mảng đã sắp xếp
   }
}
int main()
{
   int a[10]= { 1 ,4 ,5 ,6 ,9 ,205 ,1 ,4 ,2,10};
   merge_sort(a,0,9);
   for( auto i : a )
   {
      cout<< i<<" ";
   }

}

