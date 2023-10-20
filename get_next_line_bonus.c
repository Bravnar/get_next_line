/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:53:02 by smuravye          #+#    #+#             */
/*   Updated: 2023/10/20 09:54:14 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cleanup_list(t_list **list)
{
	t_list	*node_continued;
	t_list	*last_node;
	int		i;
	int		j;
	char	*new_buffer;

	node_continued = malloc(sizeof(t_list));
	new_buffer = malloc(BUFFER_SIZE + 1);
	if (!new_buffer || !node_continued)
		return ;
	i = 0;
	j = 0;
	last_node = ft_lstlast(*list);
	while (last_node->line[i] && last_node->line[i] != '\n')
		i++;
	while (last_node->line[i] && last_node->line[++i])
		new_buffer[j++] = last_node->line[i];
	new_buffer[j] = '\0';
	node_continued->line = new_buffer;
	node_continued->next = NULL;
	clean_all(list, node_continued, new_buffer);
}

char	*parse_result_line(t_list *list)
{
	int		full_length;
	char	*result;

	if (!list)
		return (NULL);
	full_length = count_until_nl(list);
	result = malloc(sizeof(char) * (full_length + 1));
	if (!result)
		return (NULL);
	node_string_to_result(list, result);
	return (result);
}

void	extend_list(t_list	**list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->line = buffer;
	new_node->next = NULL;
}

void	buf_to_node(t_list **list, int fd)
{
	int		bytes_read;
	char	*buffer;

	while (!found_new_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		extend_list(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lines = NULL;
	char			*result;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, &result, 0))
	{
		clean_all(&lines, NULL, NULL);
		return (NULL);
	}
	buf_to_node(&lines, fd);
	if (!lines)
		return (NULL);
	result = parse_result_line(lines);
	cleanup_list(&lines);
	return (result);
}
