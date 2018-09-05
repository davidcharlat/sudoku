#include "unistd.h"

int ft_putchar(char c)
{
  return write(1, &c, 1);
}

int print_line(char *line)
{
  int i;
  int error = 0;

  i = 0;
  while (i < 8) {
    error &= ft_putchar(line[i] + '0');
    error &= ft_putchar(' ');
    i++;
  }
  error &= ft_putchar(line[8] + '0');
  error &= ft_putchar('\n');
  return error;
}

int print_board(char board[81])
{
  int i;
  int error = 0;

  i = 0;
  while (i < 9)
    error &= print_line(board + i++ * 9);
  return error;
}

int print_error(void)
{
  return 1 & write(1, "Erreur\n", 7);
}