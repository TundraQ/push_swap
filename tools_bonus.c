/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:22:54 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 19:33:34 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

void	ft_rotate_up_stack_bonus(t_stack *stack)
{
	if (stack->lst.head)
		ft_rotate_up_list(&stack->lst);
}

void	ft_rotate_down_stack_bonus(t_stack *stack)
{
	if (stack->lst.head)
		ft_rotate_down_list(&stack->lst);
}

void	ft_swap_stack_bonus(t_stack *stack)
{
	if (stack->lst.size > 1)
		ft_swap_list(&stack->lst);
}

void	ft_rotate_stacks_bonus(t_stack *a, t_stack *b, char side)
{
	if (side == 'u')
	{
		if (a->lst.head)
			ft_rotate_up_list(&a->lst);
		if (b->lst.head)
			ft_rotate_up_list(&b->lst);
	}
	else
	{
		if (a->lst.head)
			ft_rotate_down_list(&a->lst);
		if (b->lst.head)
			ft_rotate_down_list(&b->lst);
	}
}

void	ft_push_from_to_bonus(t_stack *from, t_stack *to)
{
	int	tmp;

	tmp = ft_stack_top(from);
	ft_push_stack(to, tmp);
	ft_pop_stack(from);
}
