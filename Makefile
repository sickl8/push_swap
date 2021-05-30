
CHECKER_SRC = checker.c \
get_next_line.c \
get_next_line_utils.c \
stack_tools_0.c \
stack_tools_1.c \
stack_tools_2.c \
stack_tools_3.c \
stack_tools_4.c \
stack_tools_6.c \
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
algo_0.c \
algo_1.c \
algo_2.c \
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

all: $(NAME)

$(NAME): $(CHECKER) $(PUSH_SWAP) $(GEN)

$(CHECKER):
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g

$(PUSH_SWAP):
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g

clean:
	rm -rf $(CHECKER).dSYM $(PUSH_SWAP).dSYM a.out a.out.dSYM *.dSYM

fclean: clean
	rm -rf $(CHECKER) $(PUSH_SWAP) $(GEN)

re: fclean all

san:
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g -fsanitize=address
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g -fsanitize=address

deb:
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g -DDEBUG
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g -DDEBUG

sdeb:
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g -fsanitize=address -DDEBUG
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g -fsanitize=address -DDEBUG

gen:
	gcc cc.c *tools*.c -o gen -lm -g

test0:
	./gen 5 0 > 1; cat 1; bash -c "./push_swap $$(cat 1)"

.PHONY: all $(NAME) clean fclean re deb san
