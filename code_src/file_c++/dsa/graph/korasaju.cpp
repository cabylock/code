#include<iostream>
#include<vector>
#include<stack>
#include<string.h>

using namespace std; 
// tìm các thành phần liên thông mạnh ( strongly connected components :scc )
//O( 2 ((v+e)))
// 2 lần dfs 
// tính chất : thành phần liên thông không đổi khi đảo ngược đường đi 
vector<int> adj[1000] , radj[1000]; // radj: đảo tất cả hướng của đường đi ngược lại 
bool visited[1000] ={0}; 

stack<int> st; // lưu thứ tự đỉnh được duyệt xong trước
               // sắp xếp topo

void dfs1(int x )
{
   visited[x]  =1; 
   for( int i : adj[x])
   {
      if(visited[i] == 0 )
      {  
         dfs1(i);
      }
   }
   st.push(x);
   cout<< x<<" "; 
}

void dfs2(int x)
{  
   visited[x] =1 ; 
   cout<< x <<" "; 
   for( int i : radj[x])
   {
      if( visited[i] == 0 )
      {
         dfs2(i);
      }
   }
}

void scc(int v )
{
   for(int i =1 ; i<= v ; i++)
   {
      if(visited[i]  == 0 )
      {
         dfs1(i); 
      }
   }
   cout<< endl ;
   memset(visited,0 , sizeof(visited)); 
  while( !st.empty())
  {
      int x = st.top(); 
      st.pop(); 
      if(visited[x] ==  0 )
      {
         dfs2(x); 
         cout<< endl ;
      }
  }

}

int main()
{  
   int v, e ; 
   cin>> v>> e ;
   for(int i = 0 ; i<  e ; i++)
   {
      int x,  y ; 
      cin >> x >> y ; 
      adj[x].push_back(y);
      radj[y].push_back(x);
   }
   scc( v );
   
   


}