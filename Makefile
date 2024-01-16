CC =cc
CFLAGS =-Wall -Wextra -Werror
SRC =env_path.c ft_split.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strtok.c main.c pipex_otuls.c
OBJ =$(SRC:.c=.o)
SRC_BNS = ft_split.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strncmp.c pipex_otuls.c env_path.c ft_strtok.c bonus/main_bonus.c bonus/pipex_otuls_bonus.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c
OBJ_B = $(SRC_BNS:.c=.o)
NAME =pipex
NAME_BNS =pipex_bonus
HEADER = pipex.h
HEADERB = bonus/pipex_bonus.h
RM =rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJ_B) $(HEADERB)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_BNS)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(NAME_BNS)

re: fclean all
.PHONY : clean all