#include<iostream>
#include<queue>
#include<stack>
#include<set>
using namespace std;

int dx[4]= {-1, 0 , 0 ,1};
int dy[4] ={ 0 ,-1 , 1 , 0};

int main()
{   int m,n ; cin >> m>> n ; //size mảng 
    int startx, starty, desx,desy; // điểm bắt đầu và kết thúc
    cin >> startx>>starty >> desx >> desy;
    int a[m][n];
    for( int i =0 ; i< m ; i++)
    {
        for( int j =0; j< n; j++ )
        {
            cin>> a[i][j];
        }
    }

    int value[m][n] = {0}; 
    

    value[startx][starty] =0;
    
    queue<pair<int,int>> q ; // queue lưu trữ vị trí x,y
   
    q.push(make_pair(startx,starty));

    while(! q.empty())
    {
        int x= q.front().first; // lấy ra vị trí x,y
        int y =q.front().second;
        int count = value[x][y];
        q.pop();

        for( int i =0; i<4 ; i++) // duyệt 4 hướng
        {   int posx = x+dx[i];
            int posy =y +dy[i]; 
            if( posx >=0 && posx < m &&posy >=0 &&posy <n && a[posx][posy] !=0   ) // kiểm tra xem có thể đi được không
            {   a[posx][posy] = 0 ; // đánh dấu đã đi qua
                q.push(make_pair(posx,posy));
                
                    value[posx][posy] =count +1 ;
                
            }
        }

    }
    
    
    cout<< value[desx][desy];
   
}