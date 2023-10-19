#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/
extern int push_arg;

/**
 * struct stock_s - doubly linked list representation of a stock (or queue)
 * @n: integer
 * @prev: points to the previous element of the stock (or queue)
 * @next: points to the next element of the stock (or queue)
 * Description: doubly linked list node structure
 * for stock, queues, LIFO, FIFO Holberton project
 */
typedef struct stock_s
{
    int n;
    struct stock_s *prev;
    struct stock_s *next;
} stock_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stock, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stock_t **stock, unsigned int ligne_nombre);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stock, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
    FILE *file;
    int push_arg;
    char *buffer;
} global_var;

extern global_var var_global;

void read_file(char *filename, stock_t **stock);
char *parse_line(char *line, stock_t **stock, unsigned int ligne_nombre);
typedef void (*instruct_func)(stock_t **stock, unsigned int ligne_nombre);
instruct_func get_op_func(char *str);

/*Fuxntions Monty*/
void _pall(stock_t **stock, unsigned int ligne_nombre);
void _push(stock_t **stock, unsigned int ligne_nombre);
void _pint(stock_t **stock, unsigned int ligne_nombre);
void _pop(stock_t **stock, unsigned int ligne_nombre);
void _swap(stock_t **stock, unsigned int ligne_nombre);
void _nop(stock_t **stock, unsigned int ligne_nombre);
void _rotl(stock_t **stock, unsigned int ligne_nombre);
void _rotr(stock_t **stock, unsigned int ligne_nombre);

/*Functions string ascci */
void _pchar(stock_t **stock, unsigned int ligne_nombre);
void _pstr(stock_t **stock, unsigned int ligne_nombre);

/*Functions math*/
void _sub(stock_t **stock, unsigned int ligne_nombre);
void _add(stock_t **stock, unsigned int ligne_nombre);
void _mul(stock_t **stock, unsigned int ligne_nombre);
void _div(stock_t **stock, unsigned int ligne_nombre);
void _mod(stock_t **stock, unsigned int ligne_nombre);

/*Utility functions*/
void free_dlistint(stock_t *head);
void dobfree(stock_t **stock);
void dobfree2(stock_t **stock);
int _isalpha(int c);
#endif
