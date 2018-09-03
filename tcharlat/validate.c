void set_unavailable(int position, char board[81], char available[9]);

int validate_position(int position, char board[81])
{
  char available[9] = { 0 };
  unsigned char current;

  current = board[position];
  board[position] = 0;
  set_unavailable(position, board, available);
  board[position] = current;
  if (available[current - 1] == 0)
    return 0;
  return 1;
}

int validate_board(char board[81])
{
  int i;

  i = 0;
  while (i < 81)
  {
    if(board[i] != 0)
    {
      if(validate_position(i, board))
        return 1;
    }
    i++;
  }
  return 0;
}
