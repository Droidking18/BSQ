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
	(*i)++;			//change i by reference to start of new line or null for the end of the map
	return (counter);
}

int	ft_get_rows(char *str)
{
	int row;
	int i;
	int counter;

	row = ft_atoi(str);			//get number of rows from file start
	i = ft_find_map_start(str);		//and check that rows match \n's
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

	i = ft_find_map_start(str);			//start at the beginning of map
	line_length = ft_count_line_length(str, &i);
	while (str[i] != '\0')
	{
		check_length = ft_count_line_length(str, &i);	//check each line for same length
		if (check_length != line_length)
			return (0);
	}
	return (line_length);
}

int	ft_check_free_space(char *str)
{
	char e;
	char o;
	char s;
	int i;
	int free_space;

	ft_find_valid_char(str, &e, &o, &s);
	i = ft_find_map_start(str);
	free_space = 0;
	while (str[i] != '\0')
	{
		if (str[i] == e)
			free_space = 1;			//check whether at least 1 cell has a empty
		i++;
	}
	if (free_space)
		return (1);
	else
		return (0);
}


int	ft_check_valid_char(char *str)
{
	char e;
	char o;					//checks whether each cell contains only \n, e, o or s
	char s;					//maybe only check \n e or o .... not s as well
	int i;

	i = ft_find_map_start(str);
	ft_find_valid_char(str, &e, &o, &s);
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != e && str[i] != o
			&& str[i] != s && str[i] != '\0')
		{
			printf("empty: %c obs: %c sq: %c str[i]: %c\n", e, o , s, str[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
