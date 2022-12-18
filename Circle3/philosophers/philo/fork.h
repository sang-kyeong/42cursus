/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:40:37 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/18 17:47:02 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>

typedef enum e_status_fork		t_status_fork;
typedef struct s_fork			t_fork;

enum e_status_fork
{
	available = 0,
	unavailable,
};

struct s_fork
{
	t_status_fork		status;
	pthread_mutex_t		*mutex_fork;
};

#endif//FORK_H