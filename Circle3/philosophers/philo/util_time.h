/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:55:40 by sangkkim          #+#    #+#             */
/*   Updated: 2022/12/21 15:33:33 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_TIME_H
# define UTIL_TIME_H

# include <sys/time.h>
# include <stddef.h>

long long	get_ms_from(struct timeval from);
void		wait_until_timeval(struct timeval until);
void		wait_until_ms(size_t until);

#endif//UTIL_TIME_H
