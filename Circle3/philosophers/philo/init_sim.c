/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:34:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/10/11 16:36:21 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "philo.h"

// philo_main.c
void	*philo_main(void *arg);

// init_sim.c [here]
static int	alloc_memory(t_sim *sim, t_philo **philos_ptr, t_fork **forks_ptr);
static int	init_mutex(t_sim *sim, t_philo *philos, t_fork *forks);
static void	init_data(t_sim *sim, t_philo *philos, t_fork *forks);
static int	create_thread(t_sim *sim, t_philo *philos, t_fork *forks);

int	init_sim(t_sim *sim, t_philo **philos_ptr, t_fork **forks_ptr)
{
	int		err;

	err = alloc_memory(sim, philos_ptr, forks_ptr);
	if (err == 0)
		err = init_mutex(sim, *philos_ptr, *forks_ptr);
	if (err == 0)
		init_data(sim, *philos_ptr, *forks_ptr);
	if (err == 0)
		err = create_thread(sim, *philos_ptr, *forks_ptr);
	return (err);
}

static int	alloc_memory(t_sim *sim, t_philo **philos_ptr, t_fork **forks_ptr)
{
	int		err;

	err = 0;
	sim->tids = malloc(sim->info.philo_num * sizeof(pthread_t));
	*philos_ptr = malloc(sim->info.philo_num * sizeof(t_philo));
	*forks_ptr = malloc(sim->info.philo_num * sizeof(t_fork));
	if (sim->tids == NULL || *philos_ptr == NULL || *forks_ptr == NULL)
		err = ERR_MALLOC;
	if (err == 0)
	{
		memset(sim->tids, 0, sim->info.philo_num * sizeof(pthread_t));
		memset(*philos_ptr, 0, sim->info.philo_num * sizeof(t_philo));
		memset(*forks_ptr, 0, sim->info.philo_num * sizeof(t_fork));
	}
	else
	{
		free(sim->tids);
		free(*philos_ptr);
		free(*forks_ptr);
	}
	return (err);
}

static int	init_mutex(t_sim *sim, t_philo *philos, t_fork *forks)
{
	int		err;
	size_t	i;

	i = 0;
	err = pthread_mutex_init(&(sim->mutex), NULL);
	while (err == 0 && i < sim->info.philo_num)
	{
		err = pthread_mutex_init(&(forks[i].mutex), NULL);
		i++;
	}
	if (err != 0)
	{
		if (i > 0)
			pthread_mutex_destroy(&(sim->mutex));
		i--;
		while (i--)
			pthread_mutex_destroy(&(forks[i].mutex));
		free(sim->tids);
		free(philos);
		free(forks);
		return (ERR_PTHREAD_MUTEX);
	}
	pthread_mutex_lock(&(sim->mutex));
	return (0);
}

static void	init_data(t_sim *sim, t_philo *philos, t_fork *forks)
{
	size_t	i;

	calc_input(sim);
	sim->progress = sim->info.philo_num;
	i = 0;
	while (i < sim->info.philo_num)
	{
		forks[i].status = available;
		philos[i].id = i + 1;
		philos[i].deadline = sim->info.time_to_die;
		philos[i].eat_cnt = 0;
		philos[i].info = sim->info;
		philos[i].wait_time = (sim->info.time_to_eat * i) % sim->period;
		philos[i].left_hand = 0;
		philos[i].right_hand = 0;
		philos[i].left_fork = &(forks[i]);
		philos[i].right_fork = &(forks[(i + 1) % sim->info.philo_num]);
		philos[i].sim = sim;
		i++;
	}
}

static int	create_thread(t_sim *sim, t_philo *philos, t_fork *forks)
{
	int		err;
	size_t	i;

	err = 0;
	i = 0;
	while (err == 0 && i < sim->info.philo_num)
	{
		err = pthread_create(sim->tids + i, NULL, philo_main, philos + i);
		i++;
	}
	if (err != 0)
	{
		i--;
		while (i--)
			pthread_detach(sim->tids[i]);
		pthread_mutex_destroy(&(sim->mutex));
		i = 0;
		while (i < sim->info.philo_num)
			pthread_mutex_destroy(&(forks[i].mutex));
		free(sim->tids);
		free(philos);
		free(forks);
		return (ERR_PTHREAD);
	}
	return (0);
}
