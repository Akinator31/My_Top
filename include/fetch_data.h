/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** fetch_data
*/

#ifndef INCLUDED_FETCH_DATA_H
    #define INCLUDED_FETCH_DATA_H
    #include <sys/types.h>
    #include <ncurses.h>

typedef struct processus_s processus_t;

struct processus_s {
    pid_t pid;
    char user[32];
    short pr;
    short ni;
    int virt;
    int res;
    int shr;
    char status;
    double cpu_usage;
    double mem_usage;
    time_t time;
    char *command;
};

enum memory_element {
    AVAILABLE_MEMORY,
    BUFFER_MEMORY,
    CACHE_MEMORY,
    FREE_MEMORY,
    SHMEM_MEMORY,
    SHMEMHUGEPAGE,
    SUNRECLAIMED_MEMORY,
    TOTAL_MEMORY,
    USED_MEMORY,
    AVAILABLE_SWAP_MEMORY,
    FREE_SWAP_MEMORY,
    TOTAL_SWAP_MEMORY,
    USED_SWAP_MEMORY
};

enum process_status {
    RUNNING,
    SLEEPING,
    STOPPED,
    ZOMBIE,
    TOTAL
};

char *fetch_rtc_time(void);
void fetch_uptime(void);
int fetch_active_users(void);
void print_load_average(void);
int fetch_kernel_system_stat_user_mode(void);
int *get_global_process_status(void);
double *get_memory_stat(char *filepath);
int show_uptime_load_average(WINDOW *window);
int show_tasks_status(WINDOW *window);
int show_cpu_stat(WINDOW *window);
int show_mem_stat(WINDOW *window);

#endif
