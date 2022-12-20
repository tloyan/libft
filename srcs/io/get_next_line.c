/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:18:05 by thloyan           #+#    #+#             */
/*   Updated: 2022/12/20 13:36:08 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_and_stash(t_list **lst, int fd)
{
	char	*buffer;
	int		readed;

	if (*lst && ft_strchr((*lst)->content, '\n'))
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!buffer)
		return (-1);
	buffer[0] = 0;
	readed = 1;
	while (readed && !ft_strchr(buffer, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), -1);
		buffer[readed] = 0;
		if (ft_lstnew_gnl(&*lst, buffer) == NULL)
			return (free(buffer), -1);
	}
	return (free(buffer), 0);
}

t_list	*ft_lstnew_gnl(t_list **lst, char *buffer)
{
	t_list	*begin;
	t_list	*new;
	char	*content;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	content = ft_strdup(buffer);
	if (!content)
		return (free(new), NULL);
	new->content = (void *)content;
	new->next = NULL;
	if (!*lst)
		return (*lst = new);
	begin = *lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = begin;
	return (*lst);
}

void	create_line(t_list	**lst, char **line)
{
	size_t		len;
	size_t		i;
	t_list		*tmp;

	len = 0;
	while (*lst)
	{
		i = 0;
		tmp = (*lst)->next;
		while (((char *)(*lst)->content)[i] != 0
			&& ((char *)(*lst)->content)[i] != '\n')
			(*line)[len++] = ((char *)(*lst)->content)[i++];
		if (((char *)(*lst)->content)[i] == '\n')
		{
			(*line)[len++] = ((char *)(*lst)->content)[i++];
			break ;
		}
		free(((char *)(*lst)->content));
		free(*lst);
		*lst = tmp;
	}
	(*line)[len] = 0;
	if (len == 0)
		return (free(*line), *line = NULL, (void)0);
}

void	update_stash(t_list *lst)
{
	char		*str;
	size_t		i;
	size_t		n;

	if (!lst)
		return ;
	str = ft_strchr((lst)->content, '\n') + 1;
	n = ft_strlen(str);
	i = 0;
	while (n--)
	{
		((char *)(lst)->content)[i] = str[i];
		i++;
	}
	((char *)(lst)->content)[i] = 0;
}

char	*get_next_line(int fd)
{
	static t_list	*lsts[FT_FD_MAX] = {};
	char			*line;
	int				i;

	line = NULL;
	if (fd >= FT_FD_MAX || fd < 0)
	{
		i = -1;
		while (++i < FT_FD_MAX)
			ft_lstclear(&lsts[i], &free);
		return (NULL);
	}
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > (INT_MAX - 1))
		return (NULL);
	if (read_and_stash(&lsts[fd], fd) == -1)
		return (ft_lstclear(&lsts[fd], &free), NULL);
	line = malloc(((ft_lstsize(lsts[fd]) * BUFFER_SIZE) + 1) * sizeof(*line));
	if (!line)
		return (ft_lstclear(&lsts[fd], &free), NULL);
	create_line(&lsts[fd], &line);
	update_stash(lsts[fd]);
	return (line);
}
