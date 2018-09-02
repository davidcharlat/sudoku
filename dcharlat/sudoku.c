#include "print_result_sudoku.h"
#include "check_argv_sudoku.h"
#include <stdlib.h>
	#include <stdio.h>

void	print_solution_sudoku(char *sol);
void	print_erreur();

int		verif (int place, char **sol)
{
	int 	i;
	int 	col;
	int 	line;
	char 	val;
	int		sqrline;
	int		sqrcol;
	
	line = place / 9;
	col = place % 9;
	val = (*sol)[place];
	i = 0;
	while (i < 9)
	{
		if ((((*sol)[line * 9 + i] == val) && (i != col)) ||
			(((*sol)[i * 9 + col] == val) && (i != line)))
			return (0);
		sqrline = line % 3;
		sqrcol = col % 3;
		if (((*sol)[(line - sqrline + (i / 3)) * 9 + col - sqrcol + i % 3] == val)
				&& (sqrline != i / 3) && (sqrcol != i % 3))
			return (0);
		i++;
	}
	return (1);
}

int		find_prev_place (int place, char ***av)
{
	int i;

	i = 1;
	while (place - i >= 0)
	{
		if((*av)[1 + ((place - i) / 9)][(place - i) % 9] == '.')
			return (place - i);
		i++;
	}
	return (-1);
}

int		find_next_place (int place, char ***av)
{
	int i;

	i = 1;
	while (place + i < 81)
	{
		if((*av)[1 + ((place + i) / 9)][(place + i) % 9] == '.')
			return (place + i);
		i++;
	}
	return (81);
}

char	*add_and_verify (char **sol, char ***av)
{
	int place;
long long count;
	
count = 0;
	place = find_next_place (-1, av);
	while ((place >= 0) && (place < 81))
	{
count++;		
		(*sol)[place]++;
		if (verif (place, sol))
			place = find_next_place (place, av);
		else 
		{	
			while ((*sol)[place] == '9')
			{
				(*sol)[place] = '0';
				place = find_prev_place (place, av);
			}
		}
	}
printf ("solved with %lld trials", count);
	if (place == -1)
		return (NULL);
	return (*sol);
}

void	main (int ac, char **av)
{
	int		i;
	int		j;
	char*sol;
	char t[82];
	
	if (check_argv_sudoku (ac, av))
	{
		sol =(char*) t;
		i = 1;
		while (i <= 9)
		{
			j = 0;
			while (j < 9)
			{
				sol[(i - 1) * 9 + j] = av[i][j];
				if ((av[i][j] < '1') || (av[i][j] > '9'))
					sol[(i - 1) * 9 + j] = '0';
				j++;
			}
		i++;
		}
		sol = add_and_verify (&sol, &av);
		(sol ? print_solution_sudoku (sol) : print_erreur ());
	}
	else print_erreur();
}

