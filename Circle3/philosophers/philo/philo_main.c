/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:16:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/10/11 13:25:54 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "philo.h"

// philo_main.c [here]
static int	philo_init(t_philo *philo);
static void	philo_clean(t_philo *philo);
int			philo_wait(t_philo *philo);

// philo_action.c
int			philo_take_fork(t_philo *philo);
int			philo_eat(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);

void	*philo_main(void *arg)
{
	int			err;
	t_philo		*philo;

	philo = (t_philo *)arg;
	err = philo_init(philo);
	while (err == 0)
	{
		err = philo_take_fork(philo);
		if (err == 0)
			err = philo_eat(philo);
		if (err == 0)
			err = philo_sleep(philo);
		if (err == 0)
			err = philo_think(philo);
	}
	philo_clean(philo);
	return (0);
}

static int	philo_init(t_philo *philo)
{
	int		err;

	pthread_mutex_lock(&(philo->sim->mutex));
	pthread_mutex_unlock(&(philo->sim->mutex));
	err = philo_wait(philo);
	return (err);
}

static void	philo_clean(t_philo *philo)
{
	if (philo->right_hand)
		pthread_mutex_unlock(&(philo->right_fork->mutex));
	if (philo->left_hand)
		pthread_mutex_unlock(&(philo->left_fork->mutex));
}

int	philo_wait(t_philo *philo)
{
	size_t	until;
	int		err;

	err = 0;
	if (philo->wait_time <= 0)
		return (err);
	until = get_ms_from(philo->sim->start_time) + philo->wait_time;
	while (err == 0)
	{
		usleep(500);
		pthread_mutex_lock(&(philo->sim->mutex));
		err = (philo->sim->progress <= 0);
		pthread_mutex_unlock(&(philo->sim->mutex));
		if (get_ms_from(philo->sim->start_time) >= until)
			break ;
	}
	return (err);
}

int	philo_echo(t_philo *philo, char *status)
{
	int		err;

	pthread_mutex_lock(&(philo->sim->mutex));
	err = (philo->sim->progress <= 0);
	if (err == 0)
		printf("%zu %zu %s\n", get_ms_from(philo->sim->start_time), \
			philo->id, status);
	pthread_mutex_unlock(&(philo->sim->mutex));
	return (err);
}