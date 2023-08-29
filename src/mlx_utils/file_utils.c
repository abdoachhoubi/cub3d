/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:55:57 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:55:58 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// checks if file exists
int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf(COLOR_RED"Error\nCannot open file \'%s\'\n"COLOR_RESET, filename);
		return (-1);
	}
	close(fd);
	return (1);
}

// gets a line from a file withouth the newline
char	*get_next_line_no_nl(char *line)
{
	char	*tmp;

	tmp = line;
	line = ft_strndup(tmp, ft_strlen(tmp) - 1);
	free(tmp);
	return (line);
}
