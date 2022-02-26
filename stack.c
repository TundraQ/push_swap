/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:37:52 by azane             #+#    #+#             */
/*   Updated: 2022/02/26 20:56:35 by azane            ###   ########.fr       */
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
}

void	ft_rotate_down_stack(t_stack *stack)
{
	if (stack->lst.head)	
		ft_rotate_down_list(&stack->lst);
}

void	ft_swap_stack(t_stack *stack)
{
	if (stack->lst.size > 1)
		ft_swap_list(&stack->lst);
}

void	ft_clear_stack(t_stack *stack)
{
	ft_clear_list(&stack->lst);
}