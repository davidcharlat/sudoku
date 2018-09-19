int	check_8 (char **av)
{
	int	i;
	int	j;
	int	found[9] = {0};
	int count;
	
	count = 0;
	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (j < 9)
		{
			if ((av[i][j] != '.') && (found[av[i][j] - '1'] == 0))
			{
				found[av[i][j] - '1'] = 1;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count < 8)
		return (1);
	return (0);
}

int	check_17cells (char **av)
{
	int	i;
	int	j;
	int count;
	
	count = 0;
	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (j < 9)
		{
			if (av[i][j] != '.')
				count++;
			j++;
		}
		i++;
	}
	if (count < 17)
		return (1);
	return (0);
}

int	preliminary_test (char **av)
{
	return (check_8 (av)  + check_17cells (av));
} 
