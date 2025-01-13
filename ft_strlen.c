/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:59:25 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/13 21:16:57 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - s));
}

void	check_list(t_list *list)
{
	t_list	*start;
	t_list	*check;

	start = list;
	while (start->next != NULL)
	{
		check = start->next;
		while (check != NULL)
		{
			if (*(int *)(start->content) == *(int *)(check->content))
			{
				ft_error("Error\n");
				ft_lstclear(&list, free);
				exit(EXIT_FAILURE);
			}
			check = check->next;
		}
		start = start->next;
	}
}
