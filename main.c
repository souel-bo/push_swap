/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:06:13 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 13:02:18 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*list;
	t_list	*list_2;

	if (argc < 2)
		return (1);
	i = 1;
	list = NULL;
	list_2 = NULL;
	while (i < argc)
	{
		list = create_list(argv[i], &list);
		i++;
	}
	if (ft_lstsize(list) < 2)
		return (1);
	check_list(list);
	if (check_if_sorted(&list) == 1)
	{
		ft_lstclear(&list, free);
		exit(EXIT_FAILURE);
	}
	check_size(&list, &list_2);
	ft_lstclear(&list, free);
}
