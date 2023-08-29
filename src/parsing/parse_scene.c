#include "../../includes/cub.h"

int	parse_scene(t_game *game)
{
	int	list_size;

	if (!get_scene(game))
		return (0);
	if (!get_attributes(game))
		return (0);
	if (!check_attributes(game))
		return (0);
	parse_maps(game);
	list_size = map_size(game->maps);
	if (list_size != 1)
		exit(write(1, "Error\nFound consecutive newlines \
		'\\n' in the middle of the map\n", 63));
	game->width = longest_line(game->map);
	game->height = ft_arrlen(game->map);
	player_init(game);
	return (1);
}

int	print_error(char *s, char *arg)
{
	if (s)
		ft_putstr_fd(s, 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

void	reset_tools(t_game *game)
{
	close(game->scene_fd);
	free(game->scene);
	free(game->walls.no_path);
	free(game->walls.so_path);
	free(game->walls.we_path);
	free(game->walls.ea_path);
	delete_list(&game->maps);
}
