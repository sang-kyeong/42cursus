/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:44:37 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/18 22:49:06 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stddef.h>
#include "simulation.h"

int	monitor_main(t_simulation *simulation)
{
	size_t	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&(simulation->mutex_simulation));
		if (simulation->progress == -1 || simulation->progress == \
			simulation->condition.number_of_philosophers)
		{
			pthread_mutex_unlock(&(simulation->mutex_simulation));
			break ;
		}
		if ((simulation->condition.time_to_die * 1000) < \
			get_us_from(simulation->philo_infos[i].last_eat))
		{
			philo_echo();
			simulation->progress = -1;
			pthread_mutex_unlock(&(simulation->mutex_simulation));
			break ;
		}
		pthread_mutex_unlock(&(simulation->mutex_simulation));
		i = (i + 1) % (simulation->condition.number_of_philosophers);
	}
	return (SUCCESS);
}
