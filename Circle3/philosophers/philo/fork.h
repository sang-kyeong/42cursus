/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:15:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/09/02 22:17:57 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FROK_H

# include <pthread.h>

typedef struct s_fork		t_fork;
typedef enum e_fork_status	t_fork_status;

struct s_fork
{
	pthread_mutex_t	mutex;
	t_fork_status	status;
};

enum e_fork_status
{
	available = 0,
	taken,
};

#endif
