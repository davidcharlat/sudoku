#include <stdio.h>

void	fill_graph_node( unsigned char pos, unsigned char row, unsigned char col, char node[20]);
void	fill_graph(char graph[81][20]);

int		main(void)
{
	char	case0[20];
	char	case50[20];
	char	graph[81][20];
	char	sol_case0[20] = {1,2,3,4,5,6,7,8,9,10,11,18,19,20,27,36,45,54,63,72};
	char	sol_case50[20] = {5,14,23,30,31,32,39,40,41,45,46,47,48,49,51,52,53,59,68,77};
	char	sol_case80[20] = {8,17,26,35,44,53,60,61,62,69,70,71,72,73,74,75,76,77,78,79};
	int 	i;

	i = 0;
	fill_graph_node((unsigned char)0,(unsigned char)0,(unsigned char)0,case0);
	fill_graph_node((unsigned char)50,(unsigned char)5,(unsigned char)5,case50);
	printf("testing function fill_graph_node\n");
	printf("testing case0\n");
	while (i < 20)
	{
		if (case0[i] != sol_case0[i++])
		{	
			printf ("case0[%d] = %d instead of %d\n", i - 1, (int)case0[i-1], (int)sol_case0[i-1]);
			return(1);
		}
	}
	printf("fill_graph_node ok for case0 \n");
	printf("testing case50\n");
	i = 0;
	while (i < 20)
	{
		if (case50[i] != sol_case50[i++])
		{	
			printf ("case50[%d] = %d instead of %d\n", i - 1, (int)case50[i-1], (int)sol_case50[i-1]);
			return(1);
		}
	}
	printf("fill_graph_node ok for case50\n");
	printf("testing function fill_graph\n");
	fill_graph(graph);
	i = 0;
	printf("testing row 0\n");
	while (i < 20)
	{
		if (graph[0][i] != sol_case0[i++])
		{	
			printf ("graph[0][%d] = %d instead of %d\n", i - 1, (int)graph[0][i-1], (int)sol_case0[i-1]);
			return(1);
		}
	}
	printf("testing row 50\n");
	i = 0;
	while (i < 20)
	{
		if (graph[50][i] != sol_case50[i++])
		{	
			printf ("graph[50][%d] = %d instead of %d\n", i - 1, (int)graph[50][i-1], (int)sol_case50[i-1]);
			return(1);
		}
	}
	i = 0;
	printf("testing row 80\n");
	while (i < 20)
	{
		if (graph[80][i] != sol_case80[i++])
		{	
			printf ("graph[80][%d] = %d instead of %d\n", i - 1, (int)graph[80][i-1], (int)sol_case80[i-1]);
			return(1);
		}
	}
	printf("OK\n");
	return(0);
}




