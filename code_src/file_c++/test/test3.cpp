
#include <iostream>
using namespace std;
#include<stack>

int main()
{  stack<int> st;
   int n; cin >> n ;
   int point = 0 ; 
   while( n -- )
   {
      char x ;
      cin >> x; 
      if( x =='C')
      {  
         if(st.empty()) continue;
         point -= st.top();
         
         st.pop();

      }
      else if( x== 'D')
      {
         int cp = 2*st.top();
        
         st.push(cp);
         point+= cp;
      }
      else if( x == '+')
      {
         int pr1 = st.top();st.pop();
         
         int pr2 =st.top(); st.pop();
         int sp = pr1+pr2; 
         st.push(pr1)  ; 
         st.push(pr2);
         st.push(sp);
         point+=sp;
      }
      else 
      {
         st.push(x -'0');
         point+=x-'0';
      }

   }
   cout<<point;
   
}


