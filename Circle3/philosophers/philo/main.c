/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:32:43 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 22:02:31 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "condition.h"
#include "fork.h"
#include "philo.h"
#include "simulation.h"
#include "error_code.h"

void	*philo_main(void *arg);

int		get_condition(t_condition *condition, int argc, char *argv[]);
int		init_simulation(t_simulation *sim);
int		run_simulation(t_simulation *sim);
int		monitor_main(t_simulation *sim);
int		terminate_simulation(t_simulation *sim);

#include <unistd.h>
int	main(int argc, char *argv[])
{
	int				err;
	t_simulation	sim;

	memset(&sim, 0, sizeof(t_simulation));
	err = get_condition(&(sim.condition), argc, argv);
	if (err == SUCCESS)
		init_simulation(&sim);
	if (err == SUCCESS)
		err = run_simulation(&sim);
	if (err == SUCCESS)
		err = monitor_main(&sim);
	if (err == SUCCESS)
		err = terminate_simulation(&sim);
	return (err);
}

int	run_simulation(t_simulation *sim)
{
	long long	i;
	int			err;

	gettimeofday(&(sim->start_time), NULL);
write(1, "! ", 2);
	sim->status = sim_running;
	sim->start_time.tv_usec += 100000;
	if (sim->start_time.tv_usec >= 1000000)
	{
		sim->start_time.tv_sec += 1;
		sim->start_time.tv_usec -= 1000000;
	}
	i = 0;
	err = 0;
write(1, "! ", 2);
	while (err == 0 && i < sim->condition.philo_num)
	{
write(1, "! ", 2);
		sim->philos[i].last_eat_time = sim->start_time;
write(1, "? ", 2);
		err = pthread_create(&(sim->threads[i]), NULL, \
			philo_main, &(sim->philos[i]));
		i++;
	}
write(1, "! ", 2);
	return (err);
}

int	terminate_simulation(t_simulation *sim)
{
	long long	i;
	int			err;

	i = 0;
	err = 0;
	while (err == 0 && i < sim->condition.philo_num)
	{
		err = pthread_detach(sim->threads[i]);
		i++;
	}
	return (err);
}
