#include<bits/stdc++.h>
using namespace std;


vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int> result;
    vector<vector<int>> arr(n);
    int lastAnswer = 0 ;
    for ( int i = 0; i< queries.size(); i++)
    {
        if(queries[i][0] ==1)
        {
            int idx= (queries[i][1] ^ lastAnswer)%n;
            cout<<idx<<endl;
            arr[idx].push_back(queries[i][2]);
        }
        else 
        {
            int idx = (queries[i][1] ^ lastAnswer)%n;
            cout<<idx<<endl;
            lastAnswer= arr[idx][queries[i][2]%(arr[idx]).size()];
            result.push_back(lastAnswer);
        }
    }
    return result;
}


int main()
{
      int n; cin >> n;
      int q; cin >> q;
      vector<vector<int>> queries(q);
      for (int i = 0; i < q; i++)
      {
         queries[i].resize(3);
         for (int j = 0; j < 3; j++)
         {
               cin >> queries[i][j];
         }
      }
      vector<int> result = dynamicArray(n, queries);
   
      for (int i = 0; i < result.size(); i++)
      {
         cout << result[i] << " ";
      }
}



