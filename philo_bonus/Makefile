NAME = philo_bonus
SOURCES = main.c data_common.c process_create.c
INCLUDES = 

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
INCS = $(addprefix $(INC_DIR)/, $(INCLUDES))

SRC_DIR = .
INC_DIR = .
OBJ_DIR = objs

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INC_DIR)
LIBFLAGS = -lpthread

all : $(NAME)

fclean : 
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)

re :
	make fclean
	make all

$(NAME) : $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) : 
	mkdir $@
