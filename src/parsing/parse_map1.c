#include "../../includes/cub.h"

int	parse_maps(t_game *game)
{
	char	*map;

	map = get_map(game);
	map_list(game, map);
	check_valid_map(game);
	is_surrounded_by_walls(game);
	if (game->player_count < 1)
		exit (write(2, "Error\nNo player found\n", 22));
	if (game->player_count > 1)
		exit (write(2, "Error\nMultiple players found\n", 29));
	game->map = game->maps->map;
	free(map);
	return (0);
}

void	check_valid_map(t_game *game)
{
	t_map	*tmp;
	int		i;
	int		j;

	tmp = game->maps;
	while (tmp)
	{
		i = 0;
		while (tmp->map[i])
		{
			j = 0;
			while (tmp->map[i][j])
			{
				if (!ft_strchr("01NSEW ", tmp->map[i][j]))
					exit (write(2, "Error\nInvalid character\n", 24));
				j++;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int		longest_line(char **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		if ((int)ft_strlen(arr[i]) > j)
			j = ft_strlen(arr[i]);
		i++;
	}
	return (j);
}

char *ft_repeat(int count, char c)
{
	char *str;
	int i;

	i = 0;
	str = ft_calloc(sizeof(char), count + 1);
	while (i < count)
		str[i++] = c;
	return (str);
}

// fill_line_with_spaces at the end of the line
char	*fill_line_with_spaces(char *line, int len)
{
	int i;
	int len_line;
	char *tmp;
	char *tmp2;
	char *res;

	len_line =  ft_strlen(line);
	if (len_line >= len)
		return (ft_strdup(line));
	i = 0;
	res = ft_calloc(sizeof(char), len + 1);
	while (i < len_line)
	{
		res[i] = line[i];
		i++;
	}
	tmp = ft_repeat(len - len_line, ' ');
	tmp2 = ft_strjoin(res, tmp);
	free(res);
	res = ft_strdup(tmp2);
	free(tmp2);
	free(tmp);
	return (res);
}

char **fill_map_with_spaces(char **map)
{
	int i;
	char **new_map;

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
	int	i;
	char **new_map;
	char *tmp;

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

char **clone_arr(char **arr)
{
	int i;
	char **new_arr;

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
		new_map = fill_map_with_spaces(tmp->map);
		free_arr(tmp->map);
		tmp->map = clone_arr(new_map);
		free_arr(new_map);
		new_map = surround_map_with_spaces(tmp->map);
		while (y < ft_arrlen(new_map) - 1)
		{
			x = 1;
			while (x < (int)ft_strlen(new_map[y]) - 1)
			{
				if (ft_strchr("NSEW0", new_map[y][x]))
				{
					if (new_map[y - 1][x] == ' ' || new_map[y + 1][x] == ' ' || new_map[y][x - 1] == ' ' || new_map[y][x + 1] == ' ')
						exit (write(2, "Error\nMap is not surrounded by walls\n", 37));
				}
				if (ft_strchr("NSEW", new_map[y][x]))
					game->player_count++;
				x++;
			}
			y++;
		}
		tmp = tmp->next;
	}
	free_arr(new_map);
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
	int i = 0;

	while (map[i])
	{
		i = store_map_list(game, map, i);
		if (i == -1)
			exit (write(2, "Error\nMemory allocation failed\n", 31));
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
			break;
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

static void	choose_angle(t_game *game, char c)
{
	if (c == 'N')
		game->player->angle = r_angle(90);
	else if (c == 'S')
		game->player->angle = r_angle(270);
	else if (c == 'E')
		game->player->angle = r_angle(0);
	else if (c == 'W')
		game->player->angle = r_angle(180);
}

// sets the player width, height, magnitude, distance to plane, and center
static void	set_player_values(t_game *game)
{
	game->player->width = game->width * TILE_SIZE;
	game->player->height = game->height * TILE_SIZE;
	game->player->mag = MAGNITUDE;
	game->player->dtp = (WIN_W / 2) / ftan(r_angle(30));
	game->player->center = WIN_H / 2;
}

// initialize player
int	player_prologue(t_game *game)
{
	int	i;
	int	j;

	game->player = (t_player *)ft_calloc(sizeof(t_player), 1);
	if (!game->player)
		return (-1);
	set_player_values(game);
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_strchr("NSWE", game->map[i][j]))
			{
				choose_angle(game, game->map[i][j]);
				game->player->point.x = (j * TILE_SIZE) + TILE_SIZE / 2;
				game->player->point.y = (i * TILE_SIZE) + TILE_SIZE / 2;
			}
		}
	}
	return (1);
}