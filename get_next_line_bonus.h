/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:53:05 by smuravye          #+#    #+#             */
/*   Updated: 2023/10/20 09:53:47 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	buf_to_node(t_list **list, int fd);
int		found_new_line(t_list *list);
void	extend_list(t_list	**list, char *buffer);
t_list	*ft_lstlast(t_list *lst);
char	*parse_result_line(t_list *list);
int		count_until_nl(t_list *list);
void	node_string_to_result(t_list *list, char *str);
void	cleanup_list(t_list **list);
void	clean_all(t_list **list, t_list *node_continued, char *leftover);

#endif