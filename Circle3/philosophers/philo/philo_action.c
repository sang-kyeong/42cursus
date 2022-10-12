/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:38:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/10/11 16:28:25 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "philo.h"

// philo_main.c
int			philo_wait(t_philo *philo);
int			philo_echo(t_philo *philo, char *status);

// philo_action.c [here]
static int	philo_echo_eat(t_philo *philo);

int	philo_take_fork(t_philo *philo)
{
	int		err;

	pthread_mutex_lock(&(philo->left_fork->mutex));
	philo->left_fork->status = taken;
	philo->left_hand = 1;
	err = philo_echo(philo, "has taken a fork");
	if (err != 0)
		return (err);
	pthread_mutex_lock(&(philo->right_fork->mutex));
	philo->right_fork->status = taken;
	philo->right_hand = 1;
	err = philo_echo(philo, "has taken a fork");
	return (err);
}

int	philo_eat(t_philo *philo)
{
	int		err;

	err = philo_echo_eat(philo);
	philo->wait_time = philo->info.time_to_eat;
	if (err == 0)
		err = philo_wait(philo);
	return (err);
}

int	philo_sleep(t_philo *philo)
{
	int		err;

	pthread_mutex_lock(&(philo->sim->mutex));
	err = (philo->sim->progress <= 0);
	if (err == 0)
	{
		printf("%zu %zu is sleeping\n", \
			get_ms_from(philo->sim->start_time), philo->id);
		if (philo->info.type == until_done)
		{
			if (++philo->eat_cnt == philo->info.must_eat)
				philo->sim->progress--;
		}
	}
	pthread_mutex_unlock(&(philo->sim->mutex));
	philo->right_hand = 0;
	philo->right_fork->status = available;
	pthread_mutex_unlock(&(philo->right_fork->mutex));
	philo->left_hand = 0;
	philo->left_fork->status = available;
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	philo->wait_time = philo->info.time_to_sleep;
	if (err == 0)
		err = philo_wait(philo);
	return (err);
}

int	philo_think(t_philo *philo)
{
	int		err;

	err = philo_echo(philo, "is thinking");
	philo->wait_time = philo->info.time_to_think;
	if (err == 0)
		err = philo_wait(philo);
	return (err);
}

static int	philo_echo_eat(t_philo *philo)
{
	int		err;
	size_t	time;

	pthread_mutex_lock(&(philo->sim->mutex));
	err = (philo->sim->progress <= 0);
	time = get_ms_from(philo->sim->start_time);
	if (err == 0 && time >= philo->deadline)
		printf("%zu %zu died\n", time, philo->id);
	if (err == 0)
	{
		printf("%zu %zu is eating\n", time, philo->id);
		philo->deadline = time + philo->info.time_to_die;
	}
	pthread_mutex_unlock(&(philo->sim->mutex));
	return (err);
}