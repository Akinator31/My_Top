/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** lib
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;

    while (dest[i] != '\0')
        i++;
    for (int e = 0; (src[e] != '\0') && (e < nb); e++) {
        dest[i] = src[e];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
