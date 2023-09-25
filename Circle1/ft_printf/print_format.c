/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:24:30 by sangkkim          #+#    #+#             */
/*   Updated: 2022/02/04 16:26:31 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(const char *s);
char	*ft_bzero(void *s, size_t size);
void	make_decimal(char *buffer, long value);
void	make_lowerhex(char *buffer, unsigned long value);
void	make_upperhex(char *buffer, unsigned long value);

int	put_character(char c)
{
	return (write(1, &c, 1));
}

int	put_string(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
}

int	put_pointer(void *ptr)
{
	char	buffer[30];

	ft_bzero(buffer, 30);
	buffer[0] = '0';
	buffer[1] = 'x';
	make_lowerhex(buffer + 2, (unsigned long)ptr);
	return (write(1, buffer, ft_strlen(buffer)));
}

int	put_decimal(long value)
{
	char	buffer[30];

	ft_bzero(buffer, 30);
	make_decimal(buffer, value);
	return (write(1, buffer, ft_strlen(buffer)));
}

int	put_hex(unsigned int value, char hex_case)
{
	char	buffer[30];

	ft_bzero(buffer, 30);
	if (hex_case == 'x')
		make_lowerhex(buffer, value);
	else
		make_upperhex(buffer, value);
	return (write(1, buffer, ft_strlen(buffer)));
}
