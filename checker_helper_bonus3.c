/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper_bonus2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:44:36 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 16:45:14 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_rotate(char *input, t_list **list_1, t_list **list_2)
{
    if (ft_strncmp(input, "ra\n", 3) == 0)
        rotate_a_bonus(&*list_1);
    else if (ft_strncmp(input, "rb\n", 3) == 0)
        rotate_b_bonus(&*list_2);
    else if (ft_strncmp(input, "rr\n", 3) == 0)
        rotate_stacks_bonus(&*list_1, &*list_2);
    else
        return (0);
    return (1);
}

int	handle_reverse_rotate(char *input, t_list **list_1, t_list **list_2)
{
    if (ft_strncmp(input, "rrb\n", 4) == 0)
        reverse_rotate_b_bonus(&*list_2);
    else if (ft_strncmp(input, "rra\n", 4) == 0)
        reverse_rotate_a_bonus(&*list_1);
    else if (ft_strncmp(input, "rrr\n", 4) == 0)
        reverse_rotate_stacks_bonus(&*list_1, &*list_2);
    else
        return (0);
    return (1);
}

int	handle_push(char *input, t_list **list_1, t_list **list_2)
{
    if (ft_strncmp(input, "pa\n", 3) == 0)
        push_a_bonus(&*list_1, &*list_2);
    else if (ft_strncmp(input, "pb\n", 3) == 0)
        push_b_bonus(&*list_1, &*list_2);
    else
        return (0);
    return (1);
}

int	handle_swap(char *input, t_list **list_1, t_list **list_2)
{
    if (ft_strncmp(input, "sa\n", 3) == 0)
        swap_a_bonus(&*list_1);
    else if (ft_strncmp(input, "sb\n", 3) == 0)
        swap_b_bonus(&*list_2);
    else if (ft_strncmp(input, "ss\n", 3) == 0)
        swap_stacks_bonus(&*list_1, &*list_2);
    else
        return (0);
    return (1);
}

int	sorting_aplly(char *input, t_list **list_1, t_list **list_2)
{
    if (handle_rotate(input, list_1, list_2))
        return (0);
    if (handle_reverse_rotate(input, list_1, list_2))
        return (0);
    if (handle_push(input, list_1, list_2))
        return (0);
    if (handle_swap(input, list_1, list_2))
        return (0);
    return (ft_error("Error"), 1);
}