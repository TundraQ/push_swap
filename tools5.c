/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 04:27:20 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 04:28:32 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_stack(t_stack *stack)
{
	ft_clear_list(&stack->lst);
}

int	ft_stack_top(t_stack *stack)
{
	return (stack->lst.head->data);
}

int	ft_stack_size(t_stack *stack)
{
	return (stack->lst.size);
}
