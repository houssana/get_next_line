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
	char	*tmp_str;

	tmp->fd = fd;
	tmp->next = *list;
	if (!(tmp->str = ft_strnew(1)))
		return (0);
	*list = tmp;
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

int		next_line(const int fd, char **line, t_str **lst, t_str *tmp)
{
	int		len;
	char	buffer[BUFF_SIZE + 1];
	char	*s;

	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	s = tmp->str;
	while (!(s = ft_strstr(tmp->str, "\n")))
	{
		if ((len = read(fd, buffer, BUFF_SIZE)) <= 0)
			return (len);
		buffer[len] = '\0';
		s = ft_strjoin(tmp->str, buffer);
		ft_strdel(&(tmp->str));
		tmp->str = s;
		if (len < BUFF_SIZE)
			break ;
	}
	s = ft_strstr(tmp->str, "\n");
	*line = ft_strsub(tmp->str, 0, (int)(s - tmp->str));
	s = ft_strsub(tmp->str, (int)(s - tmp->str + 1), ft_strlen(tmp->str) - (int)(s - tmp->str + 1));
	ft_strdel(&(tmp->str));
	tmp->str = s;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_str	*str_lst = 0;
	t_str			*tmp;
	int		r;

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
	if (!(r = next_line(fd, line, &str_lst, tmp)))
		remove_from_lst(fd, &str_lst);
	return (r);
}
