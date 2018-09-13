int		verify_sudoku_place (int place, char **av)
{
	int 	i;
	int 	col;
	int 	line;
	char	val;

	line = place / 9;
	col = place % 9;
	val = av[1 + line][col];
	i = 0;
	while (i < 9)
	{
		if (((av[1 + line][i] == val) && (i != col)) ||
			((av[1 + i][col] == val) && (i != line)) ||
			((av[1 + line - line % 3 + (i / 3)][col - col % 3 + i % 3] == val)
				&& (line % 3 != i / 3) && (col % 3 != i % 3)))
			return (1);
		i++;
	}
	return (0);
}

int	may_sudoku_be_possible (char **av)
{
	int place;
		
	place = 0;
	while (place < 81)
	{
		if (av[1 + place / 9][place % 9] != '.')
		{
			if (verify_sudoku_place (place, av))
				return (0);
		}
		place++;
	}
	return (1);
}

int	check_argv_sudoku (int ac, char **av)
{
	int i;
	int j;
	
	if (ac != 10)
		return (0);
	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (j < 9)
		{
			if ((av[i][j] != '.') && ((av[i][j] < '1') || (av[i][j] > '9')))
				return (0);
			j++;
		}
		if (av[i][9] != 0)
			return (0);
		i++;
	}
	return ( may_sudoku_be_possible(av));
}
