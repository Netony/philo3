/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:31:23 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 16:31:47 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isin(int a, char const *b);
int		ft_toklen(const char *s, const char *set);
int		ft_duplen(const char *s, const char *set);
ssize_t	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_isspace(int c);
int		ft_atoi(const char *nptr);

#endif
