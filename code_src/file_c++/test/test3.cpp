#include<iostream>

using namespace std; 
int n ;
void copy_array(int src[], int dest[], int n) {
    memcpy(dest, src, n * sizeof(int));
}

void insert_sort( int a[], int n )
{  
   for( int i = 1; i< n ; i++)
   {
      int j = i -1; 
      int key = a[i]; 
      while( j >= 0  &&  a[j] > key)
      {
         a[j+1] =a[j];
         j--; 
      }
      a[j+1] = key ;


   }
   for ( int i = 0 ; i< n; i ++)
   {
      cout << a[i] <<" "; 
   }
   cout << endl; 


}


void bubble_sort ( int a[], int n )
{
   for ( int i = 0 ; i< n; i ++)
   {
      for ( int j  = 0 ;j < n-1; j++)
      {
         if ( a[j] > a[j+1]   )
         {
            int temp = a[j]; 
            a[j] = a[j+1];
            a[j+1] = temp ;
         }
      }
   }
   for( int i = 0 ; i< n; i++)
   {
      cout << a[i] <<" ";
   }
   cout << endl; 

}


void selection_sort ( int a[], int n )
{
   for ( int i = 0 ; i< n; i++)
   {  
      int min_i = i ;
      for ( int j = i +1; j < n; j ++)
      {
         if( a[j] < a[min_i])
         {
            min_i = j ; 
         }
      }
      int temp = a[i]; 
      a[i] = a[min_i];
      a[min_i] = temp ; 
   }

   for ( int i = 0 ; i< n; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl; 
}

void merge(int a[], int l , int p , int r )
{
   int n1 = p-l ; int n2 = r- p+1 ;
   int left[ n1] ;
   int right [n2 ];

   for ( int i = 0 ; i <n1; i++)
   {
      left[i] = a[i+l];
   }
   for ( int i = 0; i <n2 ; i ++)
   {
      right[i] = a[i + p ] ;
   }
   
   int i = 0 ; int j = 0 ;
   while( i < n1  && j < n2 )
   {
      if( left[i] < right[j])
      {
         a[l++] = left[i++];
      }
      else 
      {
         a[l++] = right[j++];
      }
   }

   while( i < n1)
   {
      a[l++] =left[i++];
   }
   while( j < n2)
   {
      a[l++] = right[j++]; 
   }


}

void merge_sort( int a[], int l , int r  )
{
      if( r > l )
      {
         merge_sort( a, l, (r+l) /2 ); 
         merge_sort( a, (r+l)/2 + 1 , r );
         merge( a, l, (r+l)/2 , r ) ;
      }
      if( l == 0 && r== n-1)
      {
         for ( int i = 0 ; i< n; i ++)
         {
            cout << a[i] << " ";
         }
         cout << endl; 
      }
      
}

int  lomuto( int a[], int l , int r )
{
   int key = a[r]; 
   int i = 0 ; int j = 0 ;
   while(j <= r  )
   {  
      if( a[j] < key )
      {

      int temp = a[i] ; 
      a[i] =a [j]; 
      a[j] =temp ; i ++ ;
      }
      j ++ ; 
   }
   
   return i-1 ; 
}

void quick_sort( int a[], int l , int r )
{
   if( l < r )
   {
      int p = lomuto( a, l , r );
      
      quick_sort( a, l , p ); 
      quick_sort(a, p+1, r ); 
   }
   if( l == 0 && r == n-1)
   {
      for ( int i =  0 ; i< n ; i ++)
      {
         cout << a[i] <<" ";
      }
      cout << endl ; 
   }
}

int main()
{
   cin >> n; 
   int a[n]; 
   for ( int i = 0 ; i< n; i++)
   {
      cin >> a[ i]; 
   }
   int temp[n];
   copy_array(a,temp, n); 
   cout << "insert_sort " ;  insert_sort(temp,n);

   copy_array(a,temp, n); 
   cout <<"bubble_sort " ; bubble_sort( temp,n );

   copy_array(a,temp, n); 
   cout << "select_sort "; selection_sort( a,n) ;

   copy_array(a, temp , n ); 
   cout <<" merge_sort "; merge_sort(a,0, n-1);

   copy_array( a , temp , n );
   cout << " quick_sort " ; quick_sort( a, 0 , n-1 ); 




}