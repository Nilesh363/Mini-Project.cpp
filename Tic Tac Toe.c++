#include<iostream>
using namespace std;
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;
void drawboard ()
{
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]<< " | " << endl;
  cout << "------------\n";
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2]<< " | " << endl;
  cout << "------------\n";
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2]<< " | " << endl;
}
bool place_marker (int slot)
{
  int row = slot / 3;
  int col;
  if (slot % 3 == 0)
    {
      row = row - 1;
      col = 2;
    }
  else
    col = (slot % 3) - 1;
   if(board[row][col]!='x' && board [row][col] !='o')
  {
      board[row][col] = current_marker;
      return true;
  }
  else return false;
}
int winner ()
{
  for (int i = 0; i < 3; i++)
    {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
	return current_player;
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
	return current_player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;
  return 0;
}
void swap_player_and_marker ()
{
  if (current_marker == 'x')
    current_marker = 'o';
  else
    current_marker = 'x';
  if (current_player == 1)
    current_player = 2;
  else
    current_player = 1;
}
void game ()
{
  cout << "Player one, choose your marker ('x' or 'o'): ";
  char marker_p1;
  cin >> marker_p1;
  current_player = 1;
  current_marker = marker_p1;
  drawboard ();
  int player_won;
  for (int i = 0; i < 9; i++)
    {
      cout << "Its player " << current_player <<" turn, Enter your slot: ";
      int slot;
      cin >> slot;
      if (slot < 1 || slot > 9)
	  {
        cout << "invalid slot, slot must be between one to nine\n";
        i--;
        continue;
	  }
      if(!place_marker (slot))
     {
        cout << "This slot is occupied, try another slot!" << endl;
        i--;
        continue;
     }
     drawboard ();
      player_won = winner ();
      if (player_won == 1)
	  {
        cout << "Player One Won ! WINNER WINNER CHICKEN DINNER !";
        break;
	  }
      if (player_won == 2)
	  {
        cout << "Player Two Won ! WINNER WINNER CHICKEN DINNER !";
        break;
	  }
        swap_player_and_marker ();
      }
      if (player_won == 0)
      {
        cout << "Oops! nobody win";
      }
}
int main()
{
  game();
  return 0;
}
