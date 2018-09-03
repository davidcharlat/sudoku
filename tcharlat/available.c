void set_unavailable_row(int position, char board[81], char available[9])
{
  int row;
  int i;
  char value;

  row = position / 9;
  i = 0;
  while (i < 9)
  {
    value = board[row * 9 + i];
    if (value != 0)
      available[value - 1] = 1;
    i++;
  }
}

void set_unavailable_col(int position, char board[81], char available[9])
{
  int col;
  int i;
  char value;

  col = position % 9;
  i = 0;
  while (i < 9)
  {
    value = board[i * 9 + col];
    if (value != 0)
      available[value - 1] = 1;
    i++;
  }
}

void set_unavailable_square(int position, char board[81], char available[9])
{
  int square_row;
  int square_col;
  int i;
  int j;
  char value;

  square_row = (position / 9) / 3;
  square_col = (position % 9) / 3;
  i = 0;
  while (i < 3)
  {
    j = 0;
    while (j < 3)
    {
      value = board[(square_row * 3 + i) * 9 + square_col * 3 + j];
      if (value != 0)
        available[value - 1] = 1;
      j++;
    }
    i++;
  }
}

void set_unavailable(int position, char board[81], char available[9])
{
  set_unavailable_row(position, board, available);
  set_unavailable_col(position, board, available);
  set_unavailable_square(position, board, available);
}