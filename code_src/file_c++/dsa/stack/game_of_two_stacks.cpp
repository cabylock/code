#include<iostream>
#include<stack> 
#include<vector>

using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b) 
{
    
    stack<int> st; 
    int sum = 0 ;
    for(int i  = 0 ; i< a.size(); i++)
    {
        if( sum+ a[i] <= maxSum)
        {
            st.push(a[i]) ; 
            sum+= a[i];
            
        }
        else 
        {
            break;
        }
        
        
    }
    int res =st.size() ;
    for(int i = 0 ; i< b.size() ; i++)
    {
        while( (sum + b[i] > maxSum) &&  (!st.empty()))
        {   
            sum -= st.top();
            
            st.pop();
        }
        if( sum + b[i] > maxSum)
        {
            break;
        }
        sum += b[i];
        res = max(res,(int) st.size()+i+1);
    }
   
   return res; 

}


int main()
{     
      int g ;cin>>g;
      while(g--)
      {
          int n,m,x; 
          cin>>n>>m>>x;
          vector<int> a(n),b(m);
          for(int i = 0 ; i< n ; i++)
          {
              cin>>a[i];
          }
          for(int i = 0 ; i< m ; i++)
          {
              cin>>b[i];
          }
          cout<<twoStacks(x,a,b)<<endl;
      }


}