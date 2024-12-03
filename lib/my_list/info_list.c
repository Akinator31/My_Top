/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** info_list
*/

#include <stdlib.h>
#include <string.h>
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

int is_in_list(linked_list_t *list, char *element)
{
    linked_list_t *temp = list;

    while (temp != NULL) {
        if (strcmp(element, ((char *)(temp->data))) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
