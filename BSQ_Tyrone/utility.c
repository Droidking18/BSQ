#include "utility.h"
#include "validator.h"

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
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
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
	return (i);		//return the value for the start of the map excl the title
}

void	ft_find_valid_char(char *str, char *empty, char *obs, char *square)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || ft_isdigit(str[i]))
		i++;
	*empty = str[i];
	*obs = str[i + 1];
	*square = str[i + 2];		//assume that the characters come in order after the digit
}
