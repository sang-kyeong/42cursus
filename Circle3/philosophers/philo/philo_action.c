/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:38:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/09/02 23:03:36 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// philo_main.c
void	philo_echo(size_t time, size_t id, char *status);

void	philo_take_fork(t_philo *philo, t_fork *fork)
{
	size_t	time;

	if (philo->alive == 0)
		return ;
	pthread_mutex_lock(&fork->mutex);
	fork->status = taken;
	pthread_mutex_lock(&philo->sim->mutex);
	time = get_time(philo->sim->start_time);
	if (philo->sim->progress == 0)
		philo->alive = 0;
	else
		philo_echo(time, philo->id, " has taken a fork\n");
	pthread_mutex_unlock(&philo->sim->mutex);
}

void	philo_eat(t_philo *philo)
{
	size_t		time;

	if (philo->alive == 0)
		return ;
	pthread_mutex_lock(&philo->sim->mutex);
	time = get_time(philo->sim->stari_time);
	if (philo->sim->progress == 0)
		philo->alive = 0;
	else if (time >= philo->dead_line)
	{
		philo->sim->progress = 0;
		philo->alive = 0;
		philo_echo(time, philo->id, " died\n");
	}
	else
	{
		philo_echo(time, philo->id, " is eating\n");
		philo->deadline += time;
		if (philo->sim->type == until_done \
			&& ++philo->eat_cnt == philo->sim->must_eat)
			philo->sim->progress--;
	}
	pthread_mutex_unlock(&philo->sim->mutex);
	philo->until = time + philo->sim->time_to_eat;
}

void	philo_sleep(t_philo *philo)
{
	size_t		time;

	if (philo->alive == 0)
		return ;
	pthread_mutex_lock(&philo->sim->mutex);
	time = get_time(philo->sim->stari_time);
	if (philo->sim->progress == 0)
		philo->alive = 0;
	else
		philo_echo(time, philo->id, " is sleeping\n");
	pthread_mutex_unlock(&philo->sim->mutex);
	philo->right_fork->status = available;
	philo->left_fork->status = available;
	pthread_mutex_unlock(&philo->roght_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->until = time + philo->sim->time_to_sleep;
}

void	philo_think(t_philo *philo)
{
	if (philo->alive == 0)
		return ;
	pthread_mutex_lock(&philo->sim->mutex);
	time = get_time(philo->sim->stari_time);
	if (philo->sim->progress == 0)
		philo->alive = 0;
	else
		philo_echo(time, philo->id, " is thinking\n");
	pthread_mutex_unlock(&philo->sim->mutex);
	philo->until = time + philo->sim->time_to_think;
}
