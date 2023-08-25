/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:28:51 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/25 16:30:54 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_isin(int a, char const *b)
{
	int	i;

	i = 0;
	while (b[i])
	{
		if (a == b[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_toklen(const char *s, const char *set)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (ft_isin(*s, set) == 0)
		{
			s++;
			len++;
		}
		else
			break ;
	}
	return (len);
}

int	ft_duplen(const char *s, const char *set)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (ft_isin(*s, set))
		{
			s++;
			len++;
		}
		else
			break ;
	}
	return (len);
}
