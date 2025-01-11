#include<iostream>
#include<stack>   
#include<vector>
using namespace std;

long largestRectangle(vector<int> h) 
{
   
   long res = 0 ;
   stack<int> st; int i = 0 ;
   while(i<h.size())
   {
         if(st.empty() || h[i] >= h[st.top()])
         {
            st.push(i++);
         }
         else 
         {
            int tp = st.top(); st.pop();
            long area = h[tp] * (st.empty() ? i : i - st.top() - 1);
            res = max(res, area);
         }
   }
   while(!st.empty())
   {
      int tp = st.top(); st.pop();
      long area = h[tp] * (st.empty() ? i : i - st.top() - 1);
      res = max(res, area);
   }
   return res; 
}

int main()
{
      int n ; cin>>n;
      vector<int> h(n);
      for(int i = 0 ; i< n ; i++)
      {
         cin>>h[i];
      }
      cout<<largestRectangle(h);



}


