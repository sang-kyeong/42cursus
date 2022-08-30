/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:38:57 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 22:10:34 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_BONUS_H
# define FORMAT_BONUS_H

typedef struct s_format
{
	union{
		unsigned char	flags;
		struct
		{
			unsigned char	f_minus		: 1;
			unsigned char	f_zero		: 1;
			unsigned char	f_precision	: 1;
			unsigned char	f_width		: 1;
			unsigned char	f_hash		: 1;
			unsigned char	f_space		: 1;
			unsigned char	f_plus		: 1;
		};
	};
	size_t	precision;
	size_t	width;
	char	specifier;
}	t_format;

typedef struct s_padding
{
	int		minus;
	char	c;
	int		len;
}	t_padding;

#endif