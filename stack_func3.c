#include "monty.h"

/**
 * _pstr - mod top of stock and second top
 * @stock: monty stock lists' pointer
 * @ligne_nombre: times the opcodes happens
 */
void _pstr(stock_t **stock, unsigned int ligne_nombre)
{
    stock_t *tmp = *stock;
    int c = 0;

    (void)ligne_nombre;

    while (tmp)
    {
        c = tmp->n;
        if (c == 0 || _isalpha(c) == 0)
            break;
        putchar(c);
        tmp = tmp->next;
    }
    putchar('\n');
}

/**
 * _rotl - mod top of stock and second top
 * @stock: monty stock lists' pointer
 * @ligne_nombre: times the opcodes happens
 */
void _rotl(stock_t **stock, unsigned int ligne_nombre)
{
    stock_t *runner = *stock;
    int aux1 = 0;

    if (!ligne_nombre || !stock || !*stock || !(*stock)->next)
        return;

    aux1 = runner->n;

    while (runner->next)
    {
        runner = runner->next;
        runner->prev->n = runner->n;
    }

    runner->n = aux1;
}

/**
 * _rotr - mod top of stock and second top
 * @stock: monty stock lists' pointer
 * @ligne_nombre: times the opcodes happens
 */
void _rotr(stock_t **stock, unsigned int ligne_nombre)
{
    stock_t *runner = *stock;
    int aux1 = 0;

    if (!ligne_nombre || !stock || !*stock || !(*stock)->next)
        return;

    while (runner->next)
        runner = runner->next;

    aux1 = runner->n;

    while (runner->prev)
    {
        runner = runner->prev;
        runner->next->n = runner->n;
    }

    runner->n = aux1;
}

