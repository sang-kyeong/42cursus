/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:56:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/22 15:40:10 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <stddef.h>
# include <sys/time.h>
# include <pthread.h>

# include "fork.h"
# include "philo.h"

typedef enum e_simulation_type		t_simulation_type;
typedef enum e_simulation_status	t_simulation_status;
typedef struct s_condition			t_condition;
typedef struct s_simulation			t_simulation;

enum e_simulation_type
{
	sim_until_died = 0,
	sim_until_done,
};

enum e_simulation_status
{
	sim_initializing = 0,
	sim_running,
	sim_closing_died,
	sim_closing_done,
};

struct s_condition
{
	long long				philo_num;
	long long				time_to_die;
	long long				time_to_eat;
	long long				time_to_sleep;
	long long				must_eat;
};

struct s_simulation
{
	t_condition				condition;
	t_simulation_type		type;
	t_simulation_status		status;
	pthread_mutex_t			*mutex_sim_status;
	struct timeval			start_time;
	long long				full_philo;
	pthread_mutex_t			*mutex_sim_full_philo;

	t_fork					*forks;
	t_philo					*philos;

	pthread_t				*threads;
	pthread_mutex_t			*mutexes;
};

#endif//SIMULATION_H
