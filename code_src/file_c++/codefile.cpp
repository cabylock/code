#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(vector<int>& nums) 
    {
       int j = 0 ;int count = 0; 
        for( int i =0; i< nums.size(); i++)
        {
            if( nums[i] != nums[j] || count <2)
            {
                
               
                if( nums[i] != nums[j])
                {
                    count = 1 ;
                }
                else 
                {
                    count ++ ;
                }
                nums[j] = nums[i];
                 j++;

            }
             else if( count ==2 )
            {
                if( nums[j] != nums[j-1])
                {
                    count =1;
                }
            }
            
            
        }
        return  j;
    }
int main()
{
    vector<int> nums1 = {0,0,1,1,1,1,2,3,3};
    cout<<removeDuplicates(nums1)<<endl;

    

}




