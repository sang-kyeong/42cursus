/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:23:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 19:38:32 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "condition.h"
#include "fork.h"
#include "philo.h"
#include "simulation.h"
#include "error_code.h"

static int	allocate_memory(t_simulation *sim, long long philo_num);
static int	init_mutexes(t_simulation *sim, t_fork *forks, t_philo *philos);
static int	init_forks_and_philos(t_simulation *sim, \
	t_fork *forks, t_philo *philos);

int	init_simulation(t_simulation *sim)
{
	int	err;

	if (sim->condition.must_eat == 0)
		sim->type = sim_until_done;
	err = allocate_memory(sim, sim->condition.philo_num);
	if (err == 0)
		err = init_mutexes(sim, sim->forks, sim->philos);
	if (err == 0)
		err = init_forks_and_philos(sim, sim->forks, sim->philos);
	return (0);
}

static int	allocate_memory(t_simulation *sim, long long philo_num)
{
	sim->mutexes = malloc(((2 * philo_num) + 2) * sizeof(pthread_mutex_t));
	if (sim->threads == NULL)
		return (MALLOC_FAIL);
	memset(sim->mutexes, 0, ((2 * philo_num) + 2) * sizeof(pthread_mutex_t));
	sim->threads = malloc(philo_num * sizeof(pthread_t));
	if (sim->threads == NULL)
		return (MALLOC_FAIL);
	memset(sim->threads, 0, philo_num * sizeof(pthread_t));
	sim->forks = malloc(philo_num * sizeof(t_fork));
	if (sim->forks == NULL)
		return (MALLOC_FAIL);
	memset(sim->forks, 0, philo_num * sizeof(t_fork));
	sim->philos = malloc(philo_num * sizeof(t_philo));
	if (sim->philos == NULL)
		return (MALLOC_FAIL);
	memset(sim->philos, 0, philo_num * sizeof(t_philo));
	return (SUCCESS);
}

static int	init_mutexes(t_simulation *sim, t_fork *forks, t_philo *philos)
{
	long long	i;
	int			err;

	err = pthread_mutex_init(&(sim->mutexes[0]), NULL);
	if (err != 0)
		return (err);
	err = pthread_mutex_init(&(sim->mutexes[1]), NULL);
	if (err != 0)
		return (err);
	i = 0;
	while (i < sim->condition.philo_num)
	{
		err = pthread_mutex_init(&(sim->mutexes[i + 2]), NULL);
		if (err != 0)
			return (err);
		err = pthread_mutex_init(\
			&(sim->mutexes[i + 2 + sim->condition.philo_num]), NULL);
		if (err != 0)
			return (err);
	}
	sim->mutex_sim_status = &(sim->mutexes[0]);
	sim->mutex_sim_full_philo = &(sim->mutexes[1]);
	return (0);
}

static int	init_forks_and_philos(t_simulation *sim, \
	t_fork *forks, t_philo *philos)
{
	long long	i;

	i = 0;
	while (i < sim->condition.philo_num)
	{
		forks[i].mutex_fork = &(sim->mutexes[i + 2]);
		philos[i].id = i + 1;
		philos[i].sim_start_time = &(sim->start_time);
		philos[i].right_hand.fork = &(sim->forks[i]);
		philos[i].left_hand.fork = \
			&(sim->forks[(i + 1) % sim->condition.philo_num]);
		philos[i].condition = &(sim->condition);
		philos[i].sim_status = &(sim->status);
		philos[i].mutex_sim_status = &(sim->mutex_sim_status);
		philos[i].sim_full_philo = &(sim->full_philo);
		philos[i].mutex_sim_full_philo = &(sim->mutex_sim_full_philo);
		philos[i].mutex_philo_time = \
			&(sim->mutexes[i + 2 + sim->condition.philo_num]);
		i++;
	}
	return (0);
}
