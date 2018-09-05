int solve(int position, char board[81]);
int validate_board(char board[81]);
void print_board(char board[81]);
int print_error();

int create_board(char *src, char *dest, int size)
{
  while(size--)
  {
    if (src[size] == '.')
      dest[size] = 0;
    else if (src[size] >= '1' && src[size] <= '9')
      dest[size] = src[size] - '0';
    else
      return 1;
  }
  return 0;
}

void inverse_board(char board[81])
{
  int i;

  i = 0;
  while (i < 81)
  {
    if (board[i] != 0)
      board[i] = 10 - board[i];
    i++;
  }
}

void copy_board(char original[81], char copy[81])
{
  int i;

  i = 0;
  while (i < 81)
  {
    copy[i] = original[i];
    i++;
  }
}

int compare_board(char board[81], char board_reverse[81])
{
  int i;
  i = 0;
  while (i < 81)
  {
    if (board[i] != board_reverse[i])
      return 1;
    i++;
  }
  return 0;
}

int main(int argc, char **argv) {
  char board[81];
  char board_reverse[81];
  int row = 0;

  if (argc != 10)
    return print_error();
  row = 0;
  while(row < 9)
  {
    if (create_board(argv[row + 1], board + (9 * row), 9))
      return print_error();
    row++;
  }
  if (validate_board(board))
    return print_error();
  copy_board(board, board_reverse);
  inverse_board(board_reverse);

  if (solve(0, board))
    return print_error();
  if (solve(0, board_reverse))
    return print_error();
  inverse_board(board_reverse);
  if (compare_board(board, board_reverse))
    return print_error();
  print_board(board);
  return 0;
}
