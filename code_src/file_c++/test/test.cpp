#include<iostream>
using namespace std; 

int partrition ( int a[], int l , int r )
{
    //lomuto 
    int value_pivot = a[r];
    int i = 0 ; 
    for(int j= 0 ; j< r;  j++)
    {
        if( a[j] <= value_pivot)
        {
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i ; 


}

void quicksort(int a[], int l , int r )
{
    if(l < r )
    {
        int pivot = partrition( a, l, r );
       
        quicksort(a, l, pivot-1 );
        quicksort(a, pivot+1, r ); 


    }
}



int main()
{
    int n ;cin >> n ;

    int arr[n] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i] ;
    }

    quicksort(arr, 0, n -1 );
    for( auto i : arr )
    {
        cout << i <<" "; 
    }
    
}