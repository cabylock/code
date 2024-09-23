
#include<bits/stdc++.h>
using namespace std;

struct queen
{
   int x, y;
   queen(int x, int y) : x(x), y(y) {}

   vector<vector<pair<int,int>>> moves = {
        {{1,0},{2,0},{3,0}},
        {{-1,0},{-2,0},{-3,0}},
        {{0,1},{0,2},{0,3}},
        {{0,-1},{0,-2},{0,-3}},
        {{1,1},{2,2},{3,3}},
        {{1,-1},{2,-2},{3,-3}},
        {{-1,1},{-2,2},{-3,3}},
        {{-1,-1},{-2,-2},{-3,-3}}
    };

    
};

struct knight
{
    int x, y;
    knight(int x, int y) : x(x), y(y) {}
      vector<pair<int,int>> moves = {
         {1,2},
         {1,-2},
         {-1,2},
         {-1,-2},
         {2,1},
         {2,-1},
         {-2,1},
         {-2,-1}
      };

};
struct rook
{
    int x, y;
    rook(int x, int y) : x(x), y(y) {}
    vector<vector<pair<int,int>>> moves = {
        {{1,0},{2,0},{3,0}},
        {{-1,0},{-2,0},{-3,0}},
        {{0,1},{0,2},{0,3}},
        {{0,-1},{0,-2},{0,-3}}
    };
};
struct bishop
{
    int x, y;
    bishop(int x, int y) : x(x), y(y) {}
      vector<vector<pair<int,int>>> moves = {
         {{1,1},{2,2},{3,3}},
         {{1,-1},{2,-2},{3,-3}},
         {{-1,1},{-2,2},{-3,3}},
         {{-1,-1},{-2,-2},{-3,-3}}
      };

};
// 1 queen ,2 rook, 3 bishop, 4 knight
// positive : white, negative : black
int checkQueen(int chess_board[5][5])
{  
    for ( int row =1 ; row<=4 ; row++)
    {
         for (int col = 1; col<=4; col++)
         {
               if(chess_board[row][col] == -1)// black queen in board
            {
               return 0;
            }
         }
    }
    return 1;
}

