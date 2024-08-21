#include<iostream>

#include<string>
using namespace std;

const int n =100000;

int arr[n]   ={0};

int pi[n] ={0};


void f1( string a)
{
     
    int j =0;
    
    arr[0] = 0;
    for ( int i =1; i< (int ) a.length(); i++)
    {
        if( a[i] == a[j])
        {
            arr[i] = arr[i-1] +1;
            j++;
        }
        else 
        {
            arr[i] = 0;
            j =0;
             if( a[i] == a[j])
        {
            arr[i] =1;
            j++;
        }
        }
    }
    
}

void f2( string s)
{
    int n = (int)s.length();
    
    for (int i = 1; i < n; i++) {
        int j = arr[i - 1];
        while (j > 0 && s[i] != s[j])
            j = arr[j - 1];
        if (s[i] == s[j])
            j++;
        arr[i] = j;
    }
   
} 




int main()
{
    string b; cin >> b;
    string a;cin >> a;

    //f2(a);
    f2(a);int lena= a.length();int lenb =b.length();
    int j =0;
    /*for ( int i=0; i<lena; i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<<"\n";*/

  for ( int i =0; i<=lenb; i++)
  {     
    if( j == lena)
    {       
        j = arr[j-1];
        cout<< i-lena+1<<" ";

    }
    //cout<<i<<" "<<j<<"\n";
    if( a[j] == b[i])
    {
        j++;



    }
    else 
    {
        if( j != 0)
        {
            j=arr[j-1];
            i--;
        }
        


    }
    



  }







}