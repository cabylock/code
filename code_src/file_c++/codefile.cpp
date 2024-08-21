#include<bits/stdc++.h>

using namespace std;


void abc(   int m , int n ,    vector<int>& nums1 , vector<int>& nums2 )
{
     int a= 0 , b = 0 ;
        int l = m+n ;
        while(  l--  )
        {
            
             if( nums1[a] == 0)
            {
                nums1[a] = nums2[b];
                a++;
                b++;
            }
            else if( nums1[a] > nums2[b])
            {
                nums1.insert( nums1.begin() + a  , nums2[b] );
                a++;b++;
            }
            else 
            {
                a++;
            }

        }
        nums1.erase( nums1.begin() + m , nums1.end() );
        
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3 , n = 3;
    abc( m , n , nums1 , nums2 );


    

}




