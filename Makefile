# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habouda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 01:37:02 by Habouda           #+#    #+#              #
#    Updated: 2024/05/21 20:47:53 by habouda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPIL #####################################################################

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
NAME = libft.a

### SRC ########################################################################

SRCS	=	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_strtrim.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_substr.c \
		ft_toupper.c \
		ft_strjoin.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_itoa.c \
		ft_strjoin.c \
		ft_split.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_strdup.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \


SRCS_BONUS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

### OBJS ###########################################################################
			
OBJS	= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
### COMMANDS #######################################################################

all: $(NAME)  

$(NAME): $(OBJS) 
		ar rcs $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:	clean
	rm -f $(NAME)

re : fclean all

.PHONY : all re fclean clean


