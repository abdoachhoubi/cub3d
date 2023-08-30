/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:57:23 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:57:24 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// move player right
void	move_right(t_game *game)
{
	t_point	p;

	p.x = game->player->point.x;
	p.y = game->player->point.y;
	p = add_vec(p, vec(game->player->angle - r_angle(90), game->player->mag));
	if (game->map[(int)((p.y + 10) / TILE_SIZE)]
		[(int)((p.x + 10) / TILE_SIZE)] == '1')
		return ;
	if (game->map[(int)((game->player->point.y) / TILE_SIZE)]
		[(int)((p.x) / TILE_SIZE)] == '1')
		return ;
	if (game->map[(int)((p.y) / TILE_SIZE)]
		[(int)((game->player->point.x) / TILE_SIZE)] == '1')
		return ;
	if (p.x > game->player->width || p.x < 0
		|| p.y > game->player->height || p.y < 0)
		return ;
	if (game->map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)] != '1')
	{
		game->player->point.y = round(p.y);
		game->player->point.x = round(p.x);
	}
}

// move player left
void	move_left(t_game *game)
{
	t_point	p;

	p.x = game->player->point.x;
	p.y = game->player->point.y;
	p = add_vec(p, vec(game->player->angle + r_angle(90), game->player->mag));
	if (game->map[(int)((p.y + 10) / TILE_SIZE)]
		[(int)((p.x + 10) / TILE_SIZE)] == '1')
		return ;
	if (game->map[(int)((game->player->point.y) / TILE_SIZE)]
		[(int)((p.x) / TILE_SIZE)] == '1')
		return ;
	if (game->map[(int)((p.y) / TILE_SIZE)]
		[(int)((game->player->point.x) / TILE_SIZE)] == '1')
		return ;
	if (p.x > game->player->width || p.x < 0
		|| p.y > game->player->height || p.y < 0)
		return ;
	if (game->map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)] != '1')
	{
		game->player->point.y = round(p.y);
		game->player->point.x = round(p.x);
	}
}

// move player up
void	move_up(t_game *game)
{
	t_point	p;

	p.x = game->player->point.x;
	p.y = game->player->point.y;
	p = add_vec(p, vec(game->player->angle, game->player->mag));
	if (game->map[(int)((p.y + 10) / TILE_SIZE)]
		[(int)((p.x + 10) / TILE_SIZE)] == '1')
		return ;
	if (game->map[(int)((p.y) / TILE_SIZE)]
		[(int)((game->player->point.x) / TILE_SIZE)] == '1')
		return ;
	if (game->map[(int)((game->player->point.y) / TILE_SIZE)]
		[(int)((p.x) / TILE_SIZE)] == '1')
		return ;
	if (p.x > game->player->width || p.x < 0
		|| p.y > game->player->height || p.y < 0)
		return ;
	if (game->map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)] != '1')
	{
		game->player->point.y = round(p.y);
		game->player->point.x = round(p.x);
	}
}

// move player down
void	move_down(t_game *game)
{
	t_point	p;

	p.x = game->player->point.x;
	p.y = game->player->point.y;
	p = add_vec(p, vec(game->player->angle, game->player->mag * -1));
	if (game->map[(int)((p.y + 10) / TILE_SIZE)]
		[(int)((p.x + 10) / TILE_SIZE)] == '1')
		return ;
	if (game->map[(int)((p.y) / TILE_SIZE)]
		[(int)((game->player->point.x) / TILE_SIZE)] == '1')
		return ;
	if (game->map[(int)((game->player->point.y)
			/ TILE_SIZE)][(int)((p.x) / TILE_SIZE)] == '1')
		return ;
	if (p.x > game->player->width || p.x < 0
		|| p.y > game->player->height || p.y < 0)
		return ;
	if (game->map[(int)(p.y / TILE_SIZE)][(int)(p.x / TILE_SIZE)] != '1')
	{
		game->player->point.y = round(p.y);
		game->player->point.x = round(p.x);
	}
}

// move player
void	move(int key_code, t_game *game)
{
	if (key_code == KEY_W)
	{
		move_up(game);
		game->player->n_down = 1;
	}
	else if (key_code == KEY_S)
	{
		move_down(game);
		game->player->s_down = 1;
	}
	else if (key_code == KEY_D)
	{
		move_right(game);
		game->player->d_down = 1;
	}
	else if (key_code == KEY_A)
	{
		move_left(game);
		game->player->a_down = 1;
	}
}
