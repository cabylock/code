#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int downToZero(int n) 
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    while(!q.empty())
    {
        auto p = q.front(); q.pop();
        if(p.first == 0) return p.second;
        for(int i = 2; i <= sqrt(p.first); i++)
        {
            if(p.first % i == 0)
            {
                q.push({p.first/i, p.second+1});
            }
        }
        q.push({p.first-1, p.second+1});
    }
    return 0;
}

int main()
{
      int n ;cin >> n; 
      while(n--)
      {
          int x; cin >> x; 
          cout << downToZero(x) << endl;
      }
}