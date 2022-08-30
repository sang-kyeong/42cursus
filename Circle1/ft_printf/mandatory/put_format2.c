/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:17:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 23:33:21 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unstd.h>
#include "libft.h"

void	build_deci(char *buffer, size_t value);
void	build_hex(char *buffer, size_t value);
void	build_lhex(char *buffer, size_t value);

int	put_p(void *p)
{
	size_t	len;
	char	buffer[19];

	ft_bzero(buffer, 19);
	ft_strncpy(buffer, "0x", 3);
	build_hex(buffer, (size_t)p, 19);
	len = ft_strlen(buffer);
	return (write(STDOUT_FILENO, buffer, len));
}

int	put_d(int d)
{
	size_t	len;
	char	buffer[12];

	ft_bzero(buffer, 12);
	build_deci(buffer, (ssize_t)d, 12);
	len = ft_strlen(buffer);
	return (write(STDOUT_FILENO, buffer, len));
}

int	put_u(unsigned int u)
{
	size_t	len;
	char	buffer[11];

	ft_bzero(buffer, 11);
	build_deci(buffer, (ssize_t)u, 11);
	len = ft_strlen(buffer);
	return (write(STDOUT_FILENO, buffer, len));
}

int	put_x(unsigned int x)
{
	size_t	len;
	char	buffer[9];

	ft_bzero(buffer, 9);
	build_hex(buffer, (size_t)p, 9);
	len = ft_strlen(buffer);
	return (write(STDOUT_FILENO, buffer, len));
}

int	put_lx(unsigned int x)
{
	size_t	len;
	char	buffer[9];

	ft_bzero(buffer, 9);
	build_lhex(buffer, (size_t)p, 9);
	len = ft_strlen(buffer);
	return (write(STDOUT_FILENO, buffer, len));
}
