/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:57:36 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:57:36 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// update keys
static void	keys_update(int key_code, void *params, int up_down)
{
	t_game	*game;

	game = params;
	if (key_code == KEY_ESC)
		exit(0);
	if ((key_code == KEY_W || key_code == KEY_UP)
		&& game->player->n_down != up_down)
		game->player->n_down = up_down;
	if ((key_code == KEY_S || key_code == KEY_DOWN)
		&& game->player->s_down != up_down)
		game->player->s_down = up_down;
	if ((key_code == KEY_RIGHT) && game->player->e_down != up_down)
		game->player->e_down = up_down;
	if ((key_code == KEY_LEFT) && game->player->w_down != up_down)
		game->player->w_down = up_down;
	if ((key_code == KEY_D) && game->player->d_down != up_down)
		game->player->d_down = up_down;
	if ((key_code == KEY_A) && game->player->a_down != up_down)
		game->player->a_down = up_down;
}

// key up callback
int	handle_key_up(int key_code, void *params)
{
	keys_update(key_code, params, 0);
	return (0);
}

// key down callback
int	handle_key_down(int key_code, void *params)
{
	keys_update(key_code, params, 1);
	return (0);
}
