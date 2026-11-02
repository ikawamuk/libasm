# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/25 01:41:15 by ikawamuk          #+#    #+#              #
#    Updated: 2026/11/01 13:12:34 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
ASM			=	nasm
ASMFLAGS	=	-f elf64
AR			=	ar
ARFLAGS		=	rcs
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -I$(INCDIR) \
				-g -O0 -fsanitize=address,undefined
INCDIR		=	include
SRCDIR		=	src
SRCS		=	ft_atoi_base_bonus.s \
				ft_calloc.s \
				ft_list_push_front_bonus.s \
				ft_list_remove_if_bonus.s \
				ft_list_size_bonus.s \
				ft_list_sort_bonus.s \
				ft_read.s \
				ft_simd_memchr_bonus.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_strdup.s \
				ft_strlen.s \
				ft_write.s

OBJDIR		=	obj
OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.s=.o))

TEST_NAME	=	test_libasm
TEST_SRCDIR	=	test
TEST_SRCS	=	main.c \
				ft_atoi_base_bonus_test.c \
				ft_calloc_test.c \
				ft_list_push_front_bonus_test.c \
				ft_list_remove_if_bonus_test.c \
				ft_list_size_bonus_test.c \
				ft_list_sort_bonus_test.c \
				ft_read_test.c \
				ft_simd_memchr_bonus_test.c \
				ft_strcmp_test.c \
				ft_strcpy_test.c \
				ft_strdup_test.c \
				ft_strlen_test.c \
				ft_write_test.c \
				util/random_string.c \
				util/list_util.c 

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir -p $(OBJDIR)
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re: fclean
	$(MAKE) all

test: re
	$(CC) $(CCFLAGS) $(addprefix $(TEST_SRCDIR)/, $(TEST_SRCS)) -L. -lasm -o $(TEST_NAME)
	./$(TEST_NAME)
	@echo "\e[32mPASS\e[0m"

.PHONY: all clean fclean re bonus test
