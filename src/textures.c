/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:56:59 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:57:01 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static t_image	*new_texture_image(t_window *win, char *filename);

// initializes the walls textures
void	init_walls(t_game *game, t_window *win)
{
	game->walls.no_textu = new_texture_image(win, game->walls.no_path);
	game->walls.so_textu = new_texture_image(win, game->walls.so_path);
	game->walls.ea_textu = new_texture_image(win, game->walls.ea_path);
	game->walls.we_textu = new_texture_image(win, game->walls.we_path);
}

// initializes the game window
static t_image	*new_texture_image(t_window *win, char *filename)
{
	t_image	*data;

	data = (t_image *)malloc(sizeof(t_image));
	if (!data)
		return (NULL);
	data->win = win;
	data->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, filename,
			&(data->w), &(data->h));
	if (!data->img_ptr)
	{
		ft_putendl_fd("Error: Could not load image from xpm file", 2);
		exit (1);
	}
	data->addr = mlx_get_data_addr(data->img_ptr, &(data->bpp),
			&(data->line_len), &(data->endian));
	return (data);
}

// gets the color of a pixel in a texture
unsigned int	get_texture_color(t_image *texture, int pixel_x, int pixel_y)
{
	if (pixel_x < 0 || pixel_y < 0
		|| pixel_x >= texture->w || pixel_y >= texture->h)
		return (0);
	else
		return (*(unsigned int *)((texture->addr
				+ (pixel_y * texture->line_len)
				+ (pixel_x * texture->bpp / 8))));
}

// gets the color of a pixel in a texture
unsigned int	texture_pixel_color(t_game *game, t_point p, t_ray ray,
		t_image *texture)
{
	double	pixel_x;
	double	pixel_y;
	int		top;

	top = (game->player->center) - (ray.height / 2);
	pixel_x = p.x / TILE_SIZE * texture->w;
	pixel_y = (p.y - top) / ray.height;
	pixel_y = pixel_y * texture->h;
	return (get_texture_color(texture, pixel_x, pixel_y));
}

//	destroy walls images
void	destroy_walls(t_window *win, t_walls walls)
{
	if (walls.no_textu->img_ptr)
		mlx_destroy_image(win->mlx_ptr, walls.no_textu->img_ptr);
	if (walls.so_textu->img_ptr)
		mlx_destroy_image(win->mlx_ptr, walls.so_textu->img_ptr);
	if (walls.ea_textu->img_ptr)
		mlx_destroy_image(win->mlx_ptr, walls.ea_textu->img_ptr);
	if (walls.we_textu->img_ptr)
		mlx_destroy_image(win->mlx_ptr, walls.we_textu->img_ptr);
}
