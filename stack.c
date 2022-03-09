/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:37:52 by azane             #+#    #+#             */
/*   Updated: 2022/03/09 00:08:23 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *stack)
{
	ft_init_list(&stack->lst);
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

void	ft_rotate_up_stack(t_stack *stack)
{
	if (stack->lst.head)
		ft_rotate_up_list(&stack->lst);
	if (stack->type == 'a')
		ft_printf("ra\n");
	if (stack->type == 'b')
		ft_printf("rb\n");
}

void	ft_rotate_down_stack(t_stack *stack)
{
	if (stack->lst.head)	
		ft_rotate_down_list(&stack->lst);
	if (stack->type == 'a')
		ft_printf("rra\n");
	if (stack->type == 'b')
		ft_printf("rrb\n");
}

void	ft_swap_stack(t_stack *stack)
{
	if (stack->lst.size > 1)
		ft_swap_list(&stack->lst);
	if (stack->type == 'a')
		ft_printf("sa\n");
	if (stack->type == 'b')
		ft_printf("sb\n");
}

void	ft_clear_stack(t_stack *stack)
{
	ft_clear_list(&stack->lst);
}

int		ft_stack_top(t_stack *stack)
{
	return (stack->lst.head->data);
}

int		ft_stack_size(t_stack *stack)
{
	return (stack->lst.size);
}

void	ft_rotate_stacks(t_stack *a, t_stack *b, char side)
{
	if (side == 'u')
	{
		if (a->lst.head)
			ft_rotate_up_list(&a->lst);
		if (b->lst.head)
			ft_rotate_up_list(&b->lst);
		ft_printf("rr\n");
	}
	else
	{
		if (a->lst.head)
			ft_rotate_down_list(&a->lst);
		if (b->lst.head)
			ft_rotate_down_list(&b->lst);
		ft_printf("rrr\n");
	}
}

void	ft_push_from_to(t_stack *from, t_stack *to)
{
	int	tmp;

	tmp = ft_stack_top(from);
	ft_push_stack(to, tmp);
	ft_pop_stack(from);
	if (to->type == 'a')
		ft_printf("pa\n");
	if (to->type == 'b')
		ft_printf("pb\n");
}
