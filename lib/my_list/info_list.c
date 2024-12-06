/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** info_list
*/

#include <stdlib.h>
#include <string.h>
#include "fetch_data.h"
#include "my_list.h"
#include "my.h"

linked_list_t *new_list(void)
{
    return NULL;
}

void clear_list(linked_list_t *list)
{
    linked_list_t *temp = list;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

void clear_process_list(linked_list_t *list)
{
    linked_list_t *temp = list;

    while (temp != NULL) {
        free(((processus_t *)(temp->data))->user);
        free(temp->data);
        temp = temp->next;
    }
    clear_list(list);
}

int is_in_list(linked_list_t *list, char *element)
{
    linked_list_t *temp = list;

    while (temp != NULL) {
        if (element == ((char *)(temp->data))) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *prev = NULL;
    linked_list_t *curr = *begin;
    linked_list_t *next = NULL;

    while (curr->next != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *begin = next;
    curr->next = prev;
}