int backtracking( int  chess_board[5][5], int moves, int player)
{  // player = 1 : white, player = -1 : black

    int result = checkQueen(chess_board);
      if(result == 1 || moves == 0)
      {
          return result;
      }
    
      vector<rook> rooks_white;
      vector<rook> rooks_black;
      queen queens_white(0,0);
      queen  queens_black(0,0);
      vector<bishop> bishops_white;
      vector<bishop> bishops_black;
      vector<knight> knights_white;
      vector<knight> knights_black;

      for ( int row =1 ; row<=4 ; row++)
      {
         for(int col = 1 ; col <= 4 ; col ++)
         {
               if(chess_board[row][col] == 2)
               {
                  rooks_white.push_back(rook(row, col));
               }
               else if(chess_board[row][col] == -2)
               {
                  rooks_black.push_back(rook(row, col));
               }
               else if(chess_board[row][col] == 1)
               {
                  queens_white = queen(row, col);
               }
               else if(chess_board[row][col] == -1)
               {
                  queens_black = queen(row, col);
               }
               else if(chess_board[row][col] == 3)
               {
                  bishops_white.push_back(bishop(row, col));
               }
               else if(chess_board[row][col] == -3)
               {
                  bishops_black.push_back(bishop(row, col));
               }
               else if(chess_board[row][col] == 4)
               {
                  knights_white.push_back(knight(row, col));
               }
               else if(chess_board[row][col] == -4)
               {
                  knights_black.push_back(knight(row, col));
               }
         }
      }

    if(player == 1)
    {
      //queen moves 
      for( int direction =0 ;direction < queens_white.moves.size(); direction++)
      {
          for (int i = 0; i<queens_white.moves[direction].size(); i++)
          {
              int x = queens_white.x + queens_white.moves[direction][i].first;
              int y = queens_white.y + queens_white.moves[direction][i].second;
              if(chess_board[x][y]  !=0)
              {
                  break; //di theo huong nay khong duoc
              }
               else
               {     int temp = chess_board[x][y];
                     chess_board[x][y] = 1;
                     if(backtracking(chess_board, moves-1, -1) == 1)
                     {
                        return 1;
                     }
                     chess_board[x][y] = temp;
                     if(temp <0)
                     {
                         break;
                     }
               }
          }

      }
      //rook moves
      for (int i = 0; i<rooks_white.size(); i++)
      {
          for( int direction =0 ;direction < rooks_white[i].moves.size(); direction++)
          {
              for (int j = 0; j<rooks_white[i].moves[direction].size(); j++)
              {
                  int x = rooks_white[i].x + rooks_white[i].moves[direction][j].first;
                  int y = rooks_white[i].y + rooks_white[i].moves[direction][j].second;
                  if(chess_board[x][y]  !=0)
                  {
                      break; //di theo huong nay khong duoc
                  }
                  else
                  {     int temp = chess_board[x][y];
                        chess_board[x][y] = 2;
                        if(backtracking(chess_board, moves-1, -1) == 1)
                        {
                           return 1;
                        }
                        chess_board[x][y] = temp;
                        if(temp <0)
                        {
                            break;
                        }
                  }
              }

          }
      }
      //bishop moves
      for (int i = 0; i<bishops_white.size(); i++)
      {
          for( int direction =0 ;direction < bishops_white[i].moves.size(); direction++)
          {
              for (int j = 0; j<bishops_white[i].moves[direction].size(); j++)
              {
                  int x = bishops_white[i].x + bishops_white[i].moves[direction][j].first;
                  int y = bishops_white[i].y + bishops_white[i].moves[direction][j].second;
                  if(chess_board[x][y]  >0)
                  {  
                      break; //di theo huong nay khong duoc
                  }
                  else 
                  {     
                        int temp =chess_board[x][y];
                        
                        chess_board[x][y] = 3;
                        if(backtracking(chess_board, moves-1, -1) == 1)
                        {
                           return 1;
                        }
                        chess_board[x][y] = temp;
                        if(temp <0)
                        {
                            break;
                        }
                  }
              }

          }
      }
      //knight moves
      for (int i = 0; i<knights_white.size(); i++)
      {
          for( int direction =0 ;direction < knights_white[i].moves.size(); direction++)
          {
              int x = knights_white[i].x + knights_white[i].moves[direction].first;
              int y = knights_white[i].y + knights_white[i].moves[direction].second;
              if(chess_board[x][y]  >0)
              {
                  break; 
              }
              else
              {        int temp = chess_board[x][y];
                    chess_board[x][y] = 4;
                    if(backtracking(chess_board, moves-1, -1) == 1)
                    {
                       return 1;
                    }
                    chess_board[x][y] = temp;
              }
          }

      }

    }
    else 
    {
      //queen moves 
      for( int direction =0 ;direction < queens_black.moves.size(); direction++)
      {
          for (int i = 0; i<queens_black.moves[direction].size(); i++)
          {
              int x = queens_black.x + queens_black.moves[direction][i].first;
              int y = queens_black.y + queens_black.moves[direction][i].second;
              if(chess_board[x][y]  !=0)
              {
                  break; //di theo huong nay khong duoc
              }
               else
               {     int temp = chess_board[x][y];
                     chess_board[x][y] = -1;
                     if(backtracking(chess_board, moves-1, 1) == 1)
                     {
                        return 1;
                     }
                     chess_board[x][y] = temp;
                     if(temp >0)
                     {
                         break;
                     }
               }
          }

      }
      //rook moves
      for (int i = 0; i<rooks_black.size(); i++)
      {
          for( int direction =0 ;direction < rooks_black[i].moves.size(); direction++)
          {
              for (int j = 0; j<rooks_black[i].moves[direction].size(); j++)
              {
                  int x = rooks_black[i].x + rooks_black[i].moves[direction][j].first;
                  int y = rooks_black[i].y + rooks_black[i].moves[direction][j].second;
                  if(chess_board[x][y]  !=0)
                  {
                      break; //di theo huong nay khong duoc
                  }
                  else
                  {     int temp = chess_board[x][y];
                        chess_board[x][y] = -2;
                        if(backtracking(chess_board, moves-1, 1) == 1)
                        {
                           return 1;
                        }
                        chess_board[x][y] = temp;
                        if(temp >0)
                        {
                            break;
                        }
                  }
              }

          }
      }
      //bishop moves
      for (int i = 0; i<bishops_black.size(); i++)
      {
          for( int direction =0 ;direction < bishops_black[i].moves.size(); direction++)
          {
              for (int j = 0; j<bishops_black[i].moves[direction].size(); j++)
              {
                  int x = bishops_black[i].x + bishops_black[i].moves[direction][j].first;
                  int y = bishops_black[i].y + bishops_black[i].moves[direction][j].second;
                  if(chess_board[x][y]  <0)
                  {  
                      break; //di theo huong nay khong duoc
                  }
                  else 
                  {     
                        int temp =chess_board[x][y];
                        
                        chess_board[x][y] = -3;
                        if(backtracking(chess_board, moves-1, 1) == 1)
                        {
                           return 1;
                        }
                        chess_board[x][y] = temp;
                        if(temp >0)
                        {
                            break;
                        }
                  }
              }
          }
      }
      //knight moves
      for (int i = 0; i<knights_black.size(); i++)
      {
          for( int direction =0 ;direction < knights_black[i].moves.size(); direction++)
          {
              int x = knights_black[i].x + knights_black[i].moves[direction].first;
              int y = knights_black[i].y + knights_black[i].moves[direction].second;
              if(chess_board[x][y]  <0)
              {
                  break; 
              }
              else
              {        int temp = chess_board[x][y];
                    chess_board[x][y] = -4;
                    if(backtracking(chess_board, moves-1, 1) == 1)
                    {
                       return 1;
                    }
                    chess_board[x][y] = temp;
              }
          }

      }
    }
      return 0;

}




