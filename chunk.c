/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:42:19 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/12 14:00:50 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*sorted(t_list *list)
{
	int	i;
	int	*tab;
	int	size;

	size = ft_lstsize(list);
	tab = (int *)malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	i = 0;
	while (list != NULL)
	{
		tab[i] = *(int *)list->content;
		list = list->next;
		i++;
	}
	tab = sort_int_tab(tab, size);
	return (tab);
}

void	indexing(t_list *list, int *sorted_array)
{
	int		size;
	int		i;
	t_list	*current;

	current = list;
	size = ft_lstsize(list);
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)current->content == sorted_array[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}
