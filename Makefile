# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 12:26:14 by tfalchi           #+#    #+#              #
#    Updated: 2024/09/04 12:26:14 by tfalchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRC = main.c \
	src/pwd/pwd.c \
	src/execute_command.c \
	src/initialize_data.c \
	src/export/export.c \
	src/export/export_utils.c \
	src/parsing.c \
	src/free_and_null.c 

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
	@rm -f supp/supp.supp
	@rmdir supp
	@rm -f *.gch
	@rm -f $(NAME)
	@echo "$(RED)[MINISHELL]:\t FCLEAN$(RESET)"

re: fclean all

hel: all
	valgrind --tool=helgrind --history-level=approx -s ./$(NAME)

val: all
	valgrind --leak-check=full --track-origins=yes -s --show-leak-kinds=all --suppressions=./supp/supp.supp ./$(NAME)
supp:
		mkdir -p supp
		touch supp/supp.supp
		echo "{" > supp/supp.supp
		echo "   IgnoreReadlineLeak" >> supp/supp.supp
		echo "   Memcheck:Leak" >> supp/supp.supp
		echo "   match-leak-kinds: reachable" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "   fun:add_history" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "}" >> supp/supp.supp
		echo "{" >> supp/supp.supp
		echo "   IgnoreReadlineLeak" >> supp/supp.supp
		echo "   Memcheck:Leak" >> supp/supp.supp
		echo "   match-leak-kinds: reachable" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "   fun:readline" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "}" >> supp/supp.supp
		echo "{" >> supp/supp.supp
		echo "   IgnoreReadlineLeak" >> supp/supp.supp
		echo "   Memcheck:Leak" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "   fun:readline" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "}" >> supp/supp.supp
		echo "{" >> supp/supp.supp
		echo "   Malloc_Leak_Below_Main" >> supp/supp.supp
		echo "   Memcheck:Leak" >> supp/supp.supp
		echo "   fun:malloc" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "   obj:/usr/bin/*" >> supp/supp.supp
		echo "}" >> supp/supp.supp
		echo "{" >> supp/supp.supp
		echo "   Calloc_Leak_Below_Main" >> supp/supp.supp
		echo "   Memcheck:Leak" >> supp/supp.supp
		echo "   fun:calloc" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "   obj:/usr/bin/*" >> supp/supp.supp
		echo "}" >> supp/supp.supp
		echo "{" >> supp/supp.supp
		echo "   Realloc_Leak_Below_Main" >> supp/supp.supp
		echo "   Memcheck:Leak" >> supp/supp.supp
		echo "   fun:realloc" >> supp/supp.supp
		echo "   ..." >> supp/supp.supp
		echo "   obj:/usr/bin/*" >> supp/supp.supp
		echo "}" >> supp/supp.supp
		echo "use file supp to suppress valgrind errors: valgrind --suppressions=supp/supp.supp ./minishell"

t: all
	 ./$(NAME)
#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m
