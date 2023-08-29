/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:57:46 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 18:43:54 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// free game
void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->walls.no_path)
		free(game->walls.no_path);
	if (game->walls.so_path)
		free(game->walls.so_path);
	if (game->walls.ea_path)
		free(game->walls.ea_path);
	if (game->walls.we_path)
		free(game->walls.we_path);
	if (game->map)
		ft_arrfree(game->map);
	free(game);
}

// free game and exit
int	exit_game(t_game *game)
{
	if (game)
		free_game(game);
	exit(EXIT_SUCCESS);
}

// initializes the game window
static void	init_game_window(t_game *game, t_window *win)
{
	int			map_w;
	int			map_h;

	if (game->width * game->map_tile_size < MINIMAP_W)
		map_w = game->width * game->map_tile_size;
	else
		map_w = MINIMAP_W;
	if (game->height * game->map_tile_size < MINIMAP_H)
		map_h = game->height * game->map_tile_size;
	else
		map_h = MINIMAP_H;
	game->img_map = new_image(win, map_h, map_w);
	game->img_game = new_image(win, WIN_H, WIN_W);
	paint_map(game);
	init_walls(game, win);
	raycasting3d(game);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		game->img_game->img_ptr, 0, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		game->img_map->img_ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_window	*win;
	t_game		*game;

	if (ac != 2)
		return (print_error(ARG_ERROR, NULL));
	if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4))
		return (print_error(ARG_ERROR, NULL));
	game = (t_game *)malloc(sizeof(t_game));
	game->scene_fd = open(av[1], O_RDONLY);
	if (game->scene_fd < 3)
		return (print_error(FILE_ERROR, av[1]));
	parse_scene(game);
	if (!game)
		return (-1);
	win = new_window(WIN_H, WIN_W, "cub3D");
	mlx_hook(win->win_ptr, 3, 1L << 1, handle_key_up, game);
	mlx_hook(win->win_ptr, 2, 1L << 0, handle_key_down, game);
	mlx_hook(win->win_ptr, 17, 0, exit_game, NULL);
	mlx_loop_hook(win->mlx_ptr, update, game);
	init_game_window(game, win);
	mlx_loop(win->mlx_ptr);
	destroy_walls(win, game->walls);
	free_game(game);
	return (0);
}
