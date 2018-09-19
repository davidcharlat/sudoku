int		check_argv_sudoku (int ac, char **av);
int		print_erreur();
int		print_solution_sudoku(char sol[82]);
int		fill_rank_to_place(int rank_to_place[82], int place_to_rank[81]);
int		preliminary_test (char **av);
void	fill_place_to_rank(int place_to_rank[81], char ***av);

int		verif (int place, char sol[82])
{
	int 	i;
	int 	col;
	int 	line;
	char 	val;
	int		sqrline;
	int		sqrcol;
	
	line = place / 9;
	col = place % 9;
	val = sol[place];
	i = 0;
	while (i < 9)
	{
		if (((sol[line * 9 + i] == val) && (i != col)) ||
			((sol[i * 9 + col] == val) && (i != line)))
			return (0);
		sqrline = line % 3;
		sqrcol = col % 3;
		if ((sol[(line - sqrline + (i / 3)) * 9 + col - sqrcol + i % 3] == val)
				&& (sqrline != i / 3) && (sqrcol != i % 3))
			return (0);
		i++;
	}
	return (1);
}


int		fill_sudoku_tab (char point, char tab[82], char ***av)
{
	int i;
	int j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (j < 9)
		{
			tab[(i - 1) * 9 + j] = (*av)[i][j];
			if (((*av)[i][j] < '1') || ((*av)[i][j] > '9'))
				tab[(i - 1) * 9 + j] = point;
			j++;
		}
	i++;
	}
	return (1);
}

int		verify_inverse (char sol[82], char ***av)
{
	int place;
	int	place_to_rank[81] = {0};
	int	rank_to_place[82] = {0};

	fill_place_to_rank (place_to_rank, av);
	fill_rank_to_place (rank_to_place, place_to_rank);
	place = rank_to_place[1];
	while ((place >= 0) && (place < 81))
	{	
		sol[place]--;
		if (verif (place, sol))
			place = rank_to_place[place_to_rank[place] + 1];
		else 
		{	
			while (sol[place] == '1')
			{
				sol[place] = ':';
				place = rank_to_place[place_to_rank[place] - 1];
			}
		}
	}
	if (place == -1)
		return (0);
	return (1);
}

int		add_and_verify (char sol[82], char ***av)
{
	int place;
	int	place_to_rank[81] = {0};
	int	rank_to_place[82] = {0};

	fill_place_to_rank (place_to_rank, av);
	fill_rank_to_place (rank_to_place, place_to_rank);
	place = rank_to_place[1];
	while ((place >= 0) && (place < 81))
	{	
		sol[place]++;
		if (verif (place, sol))
			place = rank_to_place[place_to_rank[place] + 1];
		else 
		{	
			while (sol[place] == '9')
			{
				sol[place] = '0';
				place = rank_to_place[place_to_rank[place] - 1];
			}
		}
	}
	if (place == -1)
		return (0);
	return (1);
}

int		main (int ac, char **av)
{
	int		i;
	char 	sol[82];
	char 	solbis[82];
	
	i = 0;
	if ((!check_argv_sudoku (ac, av)) || (preliminary_test (av))
		|| (!fill_sudoku_tab ('0',sol, &av))
		|| (!add_and_verify (sol, &av)))
		return (print_erreur());
	fill_sudoku_tab (':',solbis, &av);
	verify_inverse (solbis, &av);
	while (i < 81)
	{
		if (sol[i] != solbis[i])
			return (print_erreur());
		i++;
	}
	return (print_solution_sudoku (sol));
}


