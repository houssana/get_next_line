# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houssana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 19:29:54 by houssana          #+#    #+#              #
#    Updated: 2017/04/17 19:45:59 by houssana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
FLAGS=-Wall -Wextra -Werror -c
FILES1=ft_{memset,bzero,memcpy,memccpy,memmove,memchr,memcmp,strlen,strdup,strcpy,strncpy,strcat,strncat,strlcat,strchr,strrchr,strstr,strnstr,strcmp,strncmp,atoi,isalpha,isdigit,isalnum,isascii,isprint,toupper,tolower}
FILES2=ft_{memalloc,memdel,strnew,strdel,strclr,striter,striteri,strmap,strmapi,strequ,strnequ,strsub,strjoin,strtrim,strsplit,itoa,putchar,putstr,putendl,putnbr,putchar_fd,putstr_fd,putendl_fd,putnbr_fd}
FILES3=ft_{lstnew,lstdelone,lstdel,lstadd,lstiter,lstmap}

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(FILES1).c $(FILES2).c $(FILES3).c
	ar rc $(NAME) $(FILES1).o $(FILES2).o $(FILES3).o
	ranlib $(NAME)

clean:
	rm -f $(FILES1).o $(FILES2).o $(FILES3).o

fclean: clean
	rm -f $(NAME)

re: fclean all
