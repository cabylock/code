#include<iostream>
#include<stack>
using namespace  std; 

int main()
{

    stack<int >st; 
    int n;cin >> n; 
    while( n --)
    {
        int x; cin >> x; 
        if( x == 1 )
        {
            int z ; cin >> z; 
            st.push(z); 
        }
        else if( x == 2 )
        {
            st.pop(); 
        }
        else 
        {
            cout <<st.top()<<endl ; 
        }
    }


}