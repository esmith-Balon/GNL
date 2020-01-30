/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esmith <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 00:18:24 by esmith       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 22:53:39 by esmith      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_free(int fd, t_list **list)
{
	t_list	*scout;
	t_list	*prev;

	prev = *list;
	if (prev->fd == fd)
	{
		scout = prev->next;
		free(prev->rest);
		free(prev);
		*list = scout;
		return (0);
	}
	scout = prev->next;
	while (scout->fd != fd)
	{
		prev = prev->next;
		scout = scout->next;
	}
	prev->next = scout->next;
	free(scout->rest);
	free(scout);
	return (0);
}

t_list	*find_fd(int fd, t_list **list)
{
	t_list	*curr;
	t_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	new->rest = 0;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		return (*list);
	}
	curr = *list;
	if (fd != curr->fd)
	{
		while (curr->next != NULL && fd != curr->fd)
			curr = curr->next;
		if (curr->next == NULL)
			return (curr->next = new);
	}
	free(new);
	return (curr);
}

int		ft_read(int fd, char **line, t_list *curr)
{
	char		*buf;
	char		*end;
	long int	size;

	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	*buf = 0;
	*line = ft_strjoin(*line, curr->rest);
	size = BUFFER_SIZE;
	while ((end = ft_strchr(buf, 10)) == NULL && size == BUFFER_SIZE)
	{
		*line = ft_strjoin(*line, buf);
		if ((size = read(fd, buf, BUFFER_SIZE)) == -1)
			free(buf);
		if (size == -1)
			return (-1);
		buf[size] = 0;
	}
	*line = ft_strjoin(*line, buf);
	if (end)
		curr->rest = ft_swap(end + 1, curr->rest);
	free(buf);
	if (!end)
		return (0);
	return (size);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*list;
	t_list			*curr;
	char			*end;
	int				size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(*line = malloc(1)))
		return (-1);
	**line = 0;
	curr = find_fd(fd, &list);
	if (ft_strchr(curr->rest, 10) == NULL)
		size = ft_read(fd, line, curr);
	else
	{
		end = ft_strchr(curr->rest, 10);
		*line = ft_strjoin(*line, curr->rest);
		curr->rest = ft_swap(end + 1, curr->rest);
		size = 1;
	}
	if (size > 0)
		return (1);
	ft_free(fd, &list);
	return ((size == -1) ? -1 : 0);
}
