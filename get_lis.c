/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:56:45 by azane             #+#    #+#             */
/*   Updated: 2022/03/14 20:20:05 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_norm
{
	int					*p;
	int					*d;
	int					*values;
	int					*lis;
	t_stack_iterator	it;
	t_stack_iterator	end;
	int					i;
	int					tmp;
	int					j;
	int					pos;
}	t_norm;

static void	ft_get_lis2(t_stack *stack, int *size, t_norm *norm)
{
	(void) size;
	while (!ft_stiter_equal(&norm->it, &norm->end))
	{
		norm->values[norm->i++] = ft_stiter_value(&norm->it);
		ft_stiter_next(&norm->it);
	}
	norm->i = -1;
	while (++norm->i < ft_stack_size(stack))
	{
		norm->d[norm->i] = 1;
		norm->p[norm->i] = -1;
		norm->j = -1;
		while (++norm->j < norm->i)
		{
			if (norm->values[norm->j] < norm->values[norm->i])
			{
				if (1 + norm->d[norm->j] > norm->d[norm->i])
				{
					norm->d[norm->i] = 1 + norm->d[norm->j];
					norm->p[norm->i] = norm->j;
				}
			}
		}
	}
}

static void	ft_get_lis3(t_stack *stack, int *size, t_norm *norm)
{
	(void) stack;
	(void) size;
	while (norm->pos != -1)
	{
		norm->lis[norm->i++] = norm->values[norm->pos];
		norm->pos = norm->p[norm->pos];
	}
	norm->j = 0;
	while (norm->j < norm->i / 2)
	{
		norm->tmp = norm->lis[norm->j];
		norm->lis[norm->j] = norm->lis[norm->i - norm->j - 1];
		norm->lis[norm->i - norm->j - 1] = norm->tmp;
		norm->j++;
	}
}

int	*ft_get_lis(t_stack *stack, int *size)
{
	t_norm	norm;

	norm.values = malloc(ft_stack_size(stack) * sizeof(int));
	norm.d = malloc(ft_stack_size(stack) * sizeof(int));
	norm.p = malloc(ft_stack_size(stack) * sizeof(int));
	norm.lis = malloc(ft_stack_size(stack) * sizeof(int));
	norm.it = ft_stack_begin(stack);
	norm.end = ft_stack_end(stack);
	norm.i = 0;
	ft_get_lis2(stack, size, &norm);
	norm.pos = norm.i - 1;
	norm.i = 0;
	ft_get_lis3(stack, size, &norm);
	*size = norm.i;
	free(norm.values);
	free(norm.d);
	free(norm.p);
	return (norm.lis);
}

int	*ft_get_best_lis(t_stack *stack, int *size)
{
	int	i;
	int	**lis;
	int	*res;
	int	tmp[2];

	lis = malloc(sizeof(int *) * ft_stack_size(stack));
	i = -1;
	while (++i < ft_stack_size(stack) - 1)
	{
		ft_rotate_up_list(&stack->lst);
		lis[i] = ft_get_lis(stack, &tmp[0]);
		if (tmp[0] > *size)
		{
			*size = tmp[0];
			tmp[1] = i;
		}
	}
	ft_rotate_up_list(&stack->lst);
	i = 0;
	while (i < ft_stack_size(stack) - 1)
		if (i++ != tmp[1])
			free(lis[i - 1]);
	res = lis[tmp[1]];
	free(lis);
	return (res);
}
