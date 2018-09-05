#include "unistd.h"

void ft_putchar(char c)
{
  (void) write(1, &c, 1);
}

void print_line(char *line)
{
  int i;

  i = 0;
  while (i < 8) {
    ft_putchar(line[i] + '0');
    ft_putchar(' ');
    i++;
  }
  ft_putchar(line[8] + '0');
  ft_putchar('\n');
}

void print_board(char board[81])
{
  int i;

  i = 0;
  while (i < 9)
    print_line(board + i++ * 9);
}

int print_error()
{
  (void) write(1, "Erreur\n", 7);
  return 1;
}