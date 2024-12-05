/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-mytop-pavel.de-wavrechin
** File description:
** my_top_tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_getnbr, test1)
{
    char *test = "salut 455";
    int result = my_getnbr(test);

    cr_assert_eq(result, 455);
}