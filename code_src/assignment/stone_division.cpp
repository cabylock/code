#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



long long  stoneDivision(long long  n, vector<long long > s) 
{      
       vector<pair<long long ,long long >> dp;
       dp.push_back({1,0});
         sort(s.begin(),s.end());
            for(int i = s.size()-1; i >= 0; i--)
            {
                if(n % s[i] == 0 && s[i] <n)
                {
                    dp.push_back({n/s[i],n% s[i]});
                }
            } 
            if(dp.size() == 0) return 0;
            long long res =0 ;
            for(int i = 1 ; i < dp.size(); i++)
            {
                res =0 ;
                for(int j =i-1;j>=0;j--)
                {
                    if(dp[i].first % dp[j].first == 0)
                    {
                        res =max(dp[j].first+dp[j].second,res);
                    }
                }

                        dp[i].second = res;
            }
        return dp[dp.size()-1].second;
}

int main()
{
   int t ;cin >> t ;
   while( t--)
   {
        long long  n ;cin >> n;
        int m ; cin >> m ;
        vector<long long > s(m);
        for(int i = 0 ; i < m ; i++)
        {
            cin >> s[i];
        }
        cout << stoneDivision(n,s) << endl;
   }
}