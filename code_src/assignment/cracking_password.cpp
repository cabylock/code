#include<bits/stdc++.h>
using namespace std;


string passwordCracker(vector<string> passwords, string loginAttempt) 
{
   queue<string>q;
   for(int i = 0 ;i< passwords.size(); i++)
   {
       if(passwords[i] == loginAttempt.substr(0,passwords[i].size()))
       {
           q.push(passwords[i]);
       }
   }
   if( q.empty())
   {
       return "WRONG PASSWORD";
   }
    string result = "";
    while( !q.empty())
    {
        string text = q.front();
        q.pop();
       for( int i = 0 ; i< passwords.size(); i++)
       {
              if( passwords[i] == loginAttempt.substr(text.size(),passwords[i].size()))
              {
                if( text.size() + passwords[i].size() == loginAttempt.size())
                {
                    result = text + " " + passwords[i];
                    return result;
                }
                else
                {   result = text + " " + passwords[i];
                    q.push(text + passwords[i]);
              }
       }
    }
    }
    
    return "WRONG PASSWORD";
}

int main()
{   
    
    int t ; cin>>t;
    while( t--)
    {
        int n ; cin>>n;
        vector<string> passwords(n);
        for( int i = 0 ; i< n ; i++)
        {
            cin>>passwords[i];
        }
        string loginAttempt; cin>>loginAttempt;
        cout<<passwordCracker(passwords,loginAttempt)<<endl;
    }
    
}