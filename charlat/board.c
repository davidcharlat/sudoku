#include "./board.h"
#include "./cell.h"

void initialize_board(t_cell board[81])
{
	int	i;

	i = 0;
	while (i < 81)
		initialize_cell(board + i++);
}
