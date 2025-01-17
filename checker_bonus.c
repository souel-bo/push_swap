/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:46:48 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 18:00:53 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ok(t_list *list)
{
	write(1, "OK\n", 3);
	ft_lstclear(&list, free);
	exit(EXIT_FAILURE);
}

void	ko(t_list *list)
{
	write(1, "KO\n", 3);
	ft_lstclear(&list, free);
	exit(EXIT_FAILURE);
}

int	process_input_and_check(t_list **list_1, t_list **list_2)
{
	char	*input;
	int		k;

	k = 0;
	input = get_next_line(0, k);
	while (input != NULL)
	{
		k = sorting_aplly(input, list_1, list_2);
		free(input);
		input = get_next_line(0, k);
	}
	if (k == 1)
		ft_lstclear(list_1, free);
	if (*list_2 != NULL)
		ft_lstclear(list_2, free);
	if (check_if_sorted(list_1) == 1 && k == 0)
		ok(*list_1);
	else if (check_if_sorted(list_1) == 0 && k == 0)
		ko(*list_1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*list_1;
	t_list	*list_2;
	int		i;

	if (argc < 2)
		return (1);
	list_1 = NULL;
	list_2 = NULL;
	i = 1;
	while (i < argc)
	{
		list_1 = create_list(argv[i], &list_1);
		i++;
	}
	check_list(list_1);
	return (process_input_and_check(&list_1, &list_2));
}
