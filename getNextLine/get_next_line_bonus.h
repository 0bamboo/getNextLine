/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:28:38 by abdait-m          #+#    #+#             */
/*   Updated: 2019/11/20 15:18:25 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# define F_LIMIT 10240

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE -1

# endif

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
void		ft_cleanall(char **s_tab);
int			ft_checkline(char **s_tab, char **line);
int			ft_help(char **line, char **s_tab, int byt, int fd);

#endif
