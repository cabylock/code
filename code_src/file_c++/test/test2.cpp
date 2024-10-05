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
           if( a[i]<st.top())
           {
           
            int j  =  i-1 ; 
           do  { cout<< a[j] << " " << a[i] <<" " << (a[j] ^ a[i] ) << endl;
                res = max(res, a[j] ^ a[i]);
                j--;
            }
            while( j >= 0 && a[j] != st.top());
            st.push(a[i]);
           }
           else 
           {
            int j = i-1 ;
            do  {
             cout<< a[j] << " " << a[i] <<" " << (a[j] ^ a[i] ) << endl;
                res = max(res, a[i] ^ a[j]);
                j--;
            }
            while( a[i] < a[j] && j >= 0);
           }
           
           
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