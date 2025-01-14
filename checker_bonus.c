/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:46:48 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/14 11:29:35 by souel-bo         ###   ########.fr       */
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

void	sorting_aplly(char *input, t_list **list_1, t_list **list_2)
{
	if (ft_strncmp(input, "ra\n", 3) == 0)
		rotate_a_bonus(&*list_1);
}

int	main(int argc, char **argv)
{
	t_list	*list_1;
    t_list	*list_2;
	int		i;
	char	*input;

	if (argc < 2)
		return (1);
	i = 1;
	list_1 = NULL;
	list_2 = NULL;
	while (i < argc)
	{
		list_1 = create_list(argv[i], &list_1);
		i++;	
	}
	check_list(list_1);
	while (input = get_next_line(0) != NULL)
	{
		sorting_aplly(input, &list_1, &list_2);
		free(input);
	}
	if (check_if_sorted(&*list_1) == 1)
		ok(list_1);
	else if (check_if_sorted(&*list_1) == 0)
		ko(list_1);
}
