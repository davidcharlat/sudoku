#ifndef __PRINT_RESULT_SUDOKU_H__
#define __PRINT_RESULT_SUDOKU_H__

# include <stdlib.h>
# include "write.h"

void ft_putchar(char c)
{
		write(1, &c, 1);
}

void	print_solution_sudoku (char *sol)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar (sol[i * 9 + j]);
			ft_putchar (' ');
			j++;
		}
		ft_putchar ('\n');
		i++;
	}
	ft_putchar ('\n');
	i = 0;
}

void	print_erreur()
{
	write (1, "erreur\n", 7);
}

#endif
