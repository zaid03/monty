#include "monty.h"
/**
 * _push - pushes into stock int
 * @stock: lists linked for monty stock
 * @ligne_nombre: how man times opcode happens
 */
void _push(stock_t **stock, __attribute__ ((unused))unsigned int ligne_nombre)
{
	stock_t *top;
	(void)ligne_nombre;

	top = malloc(sizeof(stock_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stock;
	top->prev = NULL;
	if (*stock != NULL)
		(*stock)->prev = top;
	*stock = top;
}

/**
 * _pall - print functions
 * @stock: linked list stack pointer
 * @ligne_nombre: times opcode happens
 */
void _pall(stock_t **stock, __attribute__ ((unused))unsigned int ligne_nombre)
{
	stock_t *runner;

	runner = *stock;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _print - top of stack int
 * @stock: pointer to linked list stack
 * @ligne_nombre: times of lineopcode happens
 *
 */
void _print(stock_t **stock, unsigned int ligne_nombre)
{
	stock_t *runner;

	runner = *stok;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ligne_nombre);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - removes list element
 *@stock: first node pointer
 *@ligne_nombre: int
 *Return: void
 */
void _pop(stock_t **stok, unsigned int ligne_nombre)
{
	stock_t *nodo = *stock;

	if (stock == NULL || *stock == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stock\n", ligne_nombre);
		exit(EXIT_FAILURE);
	}
	*stock = nodo->next;
	if (*stock != NULL)
		(*stock)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - list freeing
 * @head: first node pointer
 *
 */
void free_dlistint(stack_t *head)
{
	stock_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
