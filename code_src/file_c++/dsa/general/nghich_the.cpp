#include<iostream>

using namespace std;

int  merge(int a[], int l , int m , int r )
{
   int n1 = m-l+1;// độ dai mảng trái
   int n2 = r-m; // độ dài mảng phải
   int L[n1], R[n2]; // tạo 2 mảng trái phải để lưu giá trị 
   int count = 0 ;
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
   while(i < n1 && j < n2) // xét từng phần tử của mảng trái và phải
   {                         // nếu phần tử nào nhỏ hơn thì đưa vào mảng a
      if(L[i] <= R[j])
      {
         a[k] = L[i];
         i++;
      }
      else
      {  count += n1 -i ;
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
   return count;
}

int merge_sort(int a[], int l, int r)
{  int count = 0 ;
   if(l < r)
   {
      int m = (l+r)/2;
      count += merge_sort(a,l,m);
      count += merge_sort(a,m+1,r);
      count += merge(a,l,m,r);
   }
   return count ;
}
int main()
{
   int a[10]= { 1 ,4 ,5 ,6 ,9 ,205 ,1 ,4 ,2,10};
   
   cout<<merge_sort(a,0,9);
}

