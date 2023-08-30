/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attrs1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:17:03 by aanouari          #+#    #+#             */
/*   Updated: 2023/08/30 14:51:31 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	attr_error(t_game *game, int code, char *attr)
{
	ft_putstr_fd(RED"Error:\n", 2);
	if (code == 0)
		ft_putstr_fd("Duplicate attribute!\n"RESET, 2);
	else if (code == 1)
		ft_putstr_fd("Invalid attribute!\n"RESET, 2);
	else if (code == 2)
		ft_putstr_fd("Invalid color!\n"RESET, 2);
	else if (code == 3)
		ft_putstr_fd("Invalid texture path!\n"RESET, 2);
	else if (code == 4)
	{
		ft_putstr_fd("Missing: ", 2);
		ft_putstr_fd(attr, 2);
		ft_putendl_fd(" attribute!"RESET, 2);
	}
	if (game)
		reset_tools(game);
	exit(0);
}

int	set_attr(t_game *game, char *attr, char *value)
{
	if (!check_attributes_i(game))
		return (1);
	if (!ft_strncmp(attr, "NO", 2) && !game->walls.no_path)
		game->walls.no_path = ft_strdup(value);
	else if (!ft_strncmp(attr, "SO", 2) && !game->walls.so_path)
		game->walls.so_path = ft_strdup(value);
	else if (!ft_strncmp(attr, "WE", 2) && !game->walls.we_path)
		game->walls.we_path = ft_strdup(value);
	else if (!ft_strncmp(attr, "EA", 2) && !game->walls.ea_path)
		game->walls.ea_path = ft_strdup(value);
	else
		return (0);
	return (1);
}

int	check_color(char *color)
{
	int		i;
	int		ret;
	char	*trimed_color;

	i = 0;
	ret = 1;
	trimed_color = ft_strtrim(color, " \t");
	if (ft_strlen(trimed_color) > 3 || ft_strlen(trimed_color) < 1)
		ret = 0;
	while (trimed_color[i])
	{
		if (ft_iswhitespace(trimed_color[i]))
			attr_error(NULL, 2, NULL);
		if (ft_isdigit(trimed_color[i]))
			i++;
		else
		{
			ret = 0;
			break ;
		}
	}
	if (ft_atoi(trimed_color) > 255 || ft_atoi(trimed_color) < 0)
		ret = 0;
	free(trimed_color);
	return (ret);
}

char	**split_attribute(char *attr)
{
	char	*trimed_attr;
	int		i;
	char	**split_attr;

	split_attr = ft_calloc(3, sizeof(char *));
	trimed_attr = ft_strtrim(attr, " ");
	i = 0;
	while (trimed_attr[i] && !ft_iswhitespace(trimed_attr[i]))
		i++;
	split_attr[0] = ft_substr(trimed_attr, 0, i);
	while (trimed_attr[i] && ft_iswhitespace(trimed_attr[i]))
		i++;
	split_attr[1] = ft_substr(trimed_attr, i, ft_strlen(trimed_attr));
	split_attr[2] = NULL;
	free(trimed_attr);
	return (split_attr);
}

int	comma_count(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == ',')
			j++;
		i++;
	}
	return (j);
}
