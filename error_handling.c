/*
** EPITECH PROJECT, 2020
** error_handling
** File description:
** bistro
*/
#include <stddef.h>
#include "my.h"

char *error_parentheses(char *expr)
{
    int open_par = 0;
    int close_par = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(')
            open_par++;
        if (expr[i] == ')')
            close_par++;
    }
    if (open_par++ == close_par++)
        return ("tout va bien");
    else
        return (NULL);
}

char *error_unknown_digit(char *base, char *ops, char *expr)
{
    int match = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        for (int j = 0; base[j] != '\0'; j++)
            if (expr[i] == base[j])
                match++;
        for (int k = 0; ops[k] != '\0'; k++)
            if (expr[i] == ops[k])
                match++;
        if (match == 0)
            return (NULL);
        match = 0;
    }
    return ("tout va bien");
}

char *error_operator_in_the_base(char *base, char *ops)
{
    for (int i = 0; base[i] != '\0'; i++)
        for (int j = 0; ops[j] != '\0'; j++)
            if (base[i] == ops[j])
                return (NULL);
    return ("tout va bien");
}

char *error_two_identical_digits_or_ops(char *base, char *ops)
{
    int match = 0;

    for (int i = 0; base[i] != '\0'; i++)
        for (int j = 0; base[j] != '\0'; j++)
            if (base[i] == base[j])
                match++;
    if (match != my_strlen(base))
        return (NULL);
    match = 0;
    for (int i = 0; ops[i] != '\0'; i++)
        for (int j = 0; ops[j] != '\0'; j++)
            if (ops[i] == ops[j])
                match++;
    if (match != my_strlen(ops))
        return (NULL);
    return ("tout va bien");
}

char *error_handling(char *base, char *ops, char *expr)
{
    if (error_operator_in_the_base(base, ops) == NULL)
        return (NULL);
    if (error_two_identical_digits_or_ops(base, ops) == NULL)
        return (NULL);
    if (error_unknown_digit(base, ops, expr) == NULL)
        return (NULL);
    if (error_parentheses(expr) == NULL)
        return (NULL);
    if (error_no_operator(expr) == NULL)
        return (NULL);
    return (expr);
}
