/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:23:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/18 22:48:42 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "simulation.h"
#include "error_code.h"

void		*philo_main(void *arg);

static int	allocate_memory(t_simulation *simulation, size_t size);
static int	init_shared_variables(t_simulation *simulation);
static int	init_forks(t_fork *forks, size_t size);
static int	init_philo_infos(t_philo_info *infos, t_simulation *simulation);

int	init_simulation(t_simulation *simulation)
{
	int	err;

	err = allocate_memory(\
		simulation, simulation->condition.number_of_philosophers);
	if (err == SUCCESS)
		err = init_shared_variables(simulation);
	if (err == SUCCESS)
		err = init_forks(\
			simulation->forks, simulation->condition.number_of_philosophers);
	if (err == SUCCESS)
		err = init_philo_infos(simulation->philo_infos, simulation);
	return (SUCCESS);
}

static int	allocate_memory(t_simulation *simulation, size_t size)
{
	simulation->thread_ids = malloc(size * sizeof(pthread_t));
	if (simulation->thread_ids == NULL)
		return (MALLOC_FAIL);
	memset(simulation->thread_ids, 0, size * sizeof(pthread_t));
	simulation->forks = malloc(size * sizeof(pthread_t));
	if (simulation->forks == NULL)
		return (MALLOC_FAIL);
	memset(simulation->forks, 0, size * sizeof(t_fork));
	simulation->philo_infos = malloc(size * sizeof(pthread_t));
	if (simulation->philo_infos == NULL)
		return (MALLOC_FAIL);
	memset(simulation->philo_infos, 0, size * sizeof(t_philo_info));
	return (SUCCESS);
}

static int	init_shared_variables(t_simulation *simulation)
{
	int	err;

	err = pthread_mutex_init(&(simulation->mutex_simulation), 0);
	if (err == SUCCESS)
		err = pthread_mutex_init(&(simulation->mutex_print), 0);
	if (err == SUCCESS)
	{
		simulation->progress = simulation->condition.number_of_philosophers;
		pthread_mutex_lock(&simulation->mutex_simulation);
	}
	return (err);
}

static int	init_forks(t_fork *forks, size_t size)
{
	size_t	i;
	int		err;

	err = SUCCESS;
	i = 0;
	while (i < size)
	{
		err = pthread_mutex_init(forks[i].mutex_fork, 0);
		if (err != 0)
			break ;
		forks[i].status = available;
		i++;
	}
	return (err);
}

static int	init_philo_infos(t_philo_info *infos, t_simulation *simulation)
{
	size_t	i;
	int		err;

	i = 0;
	while (i < simulation->condition.number_of_philosophers)
	{
		infos[i].id = i + 1;
		infos[i].deadline = simulation->condition.time_to_die;
		infos[i].eat_cnt = 0;
		infos[i].right_fork = &(simulation->forks[i]);
		infos[i].right_hand = empty;
		infos[i].left_fork = &(simulation->forks[(i + 1) % \
			simulation->condition.number_of_philosophers]);
		infos[i].left_hand = empty;
		infos[i].mutex_simulation = &(simulation->mutex_simulation);
		infos[i].mutex_print = &(simulation->mutex_print);
		infos[i].simulation_progress = &(simulation->progress);
		infos[i].simulation_condition = &(simulation->condition);
		err = pthread_create(&(simulation->thread_ids[i]), \
			NULL, philo_main, NULL);
		if (err != 0)
			return (err);
		i++;
	}
	return (SUCCESS);
}
