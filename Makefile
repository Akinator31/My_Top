##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = main.c

FETCH_DATA =	src/fetch_data/time/time_of_day.c \
				src/fetch_data/time/uptime.c \
				src/fetch_data/active_users.c \
				src/fetch_data/load_average.c \
				src/fetch_data/process/total_process.c \
				src/fetch_data/process/running_process.c \
				src/fetch_data/process/sleeping_process.c \
				src/fetch_data/process/stopped_process.c \
				src/fetch_data/process/zombie_process.c \

TOP_PART =	src/top_part/first_line.c \
			src/top_part/second_line.c \

UTILS =	src/utils/is_only_numbers.c \
		src/utils/fetch_process_status.c \

LINKED_LIST =	lib/my_list/add_data.c \
				lib/my_list/info_list.c \
				lib/my_list/remove_data.c \

LIB = lib/my_lib/libmy.a

OBJ = 	$(SRC:.c=.o) $(FETCH_DATA:.c=.o) $(TOP_PART:.c=.o) \
		$(UTILS:.c=.o) $(LINKED_LIST:.c=.o)

NAME = my_top

all: $(NAME)


CFLAGS += -Iinclude -g3 -fsanitize=address
$(NAME): $(OBJ)
	make -C lib/my_lib
	gcc -o $(NAME) $(OBJ) $(LIB) -lncurses -fsanitize=address -g3

clean:
	find . -type f -name "*.o" -delete
	rm -f *.o

fclean: clean

re: fclean all
