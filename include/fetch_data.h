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

#endif
