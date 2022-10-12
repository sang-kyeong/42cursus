/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:44:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/10/11 16:52:07 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo.h"

void	calc_input(t_sim *sim)
{
	size_t	n;

	n = sim->info.philo_num / 2;
	sim->period = (sim->info.time_to_eat * sim->info.philo_num) / n;
	sim->period += ((sim->info.time_to_eat * sim->info.philo_num) % n) > 0;
	sim->info.time_to_think = \
		sim->period - (2 * sim->info.time_to_eat) - sim->info.time_to_sleep + 1;
}

size_t	get_ms_from(struct timeval from)
{
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec - from.tv_sec) % 1000000 * 1000;
	time += (tv.tv_usec - from.tv_usec) % 1000000 / 1000;
	return (time);
}

int	parse_uint(unsigned int *uint, char *s)
{
	size_t	val;

	if (*s < '0' || '9' < *s)
		return (-1);
	val = 0;
	while ('0' <= *s && *s <= '9')
	{
		val = val * 10 + (*s - '0');
		if (val > UINT_MAX)
			return (ERR_INVALID_INPUT);
		s++;
	}
	if (*s)
		return (ERR_INVALID_INPUT);
	*uint = val;
	return (0);
}
