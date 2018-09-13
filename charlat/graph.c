void  fill_graph_node(unsigned char pos, unsigned char row, unsigned char col, char node[20])
{
	unsigned char	edge;
	unsigned char	edge_row;
	unsigned char	edge_col;
	unsigned char	edge_pos;
	unsigned char	next;

	next = 0;
	edge = 0;
	edge_row = 0;
	edge_pos = 0;
	while (edge_row < 9)
	{
		edge_col = 0;
		while (edge_col < 9)
		{
			if (
				edge_pos != pos &&
				(edge_row == row || edge_col == col ||
					(edge_row / 3 == row / 3 && edge_col / 3 == col / 3)
				)
			)
				node[next++] = edge_pos;
			edge_pos++;
			edge_col++;
		}
		edge_row++;
	}
}

void  fill_graph(unsigned char graph[81][20])
{
	unsigned char	position;
	unsigned char	row;
	unsigned char	col;

	position = 0;
	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			fill_graph_node(position, row, col, graph[position]);
			col++;
			position++;
		}
		row++;
	}
}
