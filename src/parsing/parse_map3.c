#include "../../includes/cub.h"

void	check_player(t_game *game, char **map, int x, int y)
{
	if (ft_strchr("NSEW0", map[y][x]))
	{
		if (check_surroundings(map, x, y))
			exit (ft_puts(RED"Error\nMap not surrounded by walls"RESET, 2));
	}
	if (ft_strchr("NSEW", map[y][x]))
		game->player_count++;
}

void	is_surrounded_by_walls(t_game *game)
{
	int		y;
	int		x;
	t_map	*tmp;
	char	**new_map;

	tmp = game->maps;
	while (tmp)
	{
		y = 1;
		new_map = fill_map(tmp->map, tmp);
		while (y < ft_arrlen(new_map) - 1)
		{
			x = 1;
			while (x < (int)ft_strlen(new_map[y]) - 1)
			{
				check_player(game, new_map, x, y);
				x++;
			}
			y++;
		}
		free_arr(new_map);
		tmp = tmp->next;
	}
}

char	*get_map(t_game *game)
{
	int		i;
	int		j;
	char	*map;

	i = 0;
	j = 0;
	while (game->scene[i] && j < game->map_start)
	{
		i++;
		if (game->scene[i] == '\n' && game->scene[i + 1] != '\n')
			j++;
	}
	map = ft_substr(game->scene, i, ft_strlen(game->scene));
	return (map);
}

int	map_list(t_game *game, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i = store_map_list(game, map, i);
		if (i == -1)
			exit (ft_puts(RED"Error\nMemory allocation failed", 2));
	}
	return (1);
}

int	store_map_list(t_game *game, char *maps, int i)
{
	char	*tmp;
	char	**sub_map;
	int		j;

	while (maps[i] && maps[i] == '\n')
		i++;
	if (!maps[i])
		return (i);
	j = i;
	while (maps[i])
	{
		if (maps[i] == '\n' && (maps[i + 1] == '\n' || !maps[i + 1]))
			break ;
		i++;
	}
	tmp = ft_substr(maps, j, i - j);
	if (!tmp)
		return (-1);
	sub_map = ft_split(tmp, '\n');
	if (!sub_map)
		return (-1);
	add_map(&game->maps, new_map(sub_map));
	free(tmp);
	return (i);
}
