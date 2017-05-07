/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 11:08:00 by houssana          #+#    #+#             */
/*   Updated: 2017/05/06 17:19:02 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"

int		main(int argc, const char *argv[])
{
	int		fd0;
	int		fd1;
	int		fd2;
	int		fd3;

	char	*line_fd0;
	char	*line_fd1;
	char	*line_fd2;
	char	*line_fd3;

	fd0 = open("in_0", O_RDONLY);
	fd1 = open("in_1", O_RDONLY);
	fd2 = open("in_2", O_RDONLY);
	fd3 = open("in_3", O_RDONLY);

	get_next_line(fd0, &line_fd0);
	ft_putstr(line_fd0);
	ft_putstr("\n");

	get_next_line(fd1, &line_fd1);
	ft_putstr(line_fd1);
	ft_putstr("\n");

	get_next_line(fd2, &line_fd2);
	ft_putstr(line_fd2);
	ft_putstr("\n");

	get_next_line(fd3, &line_fd3);
	ft_putstr(line_fd3);
	ft_putstr("\n");

	get_next_line(fd0, &line_fd0);
	ft_putstr(line_fd0);
	ft_putstr("\n");

	get_next_line(fd1, &line_fd1);
	ft_putstr(line_fd1);
	ft_putstr("\n");

	get_next_line(fd2, &line_fd2);
	ft_putstr(line_fd2);
	ft_putstr("\n");

	get_next_line(fd3, &line_fd3);
	ft_putstr(line_fd3);
	ft_putstr("\n");
	return (0);
}
