CC =cc
CFLAGS =-Wall -Wextra -Werror
SRC =env_path.c ft_split.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strtok.c main.c pipex_otuls.c
OBJ =$(SRC:.c=.o)
# SRC_BNS = bonus/trate_check_bonus.c bonus/checker_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c commands_rev_rotate.c commands_swap.c commands_push.c commands_rotate.c ft_isdigit.c ft_strchr.c stack_func.c stack_func2.c ft_atoi.c ft_split.c
# OBJ_B = $(SRC_BNS:.c=.o)
NAME =pipex
# BNS_NAME =checker
HEADER = pipex.h
# HEADERB = bonus/checker_bonus.h
RM =rm -f

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJ_B) $(HEADERB)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(BNS_NAME)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(BNS_NAME)

re: fclean all
.PHONY : clean all