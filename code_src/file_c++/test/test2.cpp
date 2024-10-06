#include<iostream>
#include<vector>
#include<stack>
using namespace std; 

int andXorOr(vector<int> a) {
    // = ( m1 xor m2) ; 
    // 100 + 011  -> a xor b max
   int res = 0 ; 
   stack<int> st; st.push(a[0]) ; 
   
   for(int i = 1 ; i< a.size() ; i++)
   {
       if( a[i] > a[i-1])
       {   cout<< a[i-1] << " " << a[i] <<" " << (a[i] ^ a[i-1] ) << endl;
           res =max(res, a[i] ^ a[i-1]);
       }
       else 
       {
        // a[i] < a[i-1]
         
       }
    }

   return res ;
}


int main()
{


  int n ;cin >> n; 
  vector<int> a(n);
  for(int i = 0 ; i < n ; i++)
  {
    cin >> a[i];
  }
  cout<<andXorOr(a);

}