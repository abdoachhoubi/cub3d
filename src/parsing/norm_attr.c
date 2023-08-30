#include "../../includes/cub.h"

int	comp_attr_clrs(char *s)
{
	if (!ft_strncmp(s, "NO", ft_strlen(s))
		|| !ft_strncmp(s, "SO", ft_strlen(s))
		|| !ft_strncmp(s, "WE", ft_strlen(s))
		|| !ft_strncmp(s, "EA", ft_strlen(s))
		|| !ft_strncmp(s, "F", ft_strlen(s))
		|| !ft_strncmp(s, "C", ft_strlen(s)))
	{
		return (1);
	}
	return (0);
}

int	comp_attr(char *s)
{
	if (!ft_strncmp(s, "NO", ft_strlen(s))
		|| !ft_strncmp(s, "SO", ft_strlen(s))
		|| !ft_strncmp(s, "WE", ft_strlen(s))
		|| !ft_strncmp(s, "EA", ft_strlen(s)))
	{
		return (1);
	}
	return (0);
}

int	is_attr(t_game *game, char *s, int i)
{
	if (!s || !s[0])
		return (1);
	if (check_attr(game))
	{
		if (game->map_start == 0)
			game->map_start = i;
		return (1);
	}
	if (!((comp_attr_clrs(s)) && !check_attr(game)))
		return (0);
	return (1);
}

void	send_attr_err(t_game *game)
{
	if (!game->walls.ea_path)
		attr_error(game, 4, "EA");
	else if (!game->walls.no_path)
		attr_error(game, 4, "NO");
	else if (!game->walls.we_path)
		attr_error(game, 4, "WE");
	else if (!game->walls.so_path)
		attr_error(game, 4, "SO");
	else if (game->ceiling == -1)
		attr_error(game, 4, "C");
	else if (game->floor == -1)
		attr_error(game, 4, "F");
	else
		attr_error(game, 4, "");
}
