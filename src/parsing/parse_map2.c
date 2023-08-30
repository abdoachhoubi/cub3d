#include "../../includes/cub.h"

char	**fill_map_with_spaces(char **map)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = ft_calloc(sizeof(char *), ft_arrlen(map) + 1);
	while (map[i])
	{
		new_map[i] = fill_line_with_spaces(map[i], longest_line(map));
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

char	**surround_map_with_spaces(char **map)
{
	int		i;
	char	**new_map;
	char	*tmp;

	i = 0;
	new_map = ft_calloc(sizeof(char *), ft_arrlen(map) + 3);
	new_map[i++] = ft_repeat(longest_line(map) + 2, ' ');
	while (map[i - 1])
	{
		tmp = ft_strjoin(" ", map[i - 1]);
		new_map[i] = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	new_map[i] = ft_repeat(longest_line(map) + 2, ' ');
	new_map[i + 1] = NULL;
	return (new_map);
}

char	**clone_arr(char **arr)
{
	int		i;
	char	**new_arr;

	i = 0;
	new_arr = ft_calloc(sizeof(char *), ft_arrlen(arr) + 1);
	while (arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

int	check_surroundings(char **map, int x, int y)
{
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (1);
	return (0);
}

char	**fill_map(char **map, t_map *tmp)
{
	char	**new_m;
	char	**new_tmp;

	new_tmp = fill_map_with_spaces(map);
	free_arr(tmp->map);
	tmp->map = clone_arr(new_tmp);
	new_m = surround_map_with_spaces(new_tmp);
	free_arr(new_tmp);
	return (new_m);
}
