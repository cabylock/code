#include<iostream>
#include<vector>
using namespace std;
// Sample Input 0
// cho n số điền vào mảng arr, tìm cách thêm dấu + - * vào giữa các số để ra kết quả % 101 = 0
// 3
// 22 79 21
// Sample Output 0

// 22*79-21

string arithmeticExpressions(vector<int> arr) 
{
    string dps[101];// dps[i] là sâu dài nhất có thể tạo ra kết quả % 101 = i
    
    dps[arr[0]] = to_string(arr[0]);
    for ( int i = 1; i< arr.size(); i++)
    {
        if(!dps[0].empty())
        {
            dps[0] += "*"+ to_string(arr[i]);//nếu có biểu thức con % 101 = 0 thì nhân thêm vẫn % 101 = 0
        }
        else
        {   
           string dps_temp[101]; // kết quả  khi có thêm arr[i]
            for( int j = 1; j< 101; j++)
            {
                if( !dps[j].empty())
                {
                    dps_temp[(j+arr[i])%101] =dps[j]+ "+" + to_string(arr[i] ) ;
                    dps_temp[(j-arr[i] +202)%101] =dps[j]+ ("-" + to_string(arr[i] ));
                    dps_temp[(j*arr[i])%101] =dps[j]+ ("*" + to_string(arr[i] ));
                    
                }
            }
           for( int i = 0 ; i< 101 ; i++)
           {
               dps[i] = dps_temp[i];
           }  
        }
        
    }
    return dps[0];
}


int main()
{
      vector<int> arr ;
      int n;cin >> n; 
      for (int i = 0 ; i < n; i++)
      {
          int x; cin >> x;
          arr.push_back(x);
      }
      cout << arithmeticExpressions(arr) << endl;
      return 0;
}