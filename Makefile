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
				src/fetch_data/kernel_stat/kernel_stat.c \
				src/fetch_data/mem_stat/total_memory.c \
				src/fetch_data/mem_stat/free_memory.c \
				src/fetch_data/mem_stat/used_memory.c \
				src/fetch_data/mem_stat/buffer_memory.c \
				src/fetch_data/mem_stat/cache_memory.c \
				src/fetch_data/mem_stat/shmem_memory.c \
				src/fetch_data/mem_stat/shmemhugepage_memory.c \
				src/fetch_data/mem_stat/sunreclaimed_memory.c \
				src/fetch_data/mem_stat/available_memory.c \
				src/fetch_data/swap_stat/total_swap_memory.c \
				src/fetch_data/swap_stat/free_swap_memory.c \
				src/fetch_data/swap_stat/used_swap_memory.c \
				src/fetch_data/swap_stat/available_swap_memory.c \

TOP_PART =	src/top_part/first_line.c \
			src/top_part/second_line.c \
			src/top_part/third_line.c \
			src/top_part/fourth_line.c \
			src/top_part/fifth_line.c \
			src/top_part/draw_top_part.c \

BOTTOM_PART =	src/bottom_part/process_listing.c \

UTILS =	src/utils/is_only_numbers.c \
		src/utils/fetch_process_status.c \
		src/utils/open_and_read_file.c \
		src/utils/free_double_array.c \
		src/utils/find_number.c \

LIB = 	lib/my_lib/my_getnbr.c \
		lib/my_lib/my_memcpy.c \
		lib/my_lib/my_memset.c \
		lib/my_lib/my_str_to_word_array.c \
		lib/my_lib/my_strcat.c \
		lib/my_lib/my_strcmp.c \
		lib/my_lib/my_strcpy.c \
		lib/my_lib/my_strdup.c \
		lib/my_lib/my_strlen.c \
		lib/my_lib/my_compute_power_rec.c \
		lib/my_lib/my_strlowcase.c \

LINKED_LIST = 	lib/my_list/add_data.c \
				lib/my_list/info_list.c \
				lib/my_list/remove_data.c \

OBJ = 	$(SRC:.c=.o) $(FETCH_DATA:.c=.o) $(TOP_PART:.c=.o) \
		$(UTILS:.c=.o) $(LIB:.c=.o) $(BOTTOM_PART:.c=.o)

NAME = my_top

all: $(NAME)

CFLAGS += -Iinclude -g3 -fsanitize=address
$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses -fsanitize=address -g3

clean:
	find . -type f -name "*.o" -delete
	rm -f *.o

fclean: clean

re: fclean all
