#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int poisonousPlants(vector<int> p) {
//  7
// p = 6 5 8 4 7 10 9
   //  res  = 2 
    stack<pair<int,int>> s ; // value , days
      int ans = 0 ; 
      for(int i = 0 ; i < p.size() ; i++)
      {
         int days = 0 ; 
         while(!s.empty() && s.top().first >= p[i])
         {  // nếu cây trước mà độc hơn cây sau thì xóa cây trước
            //đỉnh stack sau khi xóa lưu giá trị và số ngày đã được xử lý trước đó 
               days = max(days,s.top().second) ; 
               s.pop() ; 
         }
         if(s.empty())
         {
               days = 0 ; 
         }
         else
         {
               days++ ; 
         }
         ans = max(ans,days) ; 
         s.push({p[i],days}) ; 
      }
    return ans;
    
}

int main()
{

      int n = 0 ; 
      cin >> n ; 
      vector<int> v(n) ; 
      for(int i = 0 ; i < n ; i++)
      {
         cin >> v[i] ; 
      }
      cout << poisonousPlants(v) << endl ;
      return 0 ;
}