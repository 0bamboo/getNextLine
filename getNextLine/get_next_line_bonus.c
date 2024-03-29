/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:52:57 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/01 18:38:01 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		ft_cleanall(char **s_tab)
{
	if (s_tab && *s_tab)
	{
		free(*s_tab);
		*s_tab = NULL;
	}
}

int			ft_checkline(char **s_tab, char **line, int byt)
{
	int			i;
	char		*tmp2;

	i = 0;
	while (s_tab[0][i] != '\n' && s_tab[0][i] != '\0')
		i++;
	if (s_tab[0][i] == '\n')
	{
		free(*line);
		*line = ft_substr(*s_tab, 0, i);
		tmp2 = ft_strdup(*s_tab + i + 1);
		free(*s_tab);
		*s_tab = tmp2;
		if (s_tab[0][0] == '\0')
			ft_cleanall(s_tab);
	}
	else
	{
		free(*line);
		*line = ft_strdup(s_tab[0]);
		ft_cleanall(s_tab);
		if (!byt)
			return (0);
	}
	return (1);
}

int			ft_help(char **line, char **s_tab, int byt, int fd)
{
	if (line)
		*line = ft_strdup("");
	if (byt == -1)
		return (-1);
	else if (byt == 0 && s_tab[fd] == NULL)
		return (0);
	else
		return (ft_checkline(&s_tab[fd], line, byt));
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
