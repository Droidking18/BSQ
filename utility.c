/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:17:33 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/09 08:37:33 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include "validator.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_atoi(char *str)
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	return (total * sign);
}

int		ft_find_map_start(char *str)
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

int		ft_find_valid_char(char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.' && str[i + 1] == 'o' && str[i + 2] == 'x')
	{
		return (1);
	}
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
