/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:17:33 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/07 10:17:35 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include "validator.h"
#include <stdio.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int total;
	int sign;
	int i;

	i = 0;
	total = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		return (0);
	}
	while (ft_isdigit(str[i]))
	{
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	return (total * sign);
}

int	ft_find_map_start(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	i++;
	return (i);
}

int	ft_find_valid_char(char *str, char *empty, char *obs, char *square)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1] == 'o' && str[i + 2] == 'x')
	{
		*empty = '.';
		*obs = 'o';
		*square = 'x';
		return (1);
	}
	return (0);
}
