#include<iostream>
#include<vector>
#include<stack>

using namespace std ;

vector<int> waiter(vector<int> number, int q)
{
    vector<int> res ;
    vector<int> prime ;
    stack<int> A ;
    stack<int> B ;
    for(int i = 2 ; prime.size() < q ; i++)
    {
        bool isPrime = true ;
        for(int j = 2 ; j*j <= i ; j++)
        {
            if(i%j == 0)
            {
                isPrime = false ;
                break ;
            }
        }
        if(isPrime)
        {
            prime.push_back(i) ;
        }
    }
    for(int i = 0 ; i< q ; i++)
    {
        while(!number.empty())
        {
            int top = number.back() ;
            number.pop_back() ;
            if(top%prime[i] == 0)
            {
                B.push(top) ;
            }
            else
            {
                A.push(top) ;
            }
        }
        while(!B.empty())
        {
            res.push_back(B.top()) ;
            B.pop() ;
        }
        number.clear();
        while (!A.empty()) {
            number.push_back(A.top());
            A.pop();
        }
        while(!A.empty())
        {
            A.pop() ;
        }
    }
    while(!number.empty())
    {
        res.push_back(number.back()) ;
        number.pop_back() ;
    }
    return res ;
}

int main()
{
   int n , q ;
   cin >> n >> q ;
   vector<int> number(n) ;
   for(int i = 0 ; i< n ; i++)
   {
       cin >> number[i] ;
   }
   vector<int> res = waiter(number, q) ;
   for(int i = 0 ; i< res.size() ; i++)
   {
       cout << res[i] << endl ;
   }
    return 0 ;



  
}