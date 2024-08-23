#include<iostream>
#include<map>
#include<string>
#include<sstream>

using namespace std;


int main()
{
    
    int n; cin >>n; 
    cin.ignore();
    map<string, int> m;
    while( n--)
    {
        string s; cin >> s;
        if(m[s] == 0)
        {
            cout<<s<<"\n";
            m[s]++;
        }
        else 
        {
            cout << s + to_string(m[s])   <<"\n";
        }
    }
    

   
    


}   