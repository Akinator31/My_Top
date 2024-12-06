/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** process_info
*/

#define _GNU_SOURCE
#include <dirent.h>
#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "fetch_data.h"
#include "utils.h"
#include "my_list.h"
#include "my.h"

static int get_field(char *buffer, char *element_to_find)
{
    int i = 0;

    for (i = 0; buffer[i] != '\0'; i++) {
        if ((buffer[i] == element_to_find[0])
        && (buffer[i + 1] == element_to_find[1])
        && (buffer[i + 2] == element_to_find[2])
        && (buffer[i + 3] == element_to_find[3]))
            break;
    }
    return i;
}

int fetch_process_stat(char *pid, int index_element)
{
    char *filepath = get_filepath("/proc/", pid, "/stat", 256);
    FILE *stat_file = fopen(filepath, "r");
    char *stat_element = NULL;
    char *buffer = NULL;
    int result = 0;
    int counter = 0;
    size_t len = 0;

    getline(&buffer, &len, stat_file);
    stat_element = strtok(buffer, " ");
    while (counter < index_element) {
        stat_element = strtok(NULL, " ");
        counter += 1;
    }
    free(filepath);
    fclose(stat_file);
    result = my_getnbr(stat_element);
    free(buffer);
    return result;
}

int fetch_user_process_owner_uid(char *pid)
{
    char *filepath = get_filepath("/proc/", pid, "/loginuid", 256);
    struct stat info;

    if (stat(filepath, &info) != -1) {
        my_free(1, filepath);
        return info.st_uid;
    }
    my_free(1, filepath);
    return 0;
}

char *fetch_user_process_owner(char *pid)
{
    FILE *passwd_file = fopen("/etc/passwd", "r");
    int i = 0;
    int user_uid = fetch_user_process_owner_uid(pid);
    int start_line_index = 0;
    char *buffer = NULL;
    size_t len = 0;
    char *user_name = malloc(sizeof(char) * 32);

    while (getline(&buffer, &len, passwd_file) != -1) {
        if (user_uid == my_getnbr(buffer))
            break;
    }
    my_memset(user_name, '\0', sizeof(char) * 32);
    copy_until(buffer, user_name, ':');
    fclose(passwd_file);
    free(buffer);
    return user_name;
}

linked_list_t *fetch_process_info(linked_list_t *data_list, char *pid)
{
    char *user_name = fetch_user_process_owner(pid);
    char *filepath = get_filepath("/proc/", pid, "/status", 256);
    char *buffer = open_and_read_file(filepath, 500);
    char *tkt = NULL;
    int process_stat_array[6] = {0};
    processus_t *process_stat = NULL;

    if (buffer == NULL) {
        my_free(3, buffer, user_name, filepath);
        return data_list;
    }
    process_stat_array[0] = my_getnbr(buffer + get_field(buffer, "Pid:"));
    process_stat_array[1] = fetch_process_stat(pid, 17);
    process_stat_array[2] = fetch_process_stat(pid, 18);
    process_stat_array[3] = fetch_process_stat(pid, 22) / 1024;
    process_stat_array[4] = my_getnbr(buffer + get_field(buffer, "VmRS"));
    process_stat_array[5] = my_getnbr(buffer + get_field(buffer, "RssF"));
    process_stat = create_process(user_name, process_stat_array, pid);
    my_free(3, buffer, user_name, filepath);
    return push_front_list(data_list, process_stat);
}

linked_list_t *fetch_global_process_info(void)
{
    DIR *current = opendir("/proc");
    struct dirent *dir_info = readdir(current);
    linked_list_t *process_data = new_list();
    FILE *passwd_file = fopen("/etc/passwd", "r");

    while (dir_info) {
        if (is_only_number(dir_info->d_name)) {
            process_data = fetch_process_info(process_data, dir_info->d_name);
        }
        dir_info = readdir(current);
    }
    closedir(current);
    my_rev_list(&process_data);
    return process_data;
}
