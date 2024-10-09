#include<iostream>
#include<stack>
#include<vector>

using namespace std;



int main()
{
      int n; 
      cin>>n;
      vector<int> a(n);
      for(int i = 0 ; i< n ; i++)
      {
         cin>>a[i];
      }
      stack<int> st; 
      int res = 0;
      for(int i = 0 ; i< n ; i++)
      {
         while(!st.empty())
         {
               int x = a[i]^st.top();
               res = max(res,x);
               if(a[i] < st.top())
               {
                  st.pop();
               }
               else 
               {
                  break;
               }
         }
         st.push(a[i]);
      }
      cout<<res;
}