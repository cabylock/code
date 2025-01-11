#include<bits/stdc++.h>
using namespace std;


int mex(set<int> g)
{
    int m = 0;
    while(g.find(m) != g.end()) m++;
    return m;
}

  
int dp[305];
int caculateg(int state)
{
     if(state == 0) return 0;
       if(dp[state] != -1) return dp[state];

         set<int> g;
      for(int i = 0 ;i<= state /2; i++)
      {
         g.insert(caculateg(i)^caculateg(state - i -1));
         // nếu tách ra  thành 2 phần thì phần đó sẽ bằng xor của 2 trạng thái riêng 
         
         if(state - i -2 >= 0)
         { g.insert(caculateg(i)^caculateg(state - i -2));
         }
         
      }
      int res = mex(g);
      return dp[state] = res;
      return res;

      
}


string isWinning(int n, string config) 
{
   memset(dp, -1, sizeof(dp));
   int index =0 ;
   while(config[index] != 'I')
   {
       index++;
   }
   int count1 = 0 ;int res =0 ;
   for(int i = index ; i< n; i++)
   {
      if(config[i] == 'I') count1++;
      else 
      {
         res ^= caculateg(count1);
         count1 = 0;
      }
   }
   res ^= caculateg(count1);
   return res == 0 ? "LOSE" : "WIN";
   

}


int main()
{  
   int t ; cin >> t ; 
   while(t--)
   {
      int n;
      string config;
      cin >> n >> config;
      cout << isWinning(n, config) << endl;
   }
   return 0;
}

