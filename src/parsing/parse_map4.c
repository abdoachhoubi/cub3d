/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:17:26 by aanouari          #+#    #+#             */
/*   Updated: 2023/08/30 14:17:28 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	choose_angle(t_game *game, char c)
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
void	set_player_values(t_game *game)
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
