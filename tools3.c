/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 04:20:05 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 19:50:12 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_iterator	ft_stack_begin(t_stack *stack)
{
	t_stack_iterator	tmp;

	tmp.head = stack->lst.head;
	tmp.node = stack->lst.head;
	return (tmp);
}

t_stack_iterator	ft_stack_end(t_stack *stack)
{
	t_stack_iterator	tmp;

	tmp.head = stack->lst.head;
	tmp.node = 0;
	return (tmp);
}

void	ft_init_stack(t_stack *stack, char name)
{
	ft_init_list(&stack->lst);
	stack->type = name;
}

void	ft_push_stack(t_stack *stack, int num)
{
	ft_push_front_list(&stack->lst, num);
}

void	ft_pop_stack(t_stack *stack)
{
	if (stack->lst.head)
		ft_pop_front_list(&stack->lst);
}
