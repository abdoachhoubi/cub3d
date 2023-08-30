#include "../../includes/cub.h"

int	set_color(t_game *game, char *attr, char *value)
{
	char		**split_color;
	int			i;

	if (comma_count(value) != 2)
		attr_error(game, 2, NULL);
	split_color = ft_split(value, ',');
	if (ft_arrlen(split_color) != 3)
		attr_error(game, 2, NULL);
	i = 0;
	while (split_color[i])
	{
		if (!check_color(split_color[i]))
			attr_error(game, 2, NULL);
		i++;
	}
	if (!ft_strncmp(attr, "F", 1) && game->floor == -1)
		game->floor = (ft_atoi(split_color[0]) * 256 * 256) + \
			(ft_atoi(split_color[1]) * 256) + ft_atoi(split_color[2]);
	else if (!ft_strncmp(attr, "C", 1) && game->ceiling == -1)
		game->ceiling = (ft_atoi(split_color[0]) * 256 * 256) + \
			(ft_atoi(split_color[1]) * 256) + ft_atoi(split_color[2]);
	else
		attr_error(game, 2, NULL);
	free_arr(split_color);
	return (1);
}

int	check_attr(t_game *game)
{
	if (!game->walls.no_path || !game->walls.so_path
		|| !game->walls.we_path || !game->walls.ea_path
		|| (game->floor == -1)
		|| (game->ceiling == -1))
		return (0);
	return (1);
}

int	get_single_attribute(t_game *game, char **scene, int i)
{
	char	**split_attr;

	if (scene && ft_strlen(scene[i]) < 1)
		return (1);
	split_attr = split_attribute(scene[i]);
	if (ft_arrlen(split_attr) != 2)
		attr_error(game, 1, NULL);
	if (!is_attr(game, split_attr[0], i))
		send_attr_err(game);
	if (scene && scene[i] && comp_attr(split_attr[0]))
	{
		if (!set_attr(game, split_attr[0], split_attr[1]))
			attr_error(game, 0, NULL);
		split_attr = free_arr(split_attr);
	}
	else if (scene && scene[i]
		&& (!ft_strncmp(split_attr[0], "F", ft_strlen(split_attr[0]))
			|| !ft_strncmp(split_attr[0], "C", ft_strlen(split_attr[0]))))
	{
		if (!set_color(game, split_attr[0], split_attr[1]))
			attr_error(game, 1, NULL);
		split_attr = free_arr(split_attr);
	}
	split_attr = free_arr(split_attr);
	return (1);
}

int	get_attributes(t_game *game)
{
	int		i;
	char	**split_scene;

	init_attributes(game);
	i = 0;
	split_scene = ft_split(game->scene, '\n');
	while (split_scene[i])
	{
		get_single_attribute(game, split_scene, i);
		i++;
	}
	free_arr(split_scene);
	return (1);
}

void	close_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] > 2)
			close(arr[i]);
		i++;
	}
}
