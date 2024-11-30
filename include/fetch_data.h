/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** fetch_data
*/

#ifndef INCLUDED_FETCH_DATA_H
    #define INCLUDED_FETCH_DATA_H

char *fetch_rtc_time(void);
void fetch_uptime(void);
int fetch_active_users(void);
void print_load_average(void);
int fetch_total_process(void);
int fetch_running_process(void);
int fetch_sleeping_process(void);
int fetch_stopped_process(void);
int fetch_zombie_process(void);
int fetch_kernel_system_stat_user_mode(void);
double fetch_total_memory(void);
double fetch_free_memory(void);
double fetch_used_memory(void);
double fetch_buffer_memory(void);
double fetch_cache_memory(void);
double fetch_shmem_memory(void);
double fetch_shmemhugepage_memory(void);
double fetch_sunreclaimed_memory(void);
double fetch_available_memory(void);
double fetch_total_swap_memory(void);
double fetch_free_swap_memory(void);
double fetch_used_swap_memory(void);
double fetch_available_swap_memory(void);

#endif
