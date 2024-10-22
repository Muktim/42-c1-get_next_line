/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:52:35 by mcoskune          #+#    #+#             */
/*   Updated: 2024/05/18 15:43:42 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		create_list(t_list **list, int fd);
int		found_new_line(t_list *list);
void	append(t_list **list, char *buff, int fd);
t_list	*find_last_node(t_list *list);
char	*get_line(t_list *list);
int		len_to_new_line(t_list *list);
void	copy_str(t_list *list, char *str);
void	clean_up(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buff);

#endif
