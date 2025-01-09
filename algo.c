/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:19:10 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/07 21:51:47 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *sorted(t_list *list)
{
    //printf("test2");
    int i;
    int swap;
    int *tab;
    int size = ft_lstsize(list);
    int j;

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