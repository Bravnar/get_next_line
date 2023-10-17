/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:26:07 by smuravye          #+#    #+#             */
/*   Updated: 2023/10/17 12:12:08 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	found_new_line(t_list *list) //DONE
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

int	count_until_nl(t_list *list) //DONE (CHECK) -- THIS WON'T WORK,
// DO FOUND_NEW_LINE FUNCT
{
	int	length;

	if (!list)
		return (NULL);
	while (list->line[length])
	{
		if (list->line[length] == '\n')
			return (length);
		length++;
	}
	return (length);
}

t_list	*ft_lstlast(t_list *lst) //DONE
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	extend_list(t_list	**list, char *buffer) //DONE
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

void	buf_to_node(t_list **list, int fd) //DONE
{
	int		bytes_read;
	char	*buffer;

	while (!found_new_line(list))
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
	static t_list	*lines;
	char			*result;

	lines = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &result, BUFFER_SIZE) < 0)
		return (NULL);
	buf_to_node(lines, fd);
	if (!lines)
		return (NULL);
	result = parse_line(lines);
	/* cleanup_list(&lines) */;
	return (result);
}

/* int	main()
{
	int	fd;
	char *result;
	
	fd = open("test.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s\n", result);
	free(result);
}
 */
/* #include "get_next_line.h"

size_t	new_line_found(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i+1);
		i++;
	}
	return (i);
}

char	*return_buffer(t_struct *to_read)
{
	const char	*tmp;
	char	*line;

	line = NULL;
	to_read->bytes_read = read(to_read->fd, to_read->buf, sizeof(to_read->buf));
	if (to_read->bytes_read < 0)
	{
		free(line);
		return (NULL);
	}
	//int i = 42;
	//printf("|%d|", to_read->buf[i]);
	tmp = ft_strdup(to_read->buf);
	line = malloc(sizeof(char) * (new_line_found(tmp) + 1));
	if (!line)
		return (NULL);
	line = ft_strlcpy(line, tmp, new_line_found(tmp));
	//printf("%s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_struct	to_read;
	char			*result;

	to_read.fd = fd;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	result = return_buffer(&to_read);
	return (result);
}
 */