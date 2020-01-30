/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esmith <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 00:18:56 by esmith       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 09:54:40 by esmith      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	c = (char)c;
	if (!s)
		return (NULL);
	while (s[i] != 0 && s[i] != c)
		i++;
	if (s[i] != c)
		return (NULL);
	return ((char *)s + i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;
	size_t	size1;
	size_t	size2;

	i = -1;
	j = -1;
	size1 = ft_strlen(s1, 10);
	size2 = ft_strlen(s2, 10);
	if (!(dst = malloc(size1 + size2 + 1)))
		return (NULL);
	while (++i < size1)
		dst[i] = s1[i];
	while (++j < size2)
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}

char	*ft_swap(char *s1, char *free_ft)
{
	char	*dst;
	int		i;

	if (!(dst = malloc(ft_strlen(s1, 0) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	free(free_ft);
	return (dst);
}
