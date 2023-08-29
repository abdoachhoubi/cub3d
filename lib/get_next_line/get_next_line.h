/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:21:55 by aachhoub          #+#    #+#             */
/*   Updated: 2022/10/24 15:56:33 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_current_line(char **tmp, int nl);
char	*get_next_line(int fd);
int		check_newline(char *buff);
char	*get_rest(char **str, int nl);
char	*ft_substr_x(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_x(char const *s1, char const *s2);

#endif
