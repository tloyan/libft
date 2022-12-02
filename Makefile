# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 14:07:47 by thloyan           #+#    #+#              #
#    Updated: 2022/12/02 20:13:21 by thloyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                              #
#                                   VARIABLES                                  #
#                                                                              #
################################################################################

NAME = libft.a

INLCUDES = includes

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJDIR = objs

PATH_INT =	srcs/int
FILE_INT =	ft_intlen.c ft_itoa.c 
OBJ_INT = $(addprefix $(OBJDIR)/, $(FILE_INT:.c=.o))

PATH_IO =	srcs/io
FILE_IO =	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
OBJ_IO = $(addprefix $(OBJDIR)/, $(FILE_IO:.c=.o))

PATH_LIBC_CTYPE = srcs/libc/ctype
FILE_LIBC_CTYPE = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
									ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c	\
									ft_tolower.c ft_toupper.c
OBJ_LIBC_CTYPE = $(addprefix $(OBJDIR)/, $(FILE_LIBC_CTYPE:.c=.o))

PATH_LIBC_STDLIB = srcs/libc/stdlib
FILE_LIBC_STDLIB = ft_atoi.c ft_calloc.c
OBJ_LIBC_STDLIB = $(addprefix $(OBJDIR)/, $(FILE_LIBC_STDLIB:.c=.o))

PATH_LIBC_STRING = srcs/libc/string
FILE_LIBC_STRING =	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
										ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
										ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
										ft_strrchr.c
OBJ_LIBC_STRING = $(addprefix $(OBJDIR)/, $(FILE_LIBC_STRING:.c=.o))

PATH_LIBC_STRINGS =	srcs/libc/strings
FILE_LIBC_STRINGS =	ft_bzero.c
OBJ_LIBC_STRINGS = $(addprefix $(OBJDIR)/, $(FILE_LIBC_STRINGS:.c=.o))

PATH_LIST =	srcs/list
FILE_LIST =	ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
						ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJ_LIST = $(addprefix $(OBJDIR)/, $(FILE_LIST:.c=.o))

PATH_STRING =	srcs/string
FILE_STRING =	ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c \
							ft_strtrim.c ft_substr.c
OBJ_STRING = $(addprefix $(OBJDIR)/, $(FILE_STRING:.c=.o))

OBJS =	$(OBJ_INT) $(OBJ_IO) $(OBJ_LIBC_CTYPE) $(OBJ_LIBC_STDLIB) \
				$(OBJ_LIBC_STRING) $(OBJ_LIBC_STRINGS) $(OBJ_LIST) $(OBJ_STRING)

################################################################################
#                                                                              #
#                                   RULES                                      #
#                                                                              #
################################################################################

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(PATH_INT)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES}

$(OBJDIR)/%.o: $(PATH_IO)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES}

$(OBJDIR)/%.o: $(PATH_LIBC_CTYPE)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES}

$(OBJDIR)/%.o: $(PATH_LIBC_STDLIB)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES}

$(OBJDIR)/%.o: $(PATH_LIBC_STRING)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES}

$(OBJDIR)/%.o: $(PATH_LIBC_STRINGS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES}

$(OBJDIR)/%.o: $(PATH_LIST)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES}

$(OBJDIR)/%.o: $(PATH_STRING)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${INLCUDES}

clean:
	rm -f $(OBJS)
	rmdir $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

################################################################################
#                                                                              #
#                                   END                                        #
#                                                                              #
################################################################################