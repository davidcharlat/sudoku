#ifndef CELL_H
# define CELL_H

typedef struct	s_cell
{
unsigned char	unavailable[9];
unsigned char	degrees_of_freedom;
unsigned char	value;
unsigned char	has_value;
} 				t_cell;$
/*
** degrees_of_freedom is 0 when all values are possible, 9 when no more values are possible.
** unavailable[x] == 1 means the value x is not available
** unavailable[x] == 0 means the value x is available
** unavailable[x] should never be > 1
** sum of unavailable from 0 to 8 should equal degrees_of_freedom
*/

#endif /* !CELL_H */


