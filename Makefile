##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = $(shell find . -type f -name "*.c" ! -name "tests*")
SRC_TESTS = $(shell find . -type f -name "*.c" ! -name "main.c")
OBJ = 	$(SRC:%.c=build/%.o)
OBJS = $(SRC:%.c=build-debug/%.o)
OBJS_TESTS = $(SRC_TESTS:%.c=build-tests/%.o)
OBJS_TESTS := $(filter-out main.c, $(OBJS_TESTS))
DEBUG_FLAGS = -fsanitize=address -g3 -Iinclude -lncurses
TESTS_FLAGS = -Iinclude -lncurses -lcriterion
CFLAGS += -Iinclude -lncurses
NAME = my_top
DEBUG_NAME = debug
TEST_NAME = test_my_top

build/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

build-debug/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(DEBUG_FLAGS) -c $< -o $@

build-tests/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(TESTS_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

$(DEBUG_NAME): $(OBJS)
	gcc -o $(DEBUG_NAME) $(OBJS) $(DEBUG_FLAGS)

$(TEST_NAME): $(OBJS_TESTS)
	gcc -o $(TEST_NAME) $(OBJS_TESTS) $(TESTS_FLAGS)

clean:
	$(shell find . -type f -name "*.o" -delete)

fclean:
	rm -f $(NAME)
	rm -f $(DEBUG_NAME)
	rm -f $(TEST_NAME)
	rm -rf build-debug
	rm -rf build-tests
	rm -rf build

re: fclean all
