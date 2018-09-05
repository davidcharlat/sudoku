#ifndef __PRINT_RESULT_SUDOKU_C__
#define __PRINT_RESULT_SUDOKU_C__

# include <stdlib.h>
# include "write.c"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	print_solution_sudoku (char *sol)
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
			if (j != 9)
				ft_putchar (' ');
			j++;
		}
		ft_putchar ('\n');
		i++;
	}
	return (0);
}

int	print_erreur()
{
	return (write (1, "Erreur\n", 7) + 1);
}

#endif
