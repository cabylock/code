#include<bits/stdc++.h>
using namespace std;


bool check_row(vector<string> &crossword,string words, int i, int j)
{
    if( j + words.size() > 10)
    {
        return false;
    }
      for( int k = 0 ; k < words.size(); k++)
      {
          if( crossword[i][j+k] != '-' && crossword[i][j+k] != words[k]) 
          {
              return false;
          }
      }
      return true;
    
} 

bool check_col(vector<string> &crossword,string words, int i, int j)
{
    if( i + words.size() > 10)
    {
        return false;
    }
      for( int k = 0 ; k < words.size(); k++)
      {
          if( crossword[i+k][j] != '-' && crossword[i+k][j] != words[k]) 
          {
              return false;
          }
      }
      return true;
    
}

void set_row(vector<string> &crossword,string words, int i, int j)
{
    for( int k = 0 ; k < words.size(); k++)
    {
        crossword[i][j+k] = words[k];
    }
}
void set_col(vector<string> &crossword,string words, int i, int j)
{
    for( int k =0; k< words.size(); k++)
    {
      crossword[i+k][j]= words[k];
    }
}
void del_row(vector<string> &crossword,string words, int i, int j)
{
    for( int k = 0 ; k < words.size(); k++)
    {
        crossword[i][j+k] = '-';
    }
}
void del_col(vector<string> &crossword,string words, int i, int j)
{
    for( int k =0; k< words.size(); k++)
    {
      crossword[i+k][j]= '-';
    }
}
 
bool solve( vector<string> &crossword,vector<string> words, int word_number)
{   
    if( word_number == words.size())
    {
        return true;
    }
    string word_current = words[word_number];
    for ( int i = 0 ; i< 10 ; i ++ )
    {
        for ( int j = 0 ; j< 10 ; j++)
        {
            if( check_row(crossword,word_current, i, j))
            {
                set_row(crossword,word_current,i,j);
                if(solve(crossword,words,word_number+1))
                {
                    return true;
                }
                del_row(crossword,word_current,i,j);
            }

            if( check_col(crossword,word_current, i, j))
            {
                set_col(crossword,word_current,i,j);
                if(solve(crossword,words,word_number+1))
                {
                    return true;
                }
                del_col(crossword,word_current,i,j);
            }
            
        }
    }
    return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) 
{   
   vector<string> word ; 
       string text = "";
   for( int i =  0 ; i< words.length(); i++)
   {
       if( words[i] != ';')
       {
           text += words[i];
       }
       else 
       {
           word.push_back(text);
           text ="";
       }
   }
    word.push_back(text);
     solve(crossword,word,0);
     return crossword;
   
}
int main()
{

     vector<string> crossword = {
        "+-++++++++",
        "+-++++++++",
        "+-++++++++",
        "+-----++++",
        "+-+++-++++",
        "+-+++-++++",
        "+++++-++++",
        "++------++",
        "+++++-++++",
        "+++++-++++"
    };

    string words = "LONDON;DELHI;ICELAND;ANKARA";

    vector<string> result = crosswordPuzzle(crossword, words);

    for (const auto& row : result) {
        cout << row << endl;
    }

    return 0;
}