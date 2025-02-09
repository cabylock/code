#include<iostream> 
#include<vector>
using namespace std; 

int running = 1;
void printBoard( vector<vector<char>> board)
{
   for( int i = 0 ; i< 3 ; i++)
   {
      for( int j = 0 ; j< 3 ; j++)
      {
         cout<<board[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<endl;
}


int check( vector<vector<char>> board )
{  // 1 -> player 1  // -1-> player2  // 0 -> hòa 
   // check hàng 
   for( int i = 0 ; i< 3 ; i++)
   {
      if( board[i][0]   == board[i][1] && board[i][0]  == board[i][2]) 
      {
         if(  board[i][0] == 'x')
         {
            return 1;
         }
         else if( board[i][0] == 'o')
         {
            return -1 ;
         }
      }
   }
   // check cột 
   for( int i = 0 ; i< 3 ; i++)
   {
      if( board[0][i]   == board[1][i] && board[0][i]  == board[2][i]) 
      {
         if(  board[0][i] == 'x')
         {
            return 1;
         }
         else if( board[0][i] == 'o')
         {
            return -1 ;
         }
      }
   }
   
   //check chéo 
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      if( board[0][0] == 'x')
      {
         return 1;
      }
      else if( board[0][0] == 'o') 
      {
         return -1;
      }
   }
   //check chéo
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      if( board[0][2] == 'x')
      {
         return 1;
      }
      else if( board[0][2] == 'o')
      {
         return -1;
      }
   }
   return 0 ; 


}

// kiểm tra xem còn di chuyển nào không
bool isMovesLeft( vector<vector<char>> board )
{
   for( int i = 0 ; i< 3 ; i++)
   {
      for( int j = 0 ; j< 3 ; j++)
      {
         if( board[i][j] == '_')
         {
            return true;
         }
      }
   }
   return false;
}

int minimax ( vector<vector<char>> board, int player )
{  // player1
      int score = check(board);
      if( score == 1)
         {
            return 1;
         }
      if( score == -1)
         {
            return -1;
         }
      if( isMovesLeft(board) == false) return 0 ;
      if(player == 1)
      {
         int best = INT_MIN;
         for( int i = 0 ; i< 3 ; i++)
         {
            for( int j = 0 ; j< 3 ; j++)
            {
               if( board[i][j] == '_')
               {
                  board[i][j] = 'x';
                  best = max( best, minimax(board, -player));
                  board[i][j] = '_';
               }
            }
         }
         return best;
      }
      else 
      {  
         //player 2
         int best = INT_MAX;
         for( int i = 0 ; i< 3 ; i++)
         {
            for( int j = 0 ; j< 3 ; j++)
            {
               if( board[i][j] == '_')
               {
                  board[i][j] = 'o';
                  best = min( best, minimax(board, -player));
                  
                  board[i][j] = '_';
               }
            }
         }
         return best;
      }
   
}


void findBestMove( vector<vector<char>> &board, int player)
{  
   if(check(board) == 1)
   {
      cout<<"Player 1-> x win"<<endl; running = 0;
      return  ;
   }
   if(check(board) == -1)
   {
      cout<<"Player 2-> o win"<<endl; running = 0;
      return  ;
   }
   if(isMovesLeft(board) == false) 
   {
      cout<<"Hòa"<<endl; running = 0;
      return  ;
   }
   if(player ==1 )
   {
      int bestVal = INT_MIN;
      pair<int,int> bestMove;
      for( int i = 0 ; i< 3 ; i++)
      {
         for( int j = 0 ; j< 3 ; j++)
         {
            if( board[i][j] == '_')
            {
               board[i][j] = 'x';
               int moveVal = minimax(board, -player);
               board[i][j] = '_';
               if( moveVal > bestVal)
               {
                  bestMove = {i,j};
                  bestVal = moveVal;
               }
            }
         }
      }
      
      board[bestMove.first][bestMove.second] = 'x';
     
      printBoard(board);
      findBestMove(board, -player);
   }
   /* else 
   {
      int bestVal = INT_MAX;
      pair<int,int> bestMove;
      for( int i = 0 ; i< 3 ; i++)
      {
         for( int j = 0 ; j< 3 ; j++)
         {
            if( board[i][j] == '_')
            {
               board[i][j] = 'o';
               int moveVal = minimax(board, -player);
               board[i][j] = '_';
               if( moveVal < bestVal)
               {
                  bestMove = {i,j};
                  bestVal = moveVal;
               }
            }
         }
      }
      
      board[bestMove.first][bestMove.second] = 'o';
      
      printBoard(board);
      findBestMove(board, -player);
   }
   */
   
}



int main()
{

      vector<vector<char>> board ; 
      for( int i = 0 ; i< 3 ; i++)
      {
         vector<char> temp;
         for( int j = 0 ; j< 3 ; j++)
         {
            temp.push_back('_');
         }
         board.push_back(temp);
      }


      while(true )
      {
         findBestMove(board, 1);
         if( running == 0) break;
         int x,y;
         while( true)
         {
            cout<<"Nhập vị trí x y: ";
            cin>>x>>y;
            if( x>=0 && x<3 && y>=0 && y<3 && board[x][y] == '_') break;
            cout<<"Nhập lại"<<endl;
         }
         board[x][y] = 'o';
         printBoard(board);
      }
   
}

