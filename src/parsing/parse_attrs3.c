#include "../../includes/cub.h"

int	check_files(t_game *game)
{
	int	fd[4];

	fd[0] = open(game->walls.no_path, O_RDONLY);
	fd[1] = open(game->walls.so_path, O_RDONLY);
	fd[2] = open(game->walls.we_path, O_RDONLY);
	fd[3] = open(game->walls.ea_path, O_RDONLY);
	if (fd[0] < 3 || fd[1] < 3 || fd[2] < 3 || fd[3] < 3)
	{
		close_array(fd, 4);
		attr_error(game, 3, NULL);
		return (0);
	}
	return (1);
}

int	check_attributes(t_game *game)
{
	if (!game->walls.no_path)
		attr_error(game, 4, "NO");
	if (!game->walls.so_path)
		attr_error(game, 4, "SO");
	if (!game->walls.we_path)
		attr_error(game, 4, "WE");
	if (!game->walls.ea_path)
		attr_error(game, 4, "EA");
	if (game->floor == -1)
		attr_error(game, 4, "F");
	if (game->ceiling == -1)
		attr_error(game, 4, "C");
	if (!check_files(game))
		return (0);
	return (1);
}

int	check_attributes_i(t_game *game)
{
	if (!game->walls.no_path || !game->walls.so_path
		|| !game->walls.we_path || !game->walls.ea_path
		|| game->floor == -1
		|| game->ceiling == -1)
		return (1);
	return (0);
}
