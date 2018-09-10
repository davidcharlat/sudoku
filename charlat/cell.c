#include "./cell.h"
#include "./libft.h"

unsigned char update_cell(t_cell *cell, unsigned char update)
{
	#ifdef DEBUG
	if (update > 8)	
		return (2);
	#endif
	if (((*cell).has_value != 0) || (((*cell).unavailable)[update] == 1))
		return (0);
	((*cell).unavailable)[update] = 1;
	(*cell).degrees_of_freedom++;
	return (((*cell).degrees_of_freedom > 8)? 1: 0);
}

void initialize_cell(t_cell *cell)
{
	t_cell data;
	ft_memcpy((void*)cell, (void*)&data, sizeof(data));
}
