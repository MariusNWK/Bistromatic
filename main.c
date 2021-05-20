/*
** EPITECH PROJECT, 2020
** main
** File description:
** calcul
*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "bistromatic.h"
#include "my.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        write(2, ERROR_MSG, 6);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        write(2, ERROR_MSG, 6);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;
    char *result;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    result = eval_expr(av[1], av[2], expr, size);
    if (result == NULL)
        return (84);
    my_putstr(result);
    return (0);
}
