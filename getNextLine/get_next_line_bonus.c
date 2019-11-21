/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:28:28 by abdait-m          #+#    #+#             */
/*   Updated: 2019/11/20 13:14:08 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		ft_cleanall(char **s_tab)
{
	if (s_tab != NULL && *s_tab != NULL)
	{
		free(*s_tab);
		*s_tab = NULL;
	}
}

int			ft_checkline(char **s_tab, char **line)
{
	int			i;
	char		*tmp2;

	i = 0;
	while (s_tab[0][i] != '\n' && s_tab[0][i] != '\0')
		i++;
	if (s_tab[0][i] == '\n')
	{
		*line = ft_substr(*s_tab, 0, i);
		tmp2 = ft_strdup(&(s_tab[0][i + 1]));
		free(*s_tab);
		*s_tab = tmp2;
		if (s_tab[0][0] == '\0')
			ft_cleanall(s_tab);
	}
	else
	{
		*line = ft_strdup(s_tab[0]);
		ft_cleanall(s_tab);
	}
	return (1);
}

int			ft_help(char **line, char **s_tab, int byt, int fd)
{
	*line = NULL;
	if (byt == -1)
		return (-1);
	else if (byt == 0 && s_tab[fd] == NULL)
		return (0);
	else
		return (ft_checkline(&s_tab[fd], line));
}

int			get_next_line(int fd, char **line)
{
	static char		*s_tab[F_LIMIT];
	char			*buff;
	int				byt;

	if (fd < 0 || BUFFER_SIZE <= 0 ||
			!line || !(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (ft_help(line, s_tab, -1, 0));
	while ((byt = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byt] = '\0';
		if (s_tab[fd] == NULL)
			s_tab[fd] = ft_strdup(buff);
		else
			s_tab[fd] = ft_strjoin(s_tab[fd], buff);
		if (ft_strchr(s_tab[fd], '\n'))
			break ;
	}
	free(buff);
	return (ft_help(line, s_tab, byt, fd));
}
