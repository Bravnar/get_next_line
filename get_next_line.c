/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravyev <smuravyev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:26:07 by smuravye          #+#    #+#             */
/*   Updated: 2023/10/15 20:01:52 by smuravyev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_read_buffer(t_list *list)
{
	if (!list)
		
}

char *get_next_line(int fd)
{
	static t_list	*lines;
	char			*result;
	
	lines = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || )
		return (NULL);
	//create_list(list, fd);
	// --> this is where you read the file
	if (!lines)
		return (NULL);
	// function that extracts the next line from the linked list
	// function that cleans up the linked list
	return (result);
}

int	main()
{
	int	fd;
	char *result;
	
	fd = open("test.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s\n", result);
	free(result);
}

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