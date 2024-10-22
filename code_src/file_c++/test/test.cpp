#include<iostream>
#include<stack>
using namespace std;



int main()
{
    int t ; cin >> t; 
    while( t--)
    {
        string s; cin >> s; 
        stack<char> st; 
        for( int i = 0; i< s.size(); i++)
        {
            if( s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if( st.empty())
                {
                    cout<<"no"<<endl;
                    break;
                }
                else
                {
                    if( s[i] == ')' && st.top() == '(')
                    {
                        st.pop();
                    }
                    else if( s[i] == ']' && st.top() == '[')
                    {
                        st.pop();
                    }
                    else if( s[i] == '}' && st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        cout<<"no"<<endl;
                        break;
                    }
                }
            }
        }
        if( st.empty())
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
}