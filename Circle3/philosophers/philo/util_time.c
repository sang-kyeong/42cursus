/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:01:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 16:01:41 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include <stddef.h>

long long	get_ms_from(struct timeval from)
{
	struct timeval	now;
	long long		time;

	gettimeofday(&now, NULL);
	time = ((now.tv_sec - from.tv_sec) % 1000000) * 1000;
	time += (now.tv_usec - from.tv_usec) / 1000;
	return (time);
}

void	wait_until_timeval(struct timeval until)
{
	while (get_ms_from(until) < 0)
		usleep(500);
}

void	wait_until_ms(long long until)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (get_ms_from(start) < until)
		usleep(500);
}
