/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:36:50 by sangkkim          #+#    #+#             */
/*   Updated: 2022/08/18 16:39:40 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <sys/time.h>
# include <stddef.h>

// utils1_bonus.c
size_t	get_ms_from(struct timeval from);
void	ft_putstr_fd(char *str, int fd);
void	ft_putunbr_fd(size_t n, int fd);
int		parse_uint(unsigned int *ptr, char *str);

#endif