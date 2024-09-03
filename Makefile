NAME		= minishell

SRC = main.c \
	src/pwd/pwd.c \
	src/execute_command.c \
	src/initialize_data.c \
	src/export/export.c \
	src/export/export_utils.c \
	src/parsing.c \

INCLUDES = ./includes

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libftprintf.a

#FLAGS		= -Wall -Werror -Wextra -I includes -pthread -fsanitize=thread -g
FLAGS		=  -Wall -Werror -Wextra -I includes -pthread -g 
#FLAGS		=  -Wall -Werror -Wextra

OBJS		= $(SRC:%.c=%.o)

# -s : for valgrind
$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	@cc $(OBJS) $(FLAGS) $(LIBFT) -I $(INCLUDES) -o $(NAME) -lreadline -s 
	@echo "$(GREEN)[MINISHELL]:\t PROJECT COMPILED$(RESET)"

all:$(NAME)

%.o: %.c
	@cc -c $< -o $@ $(FLAGS) -I $(INCLUDES)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -fr $(OBJS)
	@echo "$(RED)[MINISHELL]:\t CLEAN$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f *.a
	@rm -f *.out
	@rm -f *.gch
	@rm -f $(NAME)
	@echo "$(RED)[MINISHELL]:\t FCLEAN$(RESET)"

re: fclean all

hel: all
	valgrind --tool=helgrind --history-level=approx -s ./$(NAME)

val: all
	 valgrind --leak-check=full --track-origins=yes -s --show-leak-kinds=all ./$(NAME)

t: all
	 ./$(NAME)
#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m
