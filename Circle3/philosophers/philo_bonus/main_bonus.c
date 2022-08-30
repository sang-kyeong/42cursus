/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:29:03 by sangkkim          #+#    #+#             */
/*   Updated: 2022/08/27 18:07:54 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include "philo_bonus.h"

int		init_simulation(t_sim *sim, t_philo *philo, int argc, char **argv);

void	observer_main(t_sim *sim);
void	philo_main(t_sim *sim, t_philo *philo);

int	main(int argc, char **argv)
{
	t_sim	sim;
	t_philo	philo;

	if (init_simulation(&sim, &philo, argc, argv) < 0)
		return (-1);
	if (philo.type == philosopher)
		philo_main(&sim, &philo);
	else
		observer_main(&sim);
	return (0);
}

void	observer_main(t_sim *sim)
{
	printf("I am observer\nrun simulation\n");
	sem_post(sim->mutex);
}

void	philo_main(t_sim *sim, t_philo *philo)
{
	sem_wait(sim->mutex);
	printf("hello I am philo %zu\n", philo->id);
	sem_post(sim->mutex);
}
