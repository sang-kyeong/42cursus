/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:38:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 16:10:30 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

char	*parse_int(int *value, char *str);
int		parse_string(t_stack *stack, char *input);
int		check_duplicate(t_stack *stack);

static void	to_space(unsigned int i, char *s)
{
	(void)i;
	if (*s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r')
		*s = ' ';
}

int	parse_input(t_stack *stack, int argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		ft_striteri(argv[i], &to_space);
		if (parse_string(stack, argv[i++]) <= 0)
			return (-1);
	}
	if (check_duplicate(stack) < 0)
		return (-1);
	return (0);
}

int	parse_string(t_stack *stack, char *input)
{
	int	cnt;
	int	value;

	cnt = 0;
	while (*input)
	{
		if (*input == ' ')
			input++;
		else if (('0' <= *input && *input <= '9')
			|| *input == '+' || *input == '-')
		{
			cnt++;
			input = parse_int(&value, input);
			if (input == NULL)
				return (-1);
			if (push_value(stack, value) == 0)
				return (-1);
			stack->top = stack->top->next;
		}
		else
			return (-1);
	}
	return (cnt);
}

int	check_duplicate(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		*array;

	if (to_array(stack, &array) == 0)
		return (-1);
	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (array[i] == array[j])
			{
				free(array);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free(array);
	return (0);
}
