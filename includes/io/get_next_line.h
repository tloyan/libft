/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tloyan <tloyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:16:47 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 12:57:31 by tloyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef FT_FD_MAX
#  define FT_FD_MAX 256
# endif

# include "../list/ft_list.h"

char	*get_next_line(int fd);
int		read_and_stash(t_list **lst, int fd);
void	create_line(t_list	**lst, char **line);
void	update_stash(t_list *lst);
t_list	*ft_lstnew_gnl(t_list **lst, char *buffer);

#endif