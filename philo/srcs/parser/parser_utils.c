/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:28:56 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 16:30:49 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	put;

	put = write(fd, s, ft_strlen(s));
	if (put >= 0)
		put += write(fd, "\n", 1);
	return (put);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_isspace(int c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (c);
	else
		return (0);
}
