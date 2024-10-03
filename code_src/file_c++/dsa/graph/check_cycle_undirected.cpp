#include<iostream>
#include<vector>
using namespace std ; 

bool visited_dfs[1000]={0};
vector<int> adj[1000];
int check_cycle(int v , int parent)
{
   visited_dfs[v]  = 1 ; 
   for( int i : adj [v])
   {
      if( visited_dfs[i]  ==0)
      {
         if( check_cycle(i, v) ==1 )
         {
            return 1; 
         }
      }
      else if( i != parent )
      {
         return 1 ; 
      }
   }
   return 0 ; 



}


int main()
{
   int v, e ; 
   cin >> v >> e ; 
   
   for(int i  = 0 ;  i< e;  i++)
   {
      int x, y ; cin >> x>> y ; 
      adj[x].push_back(y);
      adj[y].push_back(x);
   }

   
   for(int i = 1 ; i <=v; i++)
   {
      if(visited_dfs[i] == 0 )
      {
         if(check_cycle(i, 0) ==1 )
         {
            cout<< 1 ;return 0;
         }
      }

   }
   cout<< 0 ; 
   

}


