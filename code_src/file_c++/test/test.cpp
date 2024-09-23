#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<cstring>

using namespace std; 

int mex(set<int> g)
{   
    if(g.size() == 0) return 0;

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
      for(int i = 0 ;i<= state/2; i++)
      {  
       cout<<"tach1 "<<i<<" "<<state - i -1<<endl;
         g.insert(caculateg(i)^caculateg(state - i -1));
        
         
         if(state - i -2 >= 0)
         {  
        cout<<"tach2 "<<i<<" "<<state - i -2<<endl;
            g.insert(caculateg(i)^caculateg(state - i -2));
         }
         

      }
      
      for(auto i : g)
      {
          cout<<i<<" ";
      }
      cout<<endl;
      int res = mex(g);
      return dp[state] = res;
      return res;



     
      
}


int main()
{   
  
       cout<<199223516365 %3;
   //
}