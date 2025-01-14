/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:21:54 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:49 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_list **list, t_list **list_2)
{
	if (*(int *)(*list)->content == min(*list))
	{
		push_b(&*list, &*list_2);
		sort_3(&*list);
		push_a(&*list, &*list_2);
	}
	else if (*(int *)(*list)->next->content == min(*list))
		help_4(&*list, &*list_2);
	else if (*(int *)(*list)->next->next->content == min(*list))
	{
		rotate_a(&*list);
		rotate_a(&*list);
		push_b(&*list, &*list_2);
		sort_3(&*list);
		push_a(&*list, &*list_2);
	}
	else
	{
		reverse_rotate_a(&*list);
		push_b(&*list, &*list_2);
		sort_3(&*list);
		push_a(&*list, &*list_2);
	}
}

void	helping_wiht_5(t_list **list, t_list **list_2)
{
	rotate_a(&*list);
	rotate_a(&*list);
	push_b(&*list, &*list_2);
	sort_4(&*list, &*list_2);
	push_a(&*list, &*list_2);
}

void	helping_with_5_v2(t_list **list, t_list **list_2)
{
	reverse_rotate_a(&*list);
	reverse_rotate_a(&*list);
	push_b(&*list, &*list_2);
	sort_4(&*list, &*list_2);
	push_a(&*list, &*list_2);
}

void	sort_5(t_list **list, t_list **list_2)
{
	if (*(int *)(*list)->content == min(*list))
	{
		push_b(&*list, &*list_2);
		sort_4(&*list, &*list_2);
		push_a(&*list, &*list_2);
	}
	else if (*(int *)(*list)->next->content == min(*list))
	{
		swap_a(&*list);
		push_b(&*list, &*list_2);
		sort_4(&*list, &*list_2);
		push_a(&*list, &*list_2);
	}
	else if (*(int *)(*list)->next->next->content == min(*list))
		helping_wiht_5(&*list, &*list_2);
	else if (*(int *)(*list)->next->next->next->content == min(*list))
		helping_with_5_v2(&*list, &*list_2);
	else
	{
		reverse_rotate_a(&*list);
		push_b(&*list, &*list_2);
		sort_4(&*list, &*list_2);
		push_a(&*list, &*list_2);
	}
}

void	check_size(t_list **list, t_list **list_2)
{
	int	size;

	size = ft_lstsize(*list);
	if (size == 2)
		swap_a(list);
	else if (size == 3)
		sort_3(&*list);
	else if (size == 4)
		sort_4(&*list, &*list_2);
	else if (size == 5)
		sort_5(&*list, &*list_2);
	else
		sort_more_than_six(&*list, &*list_2);
}
