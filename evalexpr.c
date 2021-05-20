/*
** EPITECH PROJECT, 2020
** main
** File description:
** evalexpr
*/
#include "bistromatic.h"
#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *eval_expr_parantheses(char *str)
{
    int p = 0;

    for (p = 0; str[p] != '\0'; p++) {
        if (str[p] == ')') {
            if (my_strlen(str) > 40)
                return (NULL);
            str = parentheses_searcher(str);
            p = 0;
        }
    }
    return (str);
}

char *eval_expr_dmm(char *str)
{
    int p = 0;

    for (p = 0; str[p] != '\0'; p++) {
        if (str[p] == '/') {
            str = s1_s2_divisor(str, '/');
            if (str == NULL)
                return (NULL);
            p = 0;
        }
        if (str[p] == '*') {
            str = s1_s2_multiplier(str, '*');
            p = 0;
        }
        if (str[p] == '%') {
            str = s1_s2_modulo(str, '%');
            if (str == NULL)
                return (NULL);
            p = 0;
        }
    }
    return (str);
}

char *eval_expr_addsoustr(char *str)
{
    int p = 0;

    for (p = 0; str[p] != '\0'; p++) {
        if (str[p] == '+') {
            str = s1_s2_addition(str, '+');
            p = 0;
        }
        if (str[p] == '-') {
            str = s1_s2_soustraction(str, '-');
            p = 0;
        }
    }
    return (str);
}

char *ops_finder(char *expr, char *ops)
{
    char expr_ops[] = "()+-*/%";

    for (int i = 0; expr[i] != '\0'; i++)
        for (int j = 0; ops[j] != '\0'; j++)
            if (expr[i] == ops[j])
                expr[i] = expr_ops[j];
    return (expr);
}

char *eval_expr(char *base, char *ops, char *expr, int size)
{
    int i = 0;

    expr = error_handling(base, ops, expr);
    if (expr == NULL) { write(2, SYNTAX_ERROR_MSG, 13);
        return (NULL);
    }
    expr = ops_finder(expr, ops);
    expr = result_between_parentheses2(expr);
    expr = eval_expr_parantheses(expr);
    if (expr == NULL) { write(2, SYNTAX_ERROR_MSG, 13);
        return (NULL);
    }
    expr = result_between_parentheses2(expr);
    expr = eval_expr_dmm(expr);
    if (expr == NULL) { write(2, ERROR_MSG, 6);
        return (NULL);
    }
    expr = result_between_parentheses2(expr);
    expr = eval_expr_addsoustr(expr);
    return (expr);
}
