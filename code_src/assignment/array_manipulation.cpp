#include<bits/stdc++.h>

using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) 
{     
      vector<long> arr(n+1);
      for (int i = 0; i < queries.size(); i++)
      {
         int a = queries[i][0];
         int b = queries[i][1];
         int k = queries[i][2];
         arr[a] += k;
         if (b + 1 <= n)
         {
               arr[b + 1] -= k;
         }
      }
      long max = 0;
      long sum = 0;
      for (int i = 1; i <= n; i++)
      {
         sum += arr[i];
         if (sum > max)
         {
               max = sum;
         }
      }
      return max;
}
int main()
{
      int n; cin >> n;
      int m; cin >> m;
      vector<vector<int>> queries(m);
      for (int i = 0; i < m; i++)
      {
         queries[i].resize(3);
         for (int j = 0; j < 3; j++)
         {
               cin >> queries[i][j];
         }
      }
      cout << arrayManipulation(n, queries) << endl;
}