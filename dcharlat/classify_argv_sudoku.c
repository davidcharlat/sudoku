#ifndef __CLASSIFY_ARGV_SUDOKU_C__
#define __CLASSIFY_ARGV_SUDOKU_C__

	#include <stdio.h>

char	*fill_sudoku_tab (char point, char **tab, char ***av);
void 	fill_graph(unsigned char graph[81][20]);

int	*fill_place_to_rank (int **place_to_rank, char ***av)
{
	unsigned char graph[81][20];
	int rank;
	int count;
	int place;
	int degrees;
	int degree_max;
	int place_of_max;
	char *tab;
	char t[82];
	int i;
	
	rank = 1;
	count = 0;
	tab = (char*)t;
	tab = fill_sudoku_tab ('.',&tab, av);
	place = 0;
	fill_graph(graph);
	while (place < 81)
	{
		if (tab[place] != '.')
		{
			(*place_to_rank)[place] = 81;
			count++;
//printf ("count: %d\n", count);
		}
		place++;
	}
	while (count < 81)
	{
		place_of_max = 0;
		place = 0;
		degree_max = 0;
		while (place < 81)
		{
			i = 0;
			if (tab[place] == '.')
			{
				degrees = 0;
				while (i < 20)
				{
					if (tab[graph[place][i++]] != '.')
						degrees++;
				}
				if (degrees >= degree_max)
				{
					degree_max = degrees;
					place_of_max = place;
				}
			}
			place++;
		}
		tab[place_of_max] = '0';
		(*place_to_rank)[place_of_max] = rank++;
		count++;
//printf ("count: %d\n", count);
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
