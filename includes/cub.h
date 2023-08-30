/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:10:13 by aanouari          #+#    #+#             */
/*   Updated: 2023/08/26 18:10:15 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define COLOR_RED "\033[0;31m"
# define COLOR_RESET "\033[0m"
# define MAP_MAX 100000000
# define ARG_ERROR "\033[1;31mError: invalid args!\n\033[0m\tUsage:\
\033[1;32m./cub3d <path_to_scene (.cub file)>\033[0m"
# define FILE_ERROR "\033[1;31mError: couldn't open file: \033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# include "cub3d.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

#endif