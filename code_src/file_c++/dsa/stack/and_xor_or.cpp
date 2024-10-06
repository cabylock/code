#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int andXorOr(vector<int> a) {
    // = ( m1 xor m2) ; 
    // 100 + 011  -> a xor b max
   // 9 6 5 3 10 11 4 2 
   // 0 1 2 3  4  
   int res =0 ; 
   int max_index = 0 ;
   for(int i = 1 ; i< a.size() ; i++)
   {
       if( a[i] > a[max_index])
       {
           int j = i-1; 
           while( a[j]  >a[i] && j >= 0  )
           {
               res= max( res, a[j] ^ a[i]);
               j--;
           }
           res=max(res, a[j] ^ a[i]);
       }
       else  {
           int j = i -1; 
           int min_val = j ;
           while( j >= max_index)
           {
               if( a[j] < a[min_val])
               {
                   min_val = j ;
               }
               res =max(res ,a[i] ^ a[min_val]);
               j--; 
           }
           max_index = i ; 
           
       }
   }
   return res; 
}

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