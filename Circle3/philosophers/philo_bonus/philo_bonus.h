/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:30:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/08/27 18:07:34 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>

# define FT_SEM_FORK		"ft_semaphore_fork"
# define FT_SEM_MUTEX		"ft_semaphore_mutex"
# define FT_SEM_WAITING		"ft_semaphore_waiting"

typedef struct s_sim
{
	size_t		philo_num;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			option;
	size_t		must_eat;
	sem_t		*forks;
	sem_t		*mutex;
	sem_t		*waiting;
	pid_t		*pids;
}	t_sim;

enum e_type
{
	observer = 0,
	philosopher,
};

typedef struct s_philo
{
	size_t			id;
	size_t			dead_line;
	size_t			eat_cnt;
	enum e_type		type;
}	t_philo;

// utils_bonus.c
size_t	get_ms_from(struct timeval from);
int		parse_uint(unsigned int *uint, char *s);
char	*ft_strcat(char *dst, char *src);
char	*ft_numcat(char *dst, size_t n);
void	print(char *str);

#endif
