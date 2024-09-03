#include<iostream>
#include<map>

using namespace std;

void ckn(int a[10],int n, int k)
{  //tổ hợp k phần tử của 1 tập n phần tử
   // các số tăng dần ,ko lặp lại
   int i =k;//i là vị trí cần tăng // tính từ 1
   while( i > 0 && a[i] == n-k+i)// n-k+i là giá trị lớn nhất mà a[i] có thể đạt được
   {
       i--;
   }
   if( i == 0)// nếu i = 0 -> tất cả vị trí đều là lớn nhất
   {
      return;
   }
   else 
   {  //6c4   
      // ví dụ 1235 -> 1236 (i = 4 )
      // 1236 -> 1245 (i = 3) -> j từ 4 ->k =4
         a[i] = a[i] + 1;// tăng dần lên cho tới khi max
         for(int j = i+1; j<=k;j++)//câp nhật lại 
         {  // do vị trí i tăng lên 1 ->các vị trí sau sẽ liên tiếp 
            a[j] = a[j-1] + 1;
         }
         for(int i=1;i<=k;i++)
         {
            cout << a[i] << " ";//in ra mảng a
         }
         cout << endl;
         ckn(a,n,k);//mỗi lần gọi sẽ sửa lại mảng a
   }
}

int main()
{  
   int n,k ; cin >> n>> k ;
   int a[n];
   for(int i=1;i<=k;i++)
   {
       a[i] =i ;//cấu hình ban đầu 
   }
   for(int i =1 ; i<=k;i++)
   {
       cout << a[i] << " ";
   }
   cout<< endl;
   ckn(a,n,k);
      
}