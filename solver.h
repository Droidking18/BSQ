/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:15:59 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/07 10:16:04 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

int		min(int a, int b, int c);
void	convert(int **grid, int row, int col);
int		*largest_number(int **grid, int x, int y);
int		solver(int **grid, int a, int b, int *largest);

#endif
