/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** task02
*/

#ifndef MY_H
    #define MY_H
    #include <stdlib.h>

int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dest, char const *src);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
void *my_memcpy(void *dest, const void *src, size_t size);
void *my_memset(void *pointer, int value, size_t size);
int my_compute_power_rec(int nb, int p);
char *my_strlowcase(char *str);
char **my_str_to_separator_word_array(char const *str, char separator);
char *my_strncat(char *dest, char const *src, int nb);
void copy_until(char *src, char *dest, char to_find);

#endif
