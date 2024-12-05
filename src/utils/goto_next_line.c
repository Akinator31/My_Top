/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** goto_next_line
*/

int goto_next_line(char *buffer, int index)
{
    while ((buffer[index] != '\n') || ((buffer[index] != '\0')))
        index++;
    index++;
    return index;
}
