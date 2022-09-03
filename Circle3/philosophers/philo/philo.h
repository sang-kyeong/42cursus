/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:05:53 by sangkkim          #+#    #+#             */
/*   Updated: 2022/09/03 13:41:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>

# include "fork.h"
# include "sim.h"

typedef struct s_philo		t_philo;

struct s_philo
{
	size_t				id;
	size_t				deadline;
	size_t				eat_cnt;
	int					alive;
	size_t				until;
	t_fork				*right_fork;
	t_fork				*left_fork;
	t_sim				*sim;
};

// utils.c
size_t	get_ms_from(struct timeval from);
int		parse_uint(unsigned int *uint, char *s);
char	*ft_strcat(char *dst, char *src);
char	*ft_numcat(char *dst, size_t n);
void	print(char *str);

#endif
