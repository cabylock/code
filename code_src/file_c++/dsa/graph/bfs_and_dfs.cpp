#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> adj[1001];
bool visited_bfs[1001] ={0};
bool visited_dfs[1001] ={0};
void init()
{  
    int n,m; cin >> n>> m;// n là số đỉnh , m là số cạnh
      for (int i = 0; i < m; i++)
      {
         int u,v; cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }

}

void bfs(int node)
{
   queue<int> q;
   q.push(node);
   visited_bfs[node] = 1;
   while( !q.empty())
   {
         int node = q.front();
         cout<<node<<" ";
         q.pop();
         for (auto i : adj[node])
         {
            if (!visited_bfs[i])
            {
                  visited_bfs[i] = 1;
                  q.push(i);
            }
         }
   }
}

void dfs(int node)
{
   visited_dfs[node] = 1 ; 
   cout<<node<<" ";
   for( auto i : adj[node])
   {
      if( visited_dfs[i] == 0)
      {  
         dfs(i);
      }
   }
}


int main()
{
   init();
   dfs(1);
   cout<<endl;
   bfs(1);
}

