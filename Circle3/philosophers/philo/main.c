/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:38:03 by sangkkim          #+#    #+#             */
/*   Updated: 2022/10/11 16:38:46 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

int			get_input(int argc, char *argv[], t_sim *sim);
int			init_sim(t_sim *sim, t_philo **philos_ptr, t_fork **forks_ptr);

void		run_sim(t_sim *sim);
void		monitor_philos(t_sim *sim, t_philo *philos);
void		end_sim(t_sim *sim, t_philo *philos, t_fork *forks);

int	main(int argc, char **argv)
{
	int			err;
	t_sim		sim;
	t_philo		*philos;
	t_fork		*forks;

	philos = NULL;
	forks = NULL;
	err = get_input(argc, argv, &sim);
	if (err == 0)
		err = init_sim(&sim, &philos, &forks);
	if (err == 0)
	{
		run_sim(&sim);
		monitor_philos(&sim, philos);
		end_sim(&sim, philos, forks);
	}
	return (err);
}

void	run_sim(t_sim *sim)
{
	gettimeofday(&sim->start_time, NULL);
	pthread_mutex_unlock(&sim->mutex);
}

void	monitor_philos(t_sim *sim, t_philo *philos)
{
	int		err;
	size_t	id;
	size_t	time;

	err = 0;
	id = 0;
	while (err == 0)
	{
		pthread_mutex_lock(&(sim->mutex));
		err = (sim->progress <= 0);
		time = get_ms_from(sim->start_time);
		if (err == 0 && time >= philos[id].deadline)
		{
			sim->progress = 0;
			err = 1;
			printf("%zu %zu died\n", time, id + 1);
		}
		pthread_mutex_unlock(&(sim->mutex));
		if (err == 0)
			id = (id + 1) % sim->info.philo_num;
		usleep(20);
	}
}

void	end_sim(t_sim *sim, t_philo *philos, t_fork *forks)
{
	size_t	i;

	if (sim->info.philo_num == 1)
		pthread_detach(sim->tids[0]);
	else
	{
		i = 0;
		while (i < sim->info.philo_num && sim->tids[i] != 0)
			pthread_join(sim->tids[i++], NULL);
	}
	pthread_mutex_destroy(&(sim->mutex));
	i = 0;
	while (i < sim->info.philo_num)
		pthread_mutex_destroy(&(forks[i++].mutex));
	free(sim->tids);
	free(philos);
	free(forks);
}
