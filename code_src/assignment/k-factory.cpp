#include<bits/stdc++.h>
using namespace std;
vector<int> kFactorization(int n, vector<int> A) 
{   
    vector<int> res;
    res.push_back(n);
    sort(A.begin(),A.end());
    while( n != 1)
    {   bool flag = 0;
        for(int i = A.size()-1 ; i>=0 ; i--)
        {
            if(n% A[i] == 0)
            {   
                n/= A[i];
                res.push_back(n);
                flag = 1; break;
            }
        }
        if(flag == 0)
        {   res.clear();
            res.push_back(-1);
            return res;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
      int n; cin >> n;
      int m; cin >> m;
      vector<int> A;
      for (int i = 0 ; i < m; i++)
      {
         int x; cin >> x;
         A.push_back(x);
      }
      vector<int> res = kFactorization(n,A);
      for (auto i : res)
      {
         cout<<i<<" ";
      }
      return 0;
}

