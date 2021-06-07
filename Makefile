
CHECKER_SRC = checker.c \
get_next_line.c \
get_next_line_utils.c \
stack_tools_0.c \
stack_tools_1.c \
stack_tools_2.c \
stack_tools_3.c \
stack_tools_4.c \
stack_tools_5.c \
stack_tools_6.c \
stack_tools_7.c \
stack_tools_8.c \
stack_tools_9.c \
stack_tools_10.c \
stack_tools_11.c \
stack_tools_12.c \
stack_tools_13.c \
tools_0.c \
tools_1.c \
tools_2.c \
tools_3.c \
tools_4.c 

PUSH_SWAP_SRC = push_swap.c \
stack_tools_0.c \
stack_tools_1.c \
stack_tools_2.c \
stack_tools_3.c \
stack_tools_4.c \
stack_tools_5.c \
stack_tools_6.c \
stack_tools_7.c \
stack_tools_8.c \
stack_tools_9.c \
stack_tools_10.c \
stack_tools_11.c \
stack_tools_12.c \
stack_tools_13.c \
tools_0.c \
tools_1.c \
tools_2.c \
tools_3.c \
tools_4.c 

NAME = name
CHECKER = checker
PUSH_SWAP = push_swap
GEN = gen
WWW = -Wall -Wextra -Werror
CC = ~/.brew/Cellar/llvm/12.0.0_1/bin/clang

all: $(NAME)

$(NAME): $(PUSH_SWAP) $(GEN)


$(PUSH_SWAP):
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g

clean:
	rm -rf $(CHECKER).dSYM $(PUSH_SWAP).dSYM a.out a.out.dSYM *.dSYM

fclean: clean
	rm -rf $(CHECKER) $(PUSH_SWAP) $(GEN)

re: fclean all

gen:
	gcc cc.c -o $(GEN) tools_0.c

$(CHECKER):
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g

bonus: $(CHECKER)

san:
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g -fsanitize=address
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g -fsanitize=address

.PHONY: all $(NAME) clean fclean re san
