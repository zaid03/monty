#include "monty.h"

/**
 * _swap - swap top of stock and second top
 * @stock: monty stock lists' pointer
 * @ligne_nombre: times the opcodes happens
 */
void _swap(stock_t **stock, unsigned int ligne_nombre)
{
    stock_t *runner;
    int tmp;

    runner = *stock;
    if (runner == NULL || runner->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stock too short\n", ligne_nombre);
        exit(EXIT_FAILURE);
    }
    tmp = runner->n;
    runner->n = runner->next->n;
    runner->next->n = tmp;
}

/**
 * _add - adding top of stock and second top
 * @stock: monty stock lists' pointer
 * @ligne_nombre: times the opcodes happens
 */
void _add(stock_t **stock, unsigned int ligne_nombre)
{
    stock_t *tmp = *stock;
    int sum = 0, i = 0;

    if (tmp == NULL)
    {
        fprintf(stderr, "L%d: can't add, stock too short\n", ligne_nombre);
        exit(EXIT_FAILURE);
    }

    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }

    if (stock == NULL || (*stock)->next == NULL || i <= 1)
    {
        fprintf(stderr, "L%d: can't add, stock too short\n", ligne_nombre);
        exit(EXIT_FAILURE);
    }
    sum = (*stock)->next->n + (*stock)->n;
    _pop(stock, ligne_nombre);

    (*stock)->n = sum;
}

/**
 * _nop - nop top of stock and second top
 * @stock: monty stock lists' pointer
 * @ligne_nombre: times the opcodes happens
 */
void _zip(__attribute__ ((unused)) stock_t **stock, __attribute__ ((unused)) unsigned int ligne_nombre)
{
    ;
}

/**
 * _pchar - prints the ASCII table value of a number
 * @stock: pointer to the top of the stock
 * @ligne_nombre: times the opcodes happens
 */
void _pchar(stock_t **stock, unsigned int ligne_nombre)
{
    int val;

    if (stock == NULL || *stock == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stock empty\n", ligne_nombre);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stock);
        exit(EXIT_FAILURE);
    }

    val = (*stock)->n;
    if (val > 127 || val < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", ligne_nombre);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stock);
        exit(EXIT_FAILURE);
    }

    putchar(val);
    putchar('\n');
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        return (1);
    else
        return (0);
}