string simplifiedChessEngine(vector<vector<char>> whites, vector<vector<char>> blacks, int moves) 
{  
   int chess_board[5][5] ={0};
   for(int i = 0 ;i< whites.size(); i++)
   {
      
         if(whites[i][0] == 'Q')
         {
            chess_board[ whites[i][1] -'A'+1  ][whites[i][2]-'0'] =1;
         }
         else if(whites[i][0] == 'R' )
        {
            chess_board[ whites[i][1] -'A'+1  ][whites[i][2]-'0'] =2;
         }
         else if(whites[i][0] == 'B' )
        {
            chess_board[ whites[i][1] -'A'+1  ][whites[i][2]-'0'] =3;
         }
         else if(whites[i][0] == 'N' )
        {
            chess_board[ whites[i][1] -'A'+1  ][whites[i][2]-'0'] =4;
         }
   }
   for(int i = 0 ;i< blacks.size(); i++)
   {
      
         if(whites[i][0] == 'Q')
         {
            chess_board[ whites[i][1] -'A'+1  ][whites[i][2]-'0'] =11;
         }
         else if(whites[i][0] == 'R' )
        {
            chess_board[ whites[i][1] -'A'+1  ][whites[i][2]-'0'] =-2;
         }
         else if(whites[i][0] == 'B' )
        {
            chess_board[ whites[i][1] -'A'+1  ][whites[i][2]-'0'] =-3;
         }
         else if(whites[i][0] == 'N' )
        {
            chess_board[ whites[i][1] -'A'+1  ][whites[i][2]-'0'] =-4;
         }
   }
   return backtracking(chess_board,moves,1)? "YES": "NO";


}








