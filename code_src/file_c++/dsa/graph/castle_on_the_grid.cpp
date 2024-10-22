#include<iostream>
#include<queue>
#include<map>
#include<utility>
using namespace std;


int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) 
{
    queue<tuple<int,int,int>> q ;
    int len = grid.size(); 
    q.push(make_tuple(startX,startY, 0)) ; 
    grid[startX][startY] = '0';
    while(!q.empty())
    {   
        int x = get<0>( q.front() ); 
        int y = get<1> (q.front()) ;
        int res =get<2> (q.front());
        if( x == goalX && y == goalY)
        {
            return res ;
        }
        q.pop();
        for( int i = x+1 ; i < len ; i++  )
        {
            if(grid[i][y] == '.')
            {
                q.push(make_tuple(i,y,res+1));
                grid[i][y] = '0';
            }
            else if( grid [i][y] == 'X')
            {
                break;
            }
        }
        for( int i = x-1 ; i >= 0 ; i--  )
        {
            if(grid[i][y] == '.')
            {
                q.push(make_tuple(i,y,res+1));
                grid[i][y] = '0';
            }
            else if( grid [i][y] == 'X')
            {
                break;
            }
        }

         for( int i = y-1 ; i >= 0 ; i--  )
         {
               if(grid[x][i] == '.')
               {
                  q.push(make_tuple(x,i,res+1));
                  grid[x][i] = '0';
               }
               else if( grid [x][i] == 'X')
               {
                  break;
               }
         }

        for( int i = y+1 ; i < len ; i++  )
        {
            if(grid[x][i] == '.')
            {
                q.push(make_tuple(x,i,res+1));
                  grid[x][i] = '0';
            }
            else if( grid [x][i] == 'X')
            {
                break;
            }
        }
    }
   return 0 ;
    
}


int main()
{

     int n;cin>>n;
       vector<string> grid(n);
         for(int i=0;i<n;i++)
         {
            cin>>grid[i];
         }
         int startX,startY,goalX,goalY;
         cin>>startX>>startY>>goalX>>goalY;
         cout<<minimumMoves(grid,startX,startY,goalX,goalY);
      return 0;
}