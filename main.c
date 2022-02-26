/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:28:46 by azane             #+#    #+#             */
/*   Updated: 2022/02/26 21:32:35 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include <stdio.h>

void	ft_print_stack(t_stack *stack)
{
	const t_node	*node = stack->lst.head;

	if (!stack->lst.head)
		return ;
	while (node != stack->lst.head->prev)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
	printf("%d\n", node->data);
}

int main()
{
	t_stack	a;
	t_stack	b;

	ft_init_stack(&a);
	ft_init_stack(&b);
	for (int i = 0; i < 20; i++)
		ft_push_stack(&a, i);
	ft_starting_position(&a, &b);
	ft_print_stack(&a);
	printf("-------\n");
	ft_print_stack(&b);
	return (0);
}