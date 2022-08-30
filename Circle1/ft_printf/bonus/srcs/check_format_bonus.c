/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:34:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/10 23:41:37 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "format_bonus.h"

int	check_format(t_format format)
{
	if (!ft_strchr("cspdiuxX%", format.specifier))
		return (-1);
	//	TODO: undefined specifier;
	if (format.width > 2147483645 || format.precision > 2147483645)
		return (-1);
	//	TODO: wodth or precision is too big
	// if (format.f_zero && format.f_minus)
	// 	format.f_zero = 0;
	// if (format.f_zero && format.f_precision && ft_strchr("duixX", format.specifier))
	// 	format.f_zero = 0;
	// if (format.f_hash && ft_strchr("cdipsu", format.specifier))
	// 	format.f_hash = 0;
	return (0);
}