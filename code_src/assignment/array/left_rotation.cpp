#include<bits/stdc++.h>
using namespace std;

vector<int> leftRotation(vector<int> a, int d) 
{
    vector<int> b;
    for (int i = d; i < a.size(); i++)
    {
        b.push_back(a[i]);
    }
    for (int i = 0; i < d; i++)
    {
        b.push_back(a[i]);
    }
    return b;
}

int main()
{
      int n; cin >> n;
      int d; cin >> d;
      vector<int> a(n);
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
      }
      vector<int> result = leftRotation(a, d);
   
      for (int i = 0; i < result.size(); i++)
      {
         cout << result[i] << " ";
      }
}