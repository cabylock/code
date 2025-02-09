#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[1000];
int degree[1000] ={0};
// nếu dùng dfs như trong đồ thị vô hướng ->  sai 
// có thể từ 1 đỉnh v1 đi tới 1 đỉnh v2 mà v2 đã được duyệt  nhưng v2 nằm trong 
// 1 đường đi ko phải chu trình 
//  1 ->2 ->3 ->4 
//   5->2 
// khi gọi dfs(1,0) - > 2,3,4 được duyệt xong gọi dfs(5) -> v2 được duyệt rồi != parent[5] = 0 
// nhưng 5->2 không phải chu trình 
int status [100] = { 0 }; // 0-> chưa xét 
                          // 1 -> duyệt nhưng chưa xong 
                          // 2 -> duyệt nhuwg xong rồi 
int check_cycle_dfs(int v ,int parent)
{
   status[v] = 1 ; 
   for(int i : adj[v])
   {  
      if(status[i]  == 0 )
      {

         if( check_cycle_dfs(i, v) ==1)
         {  
            return 1 ;
         }
            
      }
      else if( status[i] == 1)
      {     
           
            return 1 ;
      }
      
      
   }
   status[v]  =2 ; 
   return  0 ; 
}

int  kahn_bfs( int v )
{
   queue<int> q; 
   for( int i = 1; i < v; i++ )
   {
      if( degree[i] == 0 ) q.push(i);
   }
   int cnt  = 0 ; // số đỉnh có bán bực vào = 0 ;
   while( !q.empty())
   {
      int x= q.front();
      q.pop();
      cnt ++ ; 
      for( int i : adj[x])
      {
         degree[i] -- ; // duyệt node con coi như xóa node cha thì degree = ?
         if( degree[i] == 0 )
         {  
            q.push(i); 
         }
      }
   }
   // nếu có chu trình thì các đỉnh có degree != 0 
   return cnt != v; 

}

int main()
{
   int v, e ; 
   cin >> v >> e ; 
   
   for(int i  = 0 ;  i< e;  i++)
   {
      int x, y ; cin >> x>> y ; 
      adj[x].push_back(y);
      degree[y] ++ ;// tăng bán vực vào lên 1 
      
   }
   cout<< kahn_bfs(v)<<endl ; 
   
   for(int i = 1  ; i<= e; i++)
   {
      if(status[i] == 0)
      {
        int x = check_cycle_dfs(i , 0 );
        if(x)
        {
         cout<< x;  return  0 ; 
        }
      }
   }
   cout<<  0 ; 


}


