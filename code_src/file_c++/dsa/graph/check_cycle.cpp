#include<iostream>
#include<vector>
#include<queue>
#include <string.h>

using namespace std; 

vector<int>adj[100];
   bool visited_dfs[100] ={0};
   bool visited_bfs[100] ={0};
int check_cycle_dfs(int u, int parent)
{
   visited_dfs[u] =  1 ; 
   for(auto i : adj[u])
   {
      if(!visited_dfs[i])//nếu chưa tới i 
      {
         if(check_cycle_dfs(i, u ) ==1 ) // đệ quy current v = i
         return 1 ; 
      }
      else if(parent != i)// nếu tới i rồi mà i không phải là cha
      {    
         return 1;
      }
   }
   return 0 ; 
}

int check_cycle_bfs(int u )
{  
   
   int parent[100] ={0};
   queue<int> q;
   q.push(u);
   visited_bfs[u] = 1 ;
   while(!q.empty())
   {
      int x =q.front(); q.pop();
      for(auto i : adj[x])
      {
         if(!visited_bfs[i])
         {
            q.push(i);
            visited_bfs[i] = 1; 
            parent[i] = x;
         }
         else if(i != parent[x])
         {   
            cout<< x<< i<< parent[x]<<" ";
            return 1 ;
         }
      }

   }
   return  0 ; 

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
   
   cout<< check_cycle_dfs(1, 0)<<endl; 
   cout<< check_cycle_bfs(1) <<endl ;

   // trường hợp đồ thị không liên thông -> check xem có đỉnh nào chưa qua thì gọi hàm 
   // tại đó 
   // hàm các định chu trình của mỗi thành phần liên thông tại bất kỳ đỉnh nào 
   // for(int i = 1; i<= v ; i++)
   // {
   //    if(visited[i] == 0 )
   //    {
   //       cout<< check_cycle(i,0) <<endl ;
   //    }
   // }

}