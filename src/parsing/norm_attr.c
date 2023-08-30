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
