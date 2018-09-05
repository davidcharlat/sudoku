void set_unavailable(int position, char board[81], char available[9]);

int solve(int position, char board[81])
{
  char available[9] = { 0 };
  unsigned char i;

  if (position == 81)
    return 0;
  if (board[position] != 0)
    return solve(position + 1, board);
  set_unavailable(position, board, available);
  i = 0;
  while (i < 9)
  {
    if(available[i] == 0)
    {
      board[position] = i + 1;
      if(solve(position + 1, board) == 0)
        return 0;
    }
    i++;
  }
  board[position] = 0;
  return 1;
}
