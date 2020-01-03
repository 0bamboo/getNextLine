/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:51:06 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/01 15:57:13 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		j;

	j = 0;
	while (*s != '\0')
	{
		j++;
		s++;
	}
	return (j);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(s);
	if (!(tmp = (char *)malloc(len + 1)))
		return (0);
	while (i <= len)
	{
		tmp[i] = s[i];
		i++;
	}
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		j;
	char		*sub;

	if (!s || !(sub = (char *)malloc(len + 1)))
		return (NULL);
	if (start > len)
		return (ft_strdup(""));
	j = 0;
	while (j < len)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		l;
	char	*join;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	l = i + j;
	if (!(join = (char *)malloc((l + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		join[i] = s2[j];
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}
