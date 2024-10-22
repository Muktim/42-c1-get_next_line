/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:52:21 by mcoskune          #+#    #+#             */
/*   Updated: 2024/05/18 15:23:24 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_up(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = 0;
	buff = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buff || !clean_node)
		return ;
	last_node = find_last_node(*list);
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		buff[j++] = last_node->content[i];
	buff[j] = '\0';
	clean_node->content = buff;
	clean_node->next = NULL;
	dealloc(list, clean_node, buff);
}

char	*get_line(t_list *list)
{
	int		len;
	char	*full_str;

	if (!list)
		return (NULL);
	len = len_to_new_line(list);
	full_str = malloc (len + 1);
	if (!full_str)
		return (NULL);
	copy_str(list, full_str);
	return (full_str);
}

void	append(t_list **list, char *buff, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node (list[fd]);
	new_node = malloc (sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->content = buff;
	new_node->next = NULL;
}

int	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buff;

	while (!found_new_line (list[fd]))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (0);
		char_read = read (fd, buff, BUFFER_SIZE);
		if (char_read == -1)
		{
			free (buff);
			return (-1);
		}
		if (!char_read)
		{
			free (buff);
			return (0);
		}
		buff[char_read] = '\0';
		append(list, buff, fd);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list[1024];
	char			*next_line;
	int				i;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	i = create_list (list, fd);
	if (!list[fd] || i < 0)
		return (NULL);
	next_line = get_line(list[fd]);
	clean_up(&list[fd]);
	return (next_line);
}
