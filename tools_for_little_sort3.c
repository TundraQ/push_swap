/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_little_sort3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azane <azane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 05:14:13 by azane             #+#    #+#             */
/*   Updated: 2022/03/13 05:14:16 by azane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_create_array_from_list(t_dblist *list, int count)
{
	int		*array;
	t_node	*first;
	int		index;

	array = malloc(sizeof(int) * count);
	if (!array)
		return (0);
	first = list->head->next;
	index = 1;
	array[0] = list->head->data;
	while (index < count)
	{
		array[index] = first->data;
		index++;
		first = first->next;
	}
	array[0] = list->head->data;
	return (array);
}

void	ft_quick_sort(int *numbers, int left, int right)
{
	int			pivot;
	const int	l_hold = left;
	const int	r_hold = right;

	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right)
			numbers[left++] = numbers[right];
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
			numbers[right--] = numbers[left];
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		ft_quick_sort(numbers, left, pivot - 1);
	if (right > pivot)
		ft_quick_sort(numbers, pivot + 1, right);
}

int	ft_lst_get_median(t_dblist *not_empty_list, int count)
{
	int	*tmp_array;
	int	median;

	if (not_empty_list->size == 1)
		return (not_empty_list->head->data);
	tmp_array = ft_create_array_from_list(not_empty_list, count);
	if (!tmp_array)
		return (0);
	ft_quick_sort(tmp_array, 0, count - 1);
	median = tmp_array[count / 2];
	free(tmp_array);
	return (median);
}
