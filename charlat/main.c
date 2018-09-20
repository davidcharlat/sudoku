#include "./board.h"
#include "./cell.h"
#include "./preliminary_test.h"

int	main(int argc, char **argv)
{
	t_cell			board[81];
	t_cell			reverse_board[81];
	unsigned char	remaining;
	unsigned char	path[81] = { 0 };

	remaining = 81;
	initialize_board(board);
	// argc invalid -> return INVALID_ARG_NUMBER
	// if parse_arg(board, &remaining) -> return INVALID_ARG_BOARD
	// if (preliminary_test (argv)) -> BOARD CAN'T HAVE A UNIQUE SOLUTION
	// copy_board(reverse_board, board)
	// inverse_board(reverse_board)
	// if solve_board_pathg_out(board, path, remaining) -> return BOARD_HAS_NO_SOLUTION
	// if solve_board_path_in(reverse_board, path, remaining) -> return BOARD_HAS_NO_SOLUTION
	// inverse_board(reverse_board)
	// if compare_board(reverse_board, board) return BOARD_SOLUTION_IS_NOT_UNIQUE
	return (0);
}
