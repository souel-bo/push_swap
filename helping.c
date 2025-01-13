/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:35:22 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/13 07:16:47 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list *list)
{
	int		max;
	t_list	*start;

	start = list;
	max = *(int *)list->content;
	while (start != NULL)
	{
		if (max < *(int *)start->content)
			max = *(int *)start->content;
		start = start->next;
	}
	return (max);
}

int	min(t_list *list)
{
	int		max;
	t_list	*start;

	start = list;
	max = *(int *)list->content;
	while (start != NULL)
	{
		if (max > *(int *)start->content)
			max = *(int *)start->content;
		start = start->next;
	}
	return (max);
}

void	sort_3(t_list **list)
{
	if (*(int *)(*list)->content == max(*list))
		rotate_a(&*list);
	else if (*(int *)(*list)->next->content == max(*list))
		reverse_rotate_a(&*list);
	if (*(int *)(*list)->content > *(int *)(*list)->next->content)
		swap_a(&*list);
}

void	help_4(t_list **list, t_list **list_2)
{
	swap_a(&*list);
	push_b(&*list, &*list_2);
	sort_3(&*list);
	push_a(&*list, &*list_2);
}

void	rotate_a(t_list **list1)
{
	t_list	*temp;

	if (!list1 || !*list1 || (*list1)->next == NULL)
		return ;
	temp = *list1;
	*list1 = (*list1)->next;
	temp->next = NULL;
	ft_lstadd_back(list1, temp);
	write(1, "ra\n", 3);
}
