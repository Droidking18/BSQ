#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utility.h"
#include "validator.h"
#define BUFF_SIZE 100000000

int	main(void)
{
	char *str;

	str = (char*)malloc(sizeof(char) * BUFF_SIZE);
	read(0, str, BUFF_SIZE);
	if (!ft_check_map_length(str) || !ft_check_valid_char(str) || !ft_check_free_space(str))
	{
		printf("map error\n");
	}
	free(str);
	return (0);
}
