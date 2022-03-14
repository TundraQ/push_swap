/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 04:27:20 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 21:35:19 by azane            ###   ########.fr       */
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

int	ft_check_arg(char *argv)
{
	long long	i;
	int			zero;

	i = 0;
	zero = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			if (!(i == 0 && (argv[i] == '-' || argv[i] == '+')))
				ft_fatal("");
		}
		i++;
	}
	i = 0;
	while (argv[i] && argv[i++] == '0')
		zero++;
	if (ft_strlen(argv) - zero > 12)
		ft_fatal("");
	i = ft_atoi(argv);
	if (i > 2147483647 || i < -2147483648)
		ft_fatal("");
	return ((int) i);
}
