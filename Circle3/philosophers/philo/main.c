/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:38:03 by sangkkim          #+#    #+#             */
/*   Updated: 2022/08/27 16:07:12 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

int		init_sim(t_sim *sim, int argc, char **argv);
void	run_sim(t_sim *sim);
void	end_sim(t_sim *sim);

void	observer_main(t_sim *sim);

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (init_sim(&sim, argc, argv) < 0)
		return (-1);
	run_sim(&sim);
	observer_main(&sim);
	end_sim(&sim);
	return (0);
}

void	print_arg(t_sim *sim)
{
	char	buffer[25];

	print("philosophers  : ");
	buffer[0] = '\0';
	print(ft_numcat(buffer, sim->arg.philo_num));
	print("\ntime to die   : ");
	buffer[0] = '\0';
	print(ft_numcat(buffer, sim->arg.time_to_die));
	print("\ntime to eat   : ");
	buffer[0] = '\0';
	print(ft_numcat(buffer, sim->arg.time_to_eat));
	print("\ntime to sleep : ");
	buffer[0] = '\0';
	print(ft_numcat(buffer, sim->arg.time_to_sleep));
	print("\nmust eat      : ");
	if (sim->arg.option)
	{
		buffer[0] = '\0';
		print(ft_numcat(buffer, sim->arg.must_eat));
	}
	else
		print("no");
	print("\n");
}

void	run_sim(t_sim *sim)
{
	print("\033[30;1m");
	print("Simulation is ready\n");
	print_arg(sim);
	print("\033[0;32m3");
	usleep(1000000);
	print("\b2");
	usleep(1000000);
	print("\b1");
	usleep(1000000);
	sim->progress = sim->arg.philo_num;
	gettimeofday(&sim->start_time, NULL);
	print("\nStart!\n");
	print("\033[0;0m");
	pthread_mutex_unlock(&sim->mutex);
}

void	end_sim(t_sim *sim)
{
	size_t	i;

	i = 0;
	while (i < sim->arg.philo_num)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->mutex);
	free(sim->forks);
	free(sim->philos);
	print("\033[30;1msimulation end!\n\033[0;0m");
}
