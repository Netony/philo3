# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/08/25 16:51:54 by dajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS = 

SOURCES = parser/parser.c \
		  parser/parser_utils.c \
		  parser/parser_utils3.c \
		  parser/parser_utils2.c \
		  info.c \
		  stat/stat.c \
		  stat/stat_array.c \
		  stat/stat_fork.c \
		  stat/stat_lock.c \
		  time/time.c \
		  time/time_array.c \
		  time/time_lock.c \
		  time/timeval.c \
		  ft_timestamp.c \
		  ft_check.c \
		  monis_init.c \
		  monis_function.c \
		  utils.c \
		  thread_init.c \
		  philos_init.c \
		  philos_function.c


DIRS = stat time utils parser

SOURCES_MANDA = main.c
SOURCES_BONUS =

INCLUDES = philo.h parser.h time.h status.h
INCLUDES_MANDA =
INCLUDES_BONUS =

LIBFT = 
LIB = 

# **************************************************************************** #

LIB_DIR = 
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incs

SRCS := $(addprefix $(SRC_DIR)/, $(SOURCES))
SRCS_MANDA := $(addprefix $(SRC_DIR)/, $(SOURCES_MANDA))
SRCS_BONUS := $(addprefix $(SRC_DIR)/, $(SOURCES_BONUS))

OBJ_DIRS = $(addprefix $(OBJ_DIR)/, $(DIRS))

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
OBJS_MANDA = $(addprefix $(OBJ_DIR)/, $(SOURCES_MANDA:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SOURCES_BONUS:.c=.o))

INCS := $(addprefix $(INC_DIR)/, $(INCLUDES))
INCS_BONUS := $(addprefix $(INC_DIR)/, $(INCLUDES_BONUS))
INCS_MANDA := $(addprefix $(INC_DIR)/, $(INCLUDES_MANDA))

LIBFT := $(addprefix $(LIB_DIR)/, $(LIBFT))

ifdef WITH_BONUS
	OBJS_NEW = $(OBJS_BONUS) $(OBJS) 
	INCS_NEW = $(INCS_BONUS) $(INCS)
else
	OBJS_NEW = $(OBJS_MANDA) $(OBJS) 
	INCS_NEW = $(INCS_MANDA) $(INCS)
endif

# **************************************************************************** #

MAKE = make
CC = cc
AR = ar
RM = rm

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = crus
RMFLAGS = -rf

# Commands ******************************************************************* #

all : 
	$(RM) $(RMFLAGS) $(OBJS_BONUS)
	$(MAKE) $(NAME) 

bonus : 
	$(RM) $(RMFLAGS) $(OBJS_MANDA)
	$(MAKE) $(NAME) WITH_BONUS=1

clean :
	$(RM) $(RMFLAGS) objs

fclean : 
	$(RM) $(RMFLAGS) objs
	$(RM) -f $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re

# Dependency ***************************************************************** #

$(NAME) $(BONUS) : $(OBJS_NEW) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_NEW) -o $@ $(LIBFLAGS)

$(LIBFT): 
	$(MAKE) -j3 -C $(LIB_DIR) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS_NEW) | $(OBJ_DIR) $(OBJ_DIRS)
	$(CC) $(CFLAGS) $< -c -I $(INC_DIR) -o $@ 

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIRS):
	mkdir $@
