CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = algo.c ft_atoi.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c\
ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
ft_lstsize_bonus.c ft_split.c ft_strlen.c main.c push_swap.c push_swap_utils.c chunk.c norm_handling.c\
helping.c push_swap_utils_2.c helper_push_swap.c

BONUS_SRC = checker_bonus.c get_next_line_utils.c get_next_line.c checker_bonus_utils.c ft_strncmp.c helper_push_swap.c\
algo.c ft_atoi.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c\
ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
ft_lstsize_bonus.c ft_split.c ft_strlen.c push_swap.c push_swap_utils.c chunk.c norm_handling.c\
helping.c push_swap_utils_2.c helper_push_swap.c

BONUS_NAME = checker

RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE_BOLD='\033[1;37m'
GREEN_BOLD='\033[1;32m'
RED_BOLD='\033[1;31m'
BG_GREEN='\033[48;5;22m'
BG_RED='\033[48;5;124m'
NC='\033[0m'

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) push_swap.h
	@echo $(GREEN_BOLD) "bonus executable created successfully ✅✅✅" $(NC)
	@$(CC) $(CFLAGS) $(OBJ) $(BONUS_OBJ) -o $(BONUS_NAME)

$(NAME): $(OBJ) push_swap.h
	@echo $(GREEN_BOLD) "executable created successfully ✅✅✅" $(NC)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo $(RED_BOLD) "Cleaning objects files 🧹🧹🧹" $(NC)
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@echo  $(WHITE_BOLD)"Cleaning the program 🧹🧹🧹" $(NC)
	@rm -f $(NAME)
	@rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ) $(BONUS_OBJ)