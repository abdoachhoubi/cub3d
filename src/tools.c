/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:57:08 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:57:09 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// free array
void	ft_arrfree(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

// duplicate a string until a certain length
char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < n)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

// counts the length of an array
int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

// repeat a char in a string
int	ft_strreps(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == c)
			count++;
	return (count);
}

// print game info
void	print_game(t_game *game)
{
	int	i;

	i = 0;
	printf("Floor Color [%d] - (%d, %d, %d)\n", game->floor,
		get_r(game->floor), get_g(game->floor), get_b(game->floor));
	printf("Ceiling Color [%d] - (%d, %d, %d)\n", game->ceiling,
		get_r(game->ceiling), get_g(game->ceiling), get_b(game->ceiling));
	printf("NO [%s]\n", game->walls.no_path);
	printf("SU [%s]\n", game->walls.so_path);
	printf("WE [%s]\n", game->walls.we_path);
	printf("EA [%s]\n", game->walls.ea_path);
	printf("MAP:\n");
	if (game->map)
	{
		while (game->map[i])
			printf("%s\n", game->map[i++]);
	}
	printf("Map Dimension: [%d x %d]\n", game->player->width,
		game->player->height);
	printf("Player Position(%f, %f) %dº\n", game->player->point.x,
		game->player->point.y, game->player->angle);
	printf("Distance of the Player to the planeº : %d\n", game->player->dtp);
}
