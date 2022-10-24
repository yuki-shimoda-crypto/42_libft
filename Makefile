# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 12:25:55 by yshimoda          #+#    #+#              #
#    Updated: 2022/10/24 12:32:08 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

OUTDIR			=	objs
SRCS			=	ft_isalpha.c		\
					ft_isdigit.c		\
					ft_isalnum.c		\
					ft_isascii.c		\
					ft_isprint.c		\
					ft_strlen.c			\
					ft_memset.c			\
					ft_bzero.c			\
					ft_memcpy.c			\
					ft_memmove.c		\
					ft_strlcpy.c		\
					ft_strlcat.c		\
					ft_toupper.c		\
					ft_tolower.c		\
					ft_strchr.c			\
					ft_strrchr.c		\
					ft_strncmp.c		\
					ft_memchr.c			\
					ft_memcmp.c			\
					ft_strnstr.c		\
					ft_atoi.c			\
					ft_calloc.c			\
					ft_strdup.c			\
					ft_substr.c			\
					ft_strjoin.c		\
					ft_strtrim.c		\
					ft_split.c			\
					ft_itoa.c			\
					ft_strmapi.c		\
					ft_striteri.c		\
					ft_putchar_fd.c		\
					ft_putstr_fd.c		\
					ft_putendl_fd.c		\
					ft_putnbr_fd.c		\
					ft_atol.c			\
					ft_strndup.c			
B_SRCS			=	ft_lstnew.c			\
					ft_lstadd_front.c	\
					ft_lstsize.c		\
					ft_lstlast.c		\
					ft_lstadd_back.c	\
					ft_lstdelone.c		\
					ft_lstclear.c		\
					ft_lstiter.c		\
					ft_lstmap.c	

PRINTF_DIR		=	printf
PRINTF			=	$(PRINTF_DIR)/libftprintf.a
					
OBJS			= $(SRCS:%.c=$(OUTDIR)/%.o)
B_OBJS			= $(B_SRCS:%.c=$(OUTDIR)/.o)

ifdef WITH_BONUS
	OBJS += $(B_OBJS)
endif

all:			$(NAME)

$(NAME):		$(OBJS) (PRINTF)
				ar rcs $(NAME) $(OBJS)

clean:			
				$(RM) $(OBJS) $(B_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:		
				make WITH_BONUS=1

.PHONY:			all clean fclean re bonus
