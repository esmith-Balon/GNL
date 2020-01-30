/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esmith <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 00:18:39 by esmith       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 06:48:50 by esmith      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				fd;
	char			*rest;
	struct s_list	*next;
}					t_list;

int					ft_free(int fd, t_list **list);
t_list				*find_fd(int fd, t_list **list);
int					ft_read(int fd, char **line, t_list *curr);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_swap(char *s1, char *free_ft);

#endif
