/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:57:49 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 16:37:43 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *a, t_stack *b, int print)
{
	(void)b;
	if (swap(a))
	{
		if (print)
			ft_putstr_fd("sa\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	sb(t_stack *a, t_stack *b, int print)
{
	(void)a;
	if (swap(b))
	{
		if (print)
			ft_putstr_fd("sb\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	ss(t_stack *a, t_stack *b, int print)
{
	if (swap(a) + swap(b))
	{
		if (print)
			ft_putstr_fd("ss\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	pa(t_stack *a, t_stack *b, int print)
{
	t_node	*node;

	if (pop_node(b, &node) && push_node(a, node))
	{
		if (print)
			ft_putstr_fd("pa\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	pb(t_stack *a, t_stack *b, int print)
{
	t_node	*node;

	if (pop_node(a, &node) && push_node(b, node))
	{
		if (print)
			ft_putstr_fd("pb\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}
