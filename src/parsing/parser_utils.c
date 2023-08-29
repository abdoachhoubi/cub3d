#include "../../includes/cub.h"

int	count_lines(const char *s)
{
	int	i;
	int	j;

	if (!s)
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] == '\n')
			j++;
	}
	return (j);
}

char	**free_arr(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
