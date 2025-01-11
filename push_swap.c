/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:21:54 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/06 04:55:35 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max(t_list *list)
{
    int     max;
    t_list  *start;

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
int min(t_list *list)
{
    int     max;
    t_list  *start;

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

void sort_3(t_list **list)
{
    if (*(int *)(*list)->content == max(*list))
        rotate_a(&*list);
    else if (*(int *)(*list)->next->content == max(*list))
        reverse_rotate_a(&*list);
    if (*(int *)(*list)->content > *(int *)(*list)->next->content)
            swap_a(&*list);
}

void	sort_4(t_list **list, t_list ** list_2)
{
    if(*(int *)(*list)->content == min(*list))
    {
        push_b(&*list, &*list_2);
        sort_3(&*list);
        push_a(&*list, &*list_2);
    }
    else if (*(int *)(*list)->next->content == min(*list))
    {
        swap_a(&*list);
        push_b(&*list, &*list_2);
        sort_3(&*list);
        push_a(&*list, &*list_2);
    }
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

void sort_5(t_list **list, t_list **list_2)
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
    {
        rotate_a(&*list);
        rotate_a(&*list);
        //reverse_rotate_a(&*list);
        push_b(&*list, &*list_2);
        sort_4(&*list, &*list_2);
        push_a(&*list, &*list_2);
    }
    else if (*(int *)(*list)->next->next->next->content == min(*list))
    {
        reverse_rotate_a(&*list);
        reverse_rotate_a(&*list);
        push_b(&*list, &*list_2);
        sort_4(&*list, &*list_2);
        push_a(&*list, &*list_2);
    }
    else
    {
        reverse_rotate_a(&*list);
        push_b(&*list, &*list_2);
        sort_4(&*list, &*list_2);
        push_a(&*list, &*list_2);
    }
}

void check_size(t_list **list, t_list **list_2)
{
    int size = ft_lstsize(*list);

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
