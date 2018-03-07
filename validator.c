/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:17:51 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/07 10:18:28 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include "validator.h"
#include "converter.h"
#include <stdio.h>

int	ft_count_line_length(char *str, int *i)
{
	int counter;

	counter = 0;
	while (str[*i] != '\n')
	{
		counter++;
		(*i)++;
	}
	(*i)++;
	return (counter);
}

int	ft_get_rows(char *str)
{
	int row;
	int i;
	int counter;

	row = ft_atoi(str);
	i = ft_find_map_start(str);
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			counter++;
		i++;
	}
	if (counter != row)
		return (0);
	else
		return (row);
}

int	ft_check_map_length(char *str)
{
	int i;
	int line_length;
	int check_length;

	i = ft_find_map_start(str);
	line_length = ft_count_line_length(str, &i);
	while (str[i] != '\0')
	{
		check_length = ft_count_line_length(str, &i);
		if (check_length != line_length)
			return (0);
	}
	return (line_length);
}

int	ft_check_free_space(char *str)
{
	char	e;
	char	o;
	char	s;
	int		i;
	int		free_space;

	ft_find_valid_char(str, &e, &o, &s);
	i = ft_find_map_start(str);
	free_space = 0;
	while (str[i] != '\0')
	{
		if (str[i] == e)
			free_space = 1;
		i++;
	}
	if (free_space)
		return (1);
	else
		return (0);
}

int	ft_check_valid_char(char *str)
{
	char	e;
	char	o;
	char	s;
	int		i;

	i = ft_find_map_start(str);
	ft_find_valid_char(str, &e, &o, &s);
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != e && str[i] != o
			&& str[i] != s && str[i] != '\0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
