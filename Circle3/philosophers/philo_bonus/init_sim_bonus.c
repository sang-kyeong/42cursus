/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:57:22 by sangkkim          #+#    #+#             */
/*   Updated: 2022/08/27 20:00:35 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo_bonus.h"

int		parse_arguments(t_sim *sim, int argc, char **argv);
int		init_values(t_sim *sim, t_philo *philo);
int		fork_philosophers(t_sim *sim, t_philo *philo);

int	init_simulation(t_sim *sim, t_philo *philo, int argc, char **argv)
{
	memset(sim, 0, sizeof(t_sim));
	memset(philo, 0, sizeof(t_philo));
	if (parse_arguments(sim, argc, argv) < 0)
	{
		print("\033[0;33mInvalid arguments\n\033[0;0m");
		return (-1);
	}
	if (init_values(sim, philo) < 0)
		return (-1);
	if (fork_philosophers(sim, philo) < 0)
		return (-1);
	return (0);
}

int	parse_arguments(t_sim *sim, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	if (parse_uint((unsigned int *)&sim->philo_num, argv[1]) < 0 \
		|| sim->philo_num == 0)
		return (-1);
	if (parse_uint((unsigned int *)&sim->time_to_die, argv[2]) < 0)
		return (-1);
	if (parse_uint((unsigned int *)&sim->time_to_eat, argv[3]) < 0)
		return (-1);
	if (parse_uint((unsigned int *)&sim->time_to_sleep, argv[4]) < 0)
		return (-1);
	if (argc == 5)
	{
		sim->option = 0;
		sim->must_eat = 0;
	}
	else
	{
		sim->option = 0;
		if (parse_uint((unsigned int *)&sim->must_eat, argv[5]) < 0)
			return (-1);
	}
	return (0);
}

int	init_values(t_sim *sim, t_philo *philo)
{
	sem_unlink(FT_SEM_MUTEX);
	sem_unlink(FT_SEM_FORK);
	sem_unlink(FT_SEM_WAITING);
	sim->mutex = sem_open(FT_SEM_MUTEX, O_CREAT | O_EXCL, 0700, 1);
	sim->forks = sem_open(FT_SEM_FORK, O_CREAT | O_EXCL, 0700, sim->philo_num);
	sim->waiting = sem_open(FT_SEM_WAITING, O_CREAT | O_EXCL, 0700, \
		sim->philo_num - 2);
	sim->pids = malloc(sim->philo_num * sizeof(pthread_mutex_t));
	if (sim->pids == NULL)
		return (-1);
	sim->waiting = sem_open(FT_SEM_WAITING, O_CREAT | O_EXCL, 0700, sim->philo_num - 2);
	philo->dead_line = sim->time_to_die;
	philo->eat_cnt = 0;
	return (0);
}

int	fork_philosophers(t_sim *sim, t_philo *philo)
{
	size_t	i;

	i = 0;
	sem_wait(sim->mutex);
	while (i < sim->philo_num)
	{
		sim->pids[i] = fork();
		if (sim->pids[i] == -1)
		{
			while (i--)
				kill(pids[i]. SIGKILL);
			return (-1);
		}
		else if (sim->pids[i] == 0) // child
		{
			philo->type = philosopher;
			philo->id = i + 1;
			return ((int)philo->id);
		}
		i++;
	}
	return (0);
}
