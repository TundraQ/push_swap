/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:28:47 by azane             #+#    #+#             */
/*   Updated: 2022/02/17 18:21:48 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_check_argc(int argc, char **argv);
{
	int	i;
	int	k;
	int	*elements;

	i = 1;
	while (i <= argc)
	{
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	*sorted_elem;

	if (argc <= 1)
		ft_fatal("no arguments");
	sorted_elem = ft_check_argc(argc, argv);
	sorted_elem = qsort(sorted_elem);
}
