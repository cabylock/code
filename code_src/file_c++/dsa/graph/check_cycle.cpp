#include<iostream>
#include<vector>
#include <string.h>

using namespace std; 

bool visited[100] ={0};
vector<int>adj[100];
int check_cycle(int u, int parent)
{
   visited[u] =  1 ; 
   for(auto i : adj[u])
   {
      if(!visited[i])//nếu chưa tới i 
      {
         if(check_cycle(i, u ) ==1 ) // đệ quy current v = i
         return 1 ; 
      }
      else if(parent != i)// nếu tới i rồi mà i không phải là cha
      {    
         return 1;
      }
   }
   return 0 ; 
}

int main()
{
   int e,v;cin >>e >>v;
   for(int i = 0 ; i< e; i++)
   {
      int x,y; 
      cin >>x >> y ;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   
   cout<< check_cycle(1, 0); 
   
   // trường hợp đồ thị không liên thông -> check xem có đỉnh nào chưa qua thì gọi hàm 
   // tại đó 
   // hàm các định chu trình của mỗi thành phần liên thông tại bất kỳ đỉnh nào 


}