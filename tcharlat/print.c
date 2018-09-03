#include "unistd.h"

void putchar(char c)
{
  write(1, &c, 1);
}

void print_line(char *line)
{
  int i;

  i = 0;
  while (i < 8) {
    putchar(line[i] + '0');
    putchar(' ');
  }
  putchar(line[8] + '0');
  putchar('\n');
}

void print_board(char board[81])
{
  int i;

  i = 0;
  while (i < 9)
    print_line(board + i * 9);
}

int print_error()
{
  write(1, "Erreur\n", 7);
  return 1;
}