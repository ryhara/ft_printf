# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 12:42:49 by ryhara            #+#    #+#              #
#    Updated: 2023/06/06 12:42:49 by ryhara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
SRCS = ft_printf.c \
	ft_putchar_fd_count.c \
	ft_putnbr_base_fd_count.c \
	ft_putnbr_fd_count.c \
	ft_putstr_fd_count.c \
	ft_putui_fd_count.c \
	ft_strlen.c

OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
OBJDIR = ./obj/
CC = cc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

all : $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJDIR):
	mkdir obj

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS)  -o $@ -c $<

clean :
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus