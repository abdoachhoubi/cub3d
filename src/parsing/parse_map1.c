/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:17:19 by aanouari          #+#    #+#             */
/*   Updated: 2023/08/30 14:17:21 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	parse_maps(t_game *game)
{
	char	*map;

	map = get_map(game);
	map_list(game, map);
	check_valid_map(game);
	is_surrounded_by_walls(game);
	if (game->player_count < 1)
		exit (ft_puts(RED"Error\nNo player found"RESET, 2));
	if (game->player_count > 1)
		exit (ft_puts(RED"Error\nMultiple players found"RESET, 2));
	game->map = game->maps->map;
	free(map);
	return (0);
}

void	check_valid_map(t_game *game)
{
	t_map	*tmp;
	int		i;
	int		j;

	tmp = game->maps;
	while (tmp)
	{
		i = 0;
		while (tmp->map[i])
		{
			j = 0;
			while (tmp->map[i][j])
			{
				if (!ft_strchr("01NSEW ", tmp->map[i][j]))
					exit (ft_puts(RED"Error\nInvalid character"RESET, 2));
				j++;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	longest_line(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		if ((int)ft_strlen(arr[i]) > j)
			j = ft_strlen(arr[i]);
		i++;
	}
	return (j);
}

char	*ft_repeat(int count, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), count + 1);
	while (i < count)
		str[i++] = c;
	return (str);
}

// fill_line_with_spaces at the end of the line
char	*fill_line_with_spaces(char *line, int len)
{
	int		i;
	int		len_line;
	char	*tmp;
	char	*tmp2;
	char	*res;

	len_line = ft_strlen(line);
	if (len_line >= len)
		return (ft_strdup(line));
	i = 0;
	res = ft_calloc(sizeof(char), len + 1);
	while (i < len_line)
	{
		res[i] = line[i];
		i++;
	}
	tmp = ft_repeat(len - len_line, ' ');
	tmp2 = ft_strjoin(res, tmp);
	free(res);
	res = ft_strdup(tmp2);
	free(tmp2);
	free(tmp);
	return (res);
}
