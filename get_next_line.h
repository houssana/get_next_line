/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:11:54 by houssana          #+#    #+#             */
/*   Updated: 2017/05/06 13:32:09 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9999

int						get_next_line(const int fd, char **line);
typedef struct s_str	t_str;
struct					s_str
{
	int		curr_line;
	int		fd;
	char	*str;
	t_str	*next;
};
#endif
