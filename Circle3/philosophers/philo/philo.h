/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:12:33 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 19:35:35 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stddef.h>

# include "condition.h"
# include "fork.h"

typedef enum e_simulation_type		t_simulation_type;
typedef enum e_simulation_status	t_simulation_status;
typedef struct s_simulation			t_simulation;

typedef enum e_philo_hand_status	t_philo_hand_status;
typedef struct s_philo_hand			t_philo_hand;
typedef struct s_philo				t_philo;

enum e_philo_hand_status
{
	hand_empty = 0,
	hand_holding,
};

struct s_philo_hand
{
	t_fork					*fork;
	t_philo_hand_status		status;
};

struct s_philo
{
	long long				id;
	long long				eat_cnt;
	struct timeval			last_eat_time;
	struct timeval			*sim_start_time;
	pthread_mutex_t			*mutex_philo_time;
	t_philo_hand			right_hand;
	t_philo_hand			left_hand;
	t_condition				*condition;
	t_simulation_status		*sim_status;
	pthread_mutex_t			*mutex_sim_status;
	long long				*sim_full_philo;
	pthread_mutex_t			*mutex_sim_full_philo;
};

#endif//PHILO_H
