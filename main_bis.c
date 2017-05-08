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

#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int	files_has(char **files, char *file, int len)
{
	while (len--)
		if (!ft_strcmp(file, files[len]))
			return (1);
	return (0);
}

int	add_file(char **files, int *fds, char *file)
{
	int i;
	int fd;

	i = -1;
	while (1)
		if (files[++i][0] == '\0')
		{
			files[i] = file;
			break ;
		}
	fd = open(file, O_RDONLY);
	fds[i] = fd;
	return (fd);	
}

int	get_fd(char **files, int *fds, char *file)
{
	int i;

	i = -1;
	while (1)
		if (!ft_strcmp(files[++i], file))
			return (fds[i]);
}

void	close_file(char **files, int *fds, int fd)
{
	int i;

	i = -1;
	while (1)
		if (fds[++i] == fd)
		{
			fds[i] = 0;
			break ;
		}
//	ft_putstr("EOF ");
//	ft_putstr(files[i]);
//	ft_putstr("\n");
//	files[i][0] = '\0';
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	fd;
	char	**files;
	int	*fds;
	char	*line;

	files = (char **)malloc(sizeof(char *) * (argc / 2));
	i = -1;
	while (++i < argc / 2)
		files[i] = (char *)ft_memalloc(sizeof(char) * 20);
	fds = (int *)ft_memalloc(sizeof(int) * (argc / 2));
	i = 1;
	while (i < argc)
	{
		j = -1;
		if (!files_has(files, argv[i], argc / 2))
		{
			fd = add_file(files, fds, argv[i]);
		}
		else
		{
			fd = get_fd(files, fds, argv[i]);
		}
		while (++j < atoi(argv[i + 1]))
		{
			if (get_next_line(fd, &line) == 0)
			{
				close_file(files, fds, fd); 
				break ;
			}
			ft_putstr(line);
			free(line);
			ft_putstr("\n");
		}
		i += 2;
	}
	return (0);
}
