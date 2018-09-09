#include "../charlat/cell.h"
#include <stdio.h>

unsigned char	update_cell(t_cell *cell, unsigned char update);

int				compare_cell_for_cell_test (t_cell cell, t_cell expected_cell)
{
	int i = 0;
	
	while (i < 9)
		{
		if (cell.unavailable[i] != expected_cell.unavailable[i++])
			return (1);
		}
		if ((cell.degrees_of_freedom != expected_cell.degrees_of_freedom)
			|| (cell.value != expected_cell.value)
			|| (cell.has_value != expected_cell.has_value))
			return (1);
		return (0);
}

int				main(void)
{
	unsigned char	result;
	unsigned char	update;
	t_cell			cell = { { 0 }, 0, 0, 1 };
	t_cell			expected_cell = { { 0 }, 0, 0, 1 };
	t_cell			cell2 = { { 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 1, 0, 0 };
	t_cell			expected_cell2 = { { 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 1, 0, 0 };
	t_cell			cell3 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0, 0, 0 };
	t_cell			expected_cell3 = { { 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 1, 0, 0 };
	t_cell			cell4 = { { 0, 1, 1, 1, 1, 1, 1, 1, 1 }, 8, 0, 0 };
	t_cell			expected_cell4 = { { 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 9, 0, 0 };
	
	update = 9;
	result = update_cell(NULL, update);
	printf ("in debug mode, when call with invalid argument, should return an error\n");
	if (result != 2)
	{
		printf ("error: received %d\n", (int)result);
		return (1);
	}
	printf ("OK\n");
	
	update = 0;
	result = update_cell(&cell, update);
	printf ("when called with a cell which already has value, should return a success and cell should not have changed\n");
	if (result != 0)
	{
		printf ("error: didn't return success\n");
		return (1);
	}
	if (compare_cell_for_cell_test (cell, expected_cell))
	{
		printf ("error: cell value has changed\n");
		return (1);
	}
	printf("OK\n");

	update = 8;
	result = update_cell(&cell2, update);
	printf ("when called with a cell which has no value and the current update is already in the cell unavailabilities, should return a success and cell should not have changed\n");
	if (result != 0)
	{
		printf ("error: didn't return success\n");
		return (1);
	}
	if (compare_cell_for_cell_test (cell2, expected_cell2))
	{
		printf ("error: cell value has changed\n");
		return (1);
	}
	printf ("OK\n");
	
	update = 0;
	result = update_cell(&cell3, update);
	printf ("when called with a cell which has no value and the current update is not yet in the cell unavailabilities and the current update is not the last remaining possible value, should return a success and cell unavailabilities and degrees of freedom should have changed\n");
	if (result != 0)
	{
		printf ("error: didn't return success\n");
		return (1);
	}
	if (compare_cell_for_cell_test (cell3, expected_cell3))
	{
		printf ("error: cell values are not the expected ones\n");
		return (1);
	}
	printf ("OK\n");
	
	update = 0;
	result = update_cell(&cell4, update);
	printf ("when called with a cell which has no value and the current update is not yet in the cell unavailabilities and the current update is the last remaining possible value, should return an error and cell unavailabilities and degrees of freedom should have changed\n");
	if (result != 1)
	{
		printf ("error: did return success\n");
		return (1);
	}
	if (compare_cell_for_cell_test (cell4, expected_cell4))
	{
		printf ("error: cell values are not the expected ones\n");
		return (1);
	}
	printf ("OK\n");
	return(0);
}




