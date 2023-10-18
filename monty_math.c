#include "monty.h"

/**
 * _subrine - subrine top stack and second top
 * @stock: monty stack's pointer to lists
 * @line_number: number of line opcode occurs on
 */
void _subrine(stock_t **stock, unsigned int ligne_nombre)
{
	stock_t *tmp = *stock;
	int subrine = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't subrine, stock too short\n", ligne_nombre);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stock == NULL || (*stock)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't subrine, stock too short\n", ligne_nombre);
		exit(EXIT_FAILURE);
	}
	subrine = (*stock)->next->n - (*stock)->n;
	_pop(stock, ligne_nombre);

	(*stock)->n = subrine;
}

/**
 * _mule - mule top stack and second top
 * @stock: monty stack's pointer to lists
 * @ligne_nombre: number of line opcode occurs on
 */
void _mule(stock_t **stock, unsigned int ligne_nombre)
{
	int aux;

	if (*stock == NULL || (*stock)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stock too short\n", ligne_nombre);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stock);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = (*stock)->n;
		_pop(stock, ligne_nombre);
		(*stock)->n *= aux;
	}
}

/**
 * _div - div top stack and second top
 * @stock: pointer to lists for monty stack
 * @ligne_nombre: number of line opcode occurs on
 */
void _div(stack_t **stock, unsigned int ligne_nombre)
{
	int div = 0;

	if (*stock == NULL || (*stock)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stock too short\n", ligne_nombre);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stock);
		exit(EXIT_FAILURE);
	}
	else if ((*stock)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ligne_nombre);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stock);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stock)->n;
		_pop(stock, ligne_nombre);
		(*stock)->n /= div;
	}
}

/**
 * _mod - mod top stack and second top
 * @stock: monty stack's pointer to lists
 * @ligne_nombre: number of line opcode occurs on
 */
void _mod(stack_t **stock, unsigned int ligne_nombre)
{
	int mod = 0;

	if (*stock == NULL || (*stock)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stock too short\n", ligne_nombre);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stock);
		exit(EXIT_FAILURE);
	}
	else if ((*stock)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ligne_nombre);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stock);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stock)->n;
		_pop(stock, ligne_nombre);
		(*stock)->n %= mod;
	}
}
