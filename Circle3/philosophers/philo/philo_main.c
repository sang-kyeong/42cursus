/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:16:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/09/02 23:03:52 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "philo.h"

// philo_action.c
void	philo_take_fork(t_philo *philo, pthread_mutex_t *fork);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

// philo_main.c [here]
void	philo_wait(t_philo *philo);

void	*philo_main(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->sim->mutex);
	pthread_mutex_unlock(&philo->sim->mutex);
	philo_wait(philo);
	while (philo->alive)
	{
		philo_take_fork(philo, philo->right_fork);
		philo_take_fork(philo, philo->left_fork);
		philo_eat(philo);
		philo_wait(philo);
		philo_sleep(philo);
		philo_wait(philo);
		philo_think(philo);
		philo_wait(philo->sim->time_to_think);
	}
	return (0);
}

void	philo_wait(t_philo *philo)
{
	while (philo->alive && get_time(philo->sim->start_time) < philo->until)
	{
		usleep(300);
		pthread_mutex_lock(&philo->sim->mutex);
		philo->alive = philo->sim->progress > 0;
		pthread_mutex_unlock(&philo->sim->mutex);
	}
}

void	philo_echo(size_t time, size_t id, char *status)
{
	put_unbr(time);
	put_str(" ");
	put_unbr(id);
	put_str(status);
}
