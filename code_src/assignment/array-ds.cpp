#include<bits/stdc++.h>
#include<vector>
using namespace std;
// Complete the reverseArray function below.
vector<int> reverseArray(vector<int> a) 
{
      vector<int> b;
      for (int i = a.size()-1; i >= 0; i--)
      {
         b.push_back(a[i]);
      }
      return b;
}


int main()
{
   int n; cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   vector<int> result = reverseArray(a);

   for (int i = 0; i < result.size(); i++)
   {
      cout << result[i] << " ";
   }


}