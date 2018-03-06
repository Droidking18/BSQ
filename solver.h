#ifndef SOLVER_H
# define SOLVER_H

int		min(int a, int b, int c);
void	convert(int **grid, int row, int col);
int		*largest_number(int **grid, int x, int y);
int		solver(int **grid, int a, int b, int *largest);

#endif
