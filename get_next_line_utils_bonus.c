/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:53:08 by smuravye          #+#    #+#             */
/*   Updated: 2023/10/20 09:53:26 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	found_new_line(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->line[i])
		{
			if (list->line[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	count_until_nl(t_list *list)
{
	int	i;
	int	length;

	if (!list)
		return (0);
	length = 0;
	while (list)
	{
		i = 0;
		while (list->line[i])
		{
			if (list->line[i] == '\n')
			{
				length++;
				return (length);
			}
			i++;
			length++;
		}
		list = list->next;
	}
	return (length);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	node_string_to_result(t_list *list, char *str)
{
	int	i;
	int	j;

	j = 0;
	if (!list)
		return ;
	while (list)
	{
		i = 0;
		while (list->line[i])
		{
			if (list->line[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->line[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

void	clean_all(t_list **list, t_list *node_continued, char *leftover)
{
	t_list	*current;

	if (!list)
		return ;
	while (*list)
	{
		current = (*list)->next;
		free((*list)->line);
		free(*list);
		*list = current;
	}
	if (!node_continued && !leftover)
		return ;
	*list = NULL;
	if (node_continued->line[0])
		*list = node_continued;
	else
	{
		free(leftover);
		free(node_continued);
	}
}
