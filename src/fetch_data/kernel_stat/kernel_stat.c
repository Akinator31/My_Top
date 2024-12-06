/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** user_mode
*/

#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "fetch_data.h"
#include "utils.h"
#include "my.h"

int compute_ticks_sum(char **ticks_value)
{
    int result = 0;

    for (int i = 1; i < 9; i++)
        result += my_getnbr(ticks_value[i]);
    return result;
}

float *compute_percentage(char **frame1, char **frame2,
    int ticks_sum, int ticks_sum2)
{
    float *result = malloc(sizeof(float) * 8);

    for (int i = 0; i < 8; i++) {
            result[i] = ((float)(my_getnbr(frame2[i + 1]) -
                my_getnbr(frame1[i + 1])) * 100) /
                (float)(ticks_sum2 - ticks_sum);
    }
    return result;
}

void print_percentage_user_mode(char *buffer, char *buffer2)
{
    char **frame1 = my_str_to_word_array(buffer);
    char **frame2 = my_str_to_word_array(buffer2);
    int ticks_sum = compute_ticks_sum(frame1);
    int ticks_sum2 = compute_ticks_sum(frame2);
    float *result = compute_percentage(frame1,
        frame2, ticks_sum, ticks_sum2);

    printw("%.1f us,  %.1f sy,  %.1f ni,  %.1f id,  %.1f wa,",
        result[0], result[2], result[1], result[3], result[4]);
    printw("  %.1f hi,  %.1f si,  %.1f st\n", 0.0,
        result[6], 0.0);
    free_double_array(frame1);
    free_double_array(frame2);
    free(result);
}

int fetch_kernel_system_stat_user_mode(void)
{
    FILE *stat_file = fopen("/proc/stat", "r");
    size_t len = 0;
    char *buffer = NULL;
    char *buffer2 = NULL;
    char *time = fetch_rtc_time();
    char *time2;

    getline(&buffer, &len, stat_file);
    sleep(1);
    time2 = fetch_rtc_time();
    fclose(stat_file);
    stat_file = fopen("/proc/stat", "r");
    getline(&buffer2, &len, stat_file);
    print_percentage_user_mode(buffer, buffer2);
    free(buffer);
    free(buffer2);
    free(time);
    free(time2);
    fclose(stat_file);
    return 0;
}
