#include "../../includes/cub.h"

int	get_scene(t_game *game)
{
	game->scene = ft_calloc(MAP_MAX + 1, sizeof(char));
	if (read(game->scene_fd, game->scene, MAP_MAX) < 0)
	{
		free(game->scene);
		perror("Error");
		return (0);
	}
	return (1);
}

void	init_attributes(t_game *game)
{
	game->walls.no_path = NULL;
	game->walls.so_path = NULL;
	game->walls.we_path = NULL;
	game->walls.ea_path = NULL;
	game->floor = -1;
	game->ceiling = -1;
	game->map_start = 0;
	game->maps = new_map(NULL);
	game->map = NULL;
	game->player = NULL;
	game->width = 0;
	game->height = 0;
	game->player_count = 0;
	game->map_tile_size = (int)round((double)TILE_SIZE / (double)MAP_SCALE);
}

// choose player starting angle
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
int	player_init(t_game *game)
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
