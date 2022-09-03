/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:49:42 by sangkkim          #+#    #+#             */
/*   Updated: 2022/09/03 13:42:28 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "philo.h"

// philo_main.c
void	philo_echo(size_t time, size_t id, char *status);

// monitoe_main.c [here]
int		check_philos(t_sim *sim, t_philo *philos, size_t time);
void	terminate_philos(t_philo *philos, size_t philo_num);

void	monitor_main(t_sim *sim, t_philo *philos)
{
	static size_t	last_time;
	size_t			time;

	while (1)
	{
		pthread_mutex_lock(&sim->mutex);
		time = get_ms_from(sim->start_time);
		if (last_time != time)
		{
			if (!sim->progress)
				break ;
			else if (check_philos(sim, philos, time) < 0)
				break ;
		}
		pthread_mutex_unlock(&sim->mutex);
		last_time = time;
		usleep(500);
	}
	pthread_mutex_unlock(&sim->mutex);
	terminate_philos(sim);
}

int	check_philos(t_sim *sim, t_philos *philos, size_t time)
{
	size_t	i;

	i = 0;
	while (id < sim->philo_num)
	{
		if (time >= philos[i].deadline)
		{
			philo_echo(time, i + 1, " died\n");
			sim->progress = 0;
			return (-1);
		}
		i++;
	}
	return (0);
}

void	terminate_philos(t_philo *philos, size_t philo_num)
{
	size_t	i;

	if (philo_num == 1)
		pthread_detach(philos[0].tid);
	else
	{
		i = 0;
		while (i < philo_num)
		{
			pthread_join(philos[i].tid, NULL);
			i++;
		}
	}
}
