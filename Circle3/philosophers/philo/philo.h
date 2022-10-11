/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:05:53 by sangkkim          #+#    #+#             */
/*   Updated: 2022/10/11 13:25:10 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR_INVALID_INPUT		1
# define ERR_MALLOC				2
# define ERR_PTHREAD_MUTEX		3
# define ERR_PTHREAD			4

typedef struct s_fork			t_fork;
typedef enum e_fork_status		t_fork_status;
typedef struct s_time_info		t_time_info;
typedef struct s_sim			t_sim;
typedef enum e_sim_type			t_sim_type;
typedef struct s_philo			t_philo;

enum e_fork_status
{
	available = 0,
	taken,
};

struct s_fork
{
	pthread_mutex_t	mutex;
	t_fork_status	status;
};

enum e_sim_type
{
	until_die = 0,
	until_done,
};

struct s_time_info
{
	size_t				philo_num;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				time_to_think;
	t_sim_type			type;
	size_t				must_eat;
};

struct s_sim
{
	t_time_info			info;
	size_t				period;
	pthread_mutex_t		mutex;
	struct timeval		start_time;
	size_t				progress;
	pthread_t			*tids;
};

struct s_philo
{
	size_t				id;
	size_t				deadline;
	size_t				eat_cnt;
	t_time_info			info;
	size_t				wait_time;
	int					left_hand;
	int					right_hand;
	t_fork				*left_fork;
	t_fork				*right_fork;
	t_sim				*sim;
};

// utils.c
size_t	get_ms_from(struct timeval from);

#endif
