/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 11:08:00 by houssana          #+#    #+#             */
/*   Updated: 2017/05/06 16:35:34 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"

int		main(int argc, const char *argv[])
{
	char	*s;
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	int		i;

	i = 0;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	while(i++ < 15)
		get_next_line(fd1, &s);
	while(i++ < 35)
		get_next_line(fd2, &s);
	while(i++ < 70)
		get_next_line(fd3, &s);
	while(i++ < 85)
		get_next_line(fd1, &s);
	return (0);

//	while (--argc)
//	{
	fd = open(argv[1], O_RDONLY);
	ft_putnbr(fd);
	ft_putstr("\n");
	while (get_next_line(fd, &s) == 1)
		ft_putstr("\n");
	close(fd);
	fd = open(argv[2], O_RDONLY);
	ft_putnbr(fd);
	ft_putstr("\n");
	while (get_next_line(fd, &s) == 1)
		ft_putstr("\n");
	close(fd);
//	}
	return (0);
}
