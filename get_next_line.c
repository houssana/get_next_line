/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:13:58 by houssana          #+#    #+#             */
/*   Updated: 2017/05/06 18:29:03 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"

int		add_to_list(t_str **list, const int fd, t_str *tmp)
{
	char	*buffer;
	char	*tmp_str;
	int		len;

	tmp->fd = fd;
	tmp->next = *list;
	tmp->str = ft_strnew(0);
	tmp->curr_line = 0;
	*list = tmp;
	if (!(buffer = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	while ((len = read(fd, buffer, BUFF_SIZE)))
	{
		if (len == -1)
			return (0);
		buffer[len] = '\0';
		tmp_str = ft_strnew(ft_strlen(tmp->str) + len + 1);
		ft_strcpy(tmp_str, tmp->str);
		ft_strcat(tmp_str, buffer);
		ft_strdel(&(tmp->str));
		tmp->str = ft_strdup(tmp_str);
		ft_strdel(&tmp_str);
	}
	return (1);
}

void	remove_from_lst(const int fd, t_str **lst)
{
	t_str	*prev;
	t_str	*l;

	prev = 0;
	l = *lst;
	while (l && l->fd != fd)
	{
		prev = l;
		l = l->next;
	}
	if (prev)
		prev->next = l->next;
	else if (l->next)
		*lst = l->next;
	else
		*lst = 0;
	ft_strdel(&(l->str));
	ft_memdel((void **)&l);
}

int		print_next_line(const int fd, char **line, t_str **lst, t_str *tmp)
{
	int		i;
	char	*s;

	i = 0;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	s = tmp->str;
	while (*s && i < tmp->curr_line)
		if (*(s++) == '\n')
			i++;
	if (!(*s))
	{
		remove_from_lst(fd, lst);
		return (0);
	}
	tmp->curr_line = i + 1;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(*line = (char *)ft_memalloc(i + 1)))
		return (-1);
	*line = ft_strsub(s, 0, i);
	ft_putstr(*line);
	ft_putstr("\n");
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_str	*str_lst = 0;
	t_str			*tmp;

	if (!line)
		return (-1);
	tmp = str_lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		if (!(tmp = (t_str *)malloc(sizeof(t_str))))
			return (-1);
		if (!(add_to_list(&str_lst, fd, tmp)))
			return (-1);
	}
	return (print_next_line(fd, line, &str_lst, tmp));
	return (1);
}
