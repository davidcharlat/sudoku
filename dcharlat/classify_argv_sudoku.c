#ifndef __CLASSIFY_ARGV_SUDOKU_C__
#define __CLASSIFY_ARGV_SUDOKU_C__

int	sum_point_line(int line, char ***av)
{
	int i;
	int sum;
	
	i = 0;
	sum = 0;
	while (i < 9)
	{
		if ((*av)[line + 1][i++] == '.')
			sum++;
	}
	return (sum);
}

int	*fill_line_order (int **line_order, char ***av)
{
	int	to_find;
	int	classed[9] = {0};
	int i;
	int	cursor_line_order;
	
	cursor_line_order = 0;
	to_find = 0;
	while (to_find <= 9)
	{
		i = 0;
		while (i < 9)
		{
			if ((sum_point_line(i, av) == to_find) && (!classed[i]))
			{
				(*line_order)[cursor_line_order++] = i;
				classed[i] = 1;
				if (sum_point_line((3 * (i / 3) + (i + 1) % 3), av)
						< sum_point_line((3 * (i / 3) + (i + 2) % 3), av))
				{
					(*line_order)[cursor_line_order++] 
						= 3 * (i / 3) + (i + 1) % 3;
					classed[3 * (i / 3) + (i + 1) % 3] = 1;
					(*line_order)[cursor_line_order++] 
						= 3 * (i / 3) + (i + 2) % 3;
					classed[3 * (i / 3) + (i + 2) % 3] = 1;
				}
				else
				{
					(*line_order)[cursor_line_order++] 
						= 3 * (i / 3) + (i + 2) % 3;
					classed[3 * (i / 3) + (i + 2) % 3] = 1;
					(*line_order)[cursor_line_order++] 
						= 3 * (i / 3) + (i + 1) % 3;
					classed[3 * (i / 3) + (i + 1) % 3] = 1;
				}
			}
			i++;
		}
		to_find++;
	}
	return (*line_order);
}

int	*fill_place_to_rank (int **place_to_rank, char ***av)
{
	int	line_order_init[9];
	int *line_order;
	int rank;
	int i;
	int j;
	
	i = 0;
	rank = 1;
	line_order = (int*)line_order_init;
	line_order = fill_line_order (&line_order, av);
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if ((*av)[line_order[i] + 1][j] == '.')
				(*place_to_rank) [9 * line_order[i] + j] = rank++;
			else
				(*place_to_rank) [9 * line_order[i] + j] = 81;
			j++;
		}
		i++;
	}
	return (*place_to_rank);
}

int	*verify_tab_rank_to_place (int **rtp)
{
	int i;
	
	if ((*rtp)[65] != 81)
	{
		i = 1;
		while (i < 82)
			(*rtp)[i++] = -1;
	}
	return (*rtp);
}

int	*fill_rank_to_place (int **rank_to_place, int **place_to_rank)
{
	int rank;
	int i;
	
	i = 1;
	while (i < 82)
	 	(*rank_to_place)[i++] = 81;
	rank = 1;
	(*rank_to_place)[0] = -1;
	while (rank < 81)
	{
		i = 0;
		while (i < 81)
		{
			if ((*place_to_rank)[i] == rank)
			{
				(*rank_to_place)[rank] = i;
				i = 81;
			}
			else i++;
		}
		rank++;
	}
	return (verify_tab_rank_to_place(rank_to_place));
}

# endif
