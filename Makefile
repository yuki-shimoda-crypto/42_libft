# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 12:25:55 by yshimoda          #+#    #+#              #
#    Updated: 2022/10/24 17:10:08 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-I include

M_SRCS			=	ft_isalpha.c		\
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
					ft_putnbr_fd.c

B_SRCS			=	ft_lstnew.c			\
					ft_lstadd_front.c	\
					ft_lstsize.c		\
					ft_lstlast.c		\
					ft_lstadd_back.c	\
					ft_lstdelone.c		\
					ft_lstclear.c		\
					ft_lstiter.c		\
					ft_lstmap.c	

EXTRA_SRCS		=	ft_atol.c			\
					ft_isspace.c		\
					ft_strndup.c			

PRINTF_SRCS		=	ft_printf/ft_printf.c	\
					ft_printf/ft_put_ptr.c	\
					ft_printf/ft_put_str.c
					
OBJDIR			=	objs
SRCS			=	$(M_SRCS) $(B_OBJS) $(EXTRA_SRCS) $(PRINTF_SRCS)
OBJS			=	$(SRCS:%.c=$(OBJDIR)/%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean:			
				@$(RM) -r $(OBJDIR) a.out

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

bonus:			all

test:			
			echo $@
			echo $(@D)
			echo $(@F)

test2:
			echo $<
			echo $(<D)
			echo $(<F)
.PHONY:			all clean fclean re bonus

# ifdef WITH_BONUS
# 	OBJS += $(B_OBJS)
# endif
# bonus:		
# 				make WITH_BONUS=1
