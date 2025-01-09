/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:05:15 by souel-bo          #+#    #+#             */
/*   Updated: 2025/01/07 21:31:09 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct node{
    void    *content;
    struct node *next;
}   t_list;

//linked list functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//other libft functions
int     ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

//function helper
void	free_split(char **split);
t_list *create_list(char *argument, t_list **list);
void    del(void *element);
int	check_if_sorted(t_list **list);

//push swap functions
void    swap_a(t_list **list);
void	swap_b(t_list **list);
void	swap_stacks(t_list **list1, t_list **list2);
void	push_b(t_list **list1, t_list **list2);
void	push_a(t_list **list1, t_list **list2);
void	rotate_a(t_list **list1);
void	rotate_b(t_list **list2);
void	rotate_stacks(t_list **list1, t_list **list2);
void	reverse_rotate_a(t_list **list1);
void	reverse_rotate_b(t_list **list2);
void	reverse_rotate_stacks(t_list **list1, t_list **list2);

//helper functions
void    check_size(t_list **list, t_list **list_2);
int     max(t_list *list);
void    check_list(t_list *list);
int *sorted(t_list *list);

# endif