/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:57:30 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:57:31 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// rotate player right
void	rotate_right(t_game *game)
{
	game->player->angle = (game->player->angle - r_angle(MAGNITUDE_ANGLE));
	if (game->player->angle < 0)
		game->player->angle = r_angle(360) + r_angle(360);
	if (game->player->angle > r_angle(360))
		game->player->angle = game->player->angle - r_angle(360);
}

// rotate player left
void	rotate_left(t_game *game)
{
	game->player->angle = (game->player->angle + r_angle(MAGNITUDE_ANGLE));
	if (game->player->angle > r_angle(360))
		game->player->angle = game->player->angle - r_angle(360);
	if (game->player->angle < 0)
		game->player->angle = r_angle(360) + r_angle(360);
}

// rotate player
void	rotate(int key_code, t_game *game)
{
	if (key_code == KEY_LEFT || key_code == KEY_Q)
		rotate_left(game);
	else if (key_code == KEY_RIGHT || key_code == KEY_E)
		rotate_right(game);
}

// update the window
void	paint_window(t_game *game)
{
	t_image		*img_map;
	t_image		*img_game;

	img_game = new_image(game->img_game->win, game->img_game->h,
			game->img_game->w);
	mlx_destroy_image(game->img_game->win->mlx_ptr, game->img_game->img_ptr);
	free(game->img_game);
	game->img_game = img_game;
	raycasting3d(game);
	mlx_put_image_to_window(game->img_game->win->mlx_ptr,
		game->img_game->win->win_ptr, img_game->img_ptr, 0, 0);
	img_map = new_image(game->img_map->win, game->img_map->h, game->img_map->w);
	mlx_destroy_image(game->img_map->win->mlx_ptr, game->img_map->img_ptr);
	free(game->img_map);
	game->img_map = img_map;
	paint_map(game);
	mlx_put_image_to_window(game->img_map->win->mlx_ptr,
		game->img_map->win->win_ptr, img_map->img_ptr, 0, 0);
}

// update the game
int	update(t_game *game)
{
	static int	fps = 0;

	if (fps++ == 5)
	{
		if (game->player->n_down)
			move(KEY_W, game);
		if (game->player->s_down)
			move(KEY_S, game);
		if (game->player->d_down)
			move(KEY_D, game);
		if (game->player->a_down)
			move(KEY_A, game);
		if (game->player->w_down)
			rotate(KEY_LEFT, game);
		if (game->player->e_down)
			rotate(KEY_RIGHT, game);
		if (game->player->n_down || game->player->s_down || game->player->e_down
			|| game->player->w_down || game->player->a_down
			|| game->player->d_down)
			paint_window(game);
		fps = 0;
	}
	return (0);
}
