##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = $(shell find . -type f -name "*.c")
OBJ = 	$(SRC:%.c=build/%.o)
OBJS = $(SRC:%.c=build-debug/%.o)
DEBUG_FLAGS = -fsanitize=address -g3 -Iinclude -lncurses
CFLAGS += -Iinclude -lncurses
NAME = my_top
DEBUG_NAME = debug

build/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

build-debug/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(DEBUG_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

$(DEBUG_NAME): $(OBJS)
	gcc -o $(DEBUG_NAME) $(OBJS) $(DEBUG_FLAGS)

clean:
	$(shell find . -type f -name "*.o" -delete)

fclean:
	rm -f $(NAME)
	rm -f $(DEBUG_NAME)
	rm -rf build-debug
	rm -rf build

re: fclean all
