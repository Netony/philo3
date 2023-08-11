/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:09:58 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/11 13:18:06 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../libft/incs/libft.h"

int		ft_toklen(const char *s, const char *set);
int		ft_duplen(const char *s, const char *set);
void	ft_free(void *ptr);

#endif
