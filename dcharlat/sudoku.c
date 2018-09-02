#include "print_result_sudoku.h"
#include "check_argv_sudoku.h"
#include <stdlib.h>
	#include <stdio.h>

void	print_solution(char **sol);
void	print_erreur();

int		verif (int place, char ***sol)
{
	int i;
	int col;
	int line;
	int val;

	line = place / 9;
	col = place % 9;
	val = (*sol)[line][col];
	i = 0;
	while (i < 9)
	{
		if ((((*sol)[line][i] == val) && (i != col)) ||
			(((*sol)[i][col] == val) && (i != line)) ||
			(((*sol)[line - line % 3 + (i / 3)][col - col % 3 + i % 3] == val)
				&& (line % 3 != i / 3) && (col % 3 != i % 3)))
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

char	**add_and_verify (char ***sol, char ***av)
{
	int place;
long long count;
	
count = 0;
	place = find_next_place (-1, av);
	while ((place >= 0) && (place < 81))
	{
count++;		
		(*sol)[place / 9][place % 9]++;
		if (verif (place, sol))
			place = find_next_place (place, av);
		else 
		{	
			while ((*sol)[place / 9][place % 9] == '9')
			{
				(*sol)[place /9][place % 9] = '0';
				place = find_prev_place (place, av);
			}
		}
	}
printf ("solved with %lld trials", count);
	if (place == -1)
	{
		while (++place < 9)
			free ((*sol)[place]);
		free (*sol);	
		return (NULL);
	}
	return (*sol);
}

void	main (int ac, char **av)
{
	int		i;
	int		j;
	char	**sol;
	
	if (check_argv_sudoku (ac, av))
	{
		sol = (char**)malloc((sizeof(char*)) * 10);
		i = 1;
		while (i <= 9)
		{
			sol[i - 1] = (char*)malloc((sizeof(char)) * 10);
			j = 0;
			while (j < 9)
			{
				sol[i - 1][j] = av[i][j];
				if ((av[i][j] < '1') || (av[i][j] > '9'))
					sol[i - 1][j] = '0';
				j++;
			}
		i++;
		}
		sol = add_and_verify (&sol, &av);
		(sol ? free_and_print_solution_sudoku (sol) : print_erreur ());
	}
	else print_erreur();
}
