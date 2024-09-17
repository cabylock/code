#include<bits/stdc++.h>
using namespace std;

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) 
{   
    vector<int>result;
   //  cout<<queries.size()<<endl;
   //  cout<<stringList.size()<<endl;
    for(int i = 0 ; i< queries.size(); i++)
    {
        int count = 0 ;
        for ( int j = 0 ; j< stringList.size(); j++)
        {   
         // cout<<queries[i]<<" "<<stringList[j] <<endl;
            if(queries[i]== (stringList[j]) )
            {
                count ++;
            }
        }
        
        result.push_back(count);
    }
    return result;
    
}



int main()
{
      int n; cin >> n;
      vector<string> stringList(n);
      for (int i = 0; i < n; i++)
      {
         cin >> stringList[i];
      }
      int q; cin >> q;
      vector<string> queries(q);
      for (int i = 0; i < q; i++)
      {
         cin >> queries[i];
      }
      vector<int> result = matchingStrings(stringList, queries);
      
      for (int i = 0; i < result.size(); i++)
      {
         cout << result[i] << " ";
      }
   
}