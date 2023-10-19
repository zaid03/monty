#include "monty.h"

/**
 * _sub - sub stack's top and second top
 * @stack: monty lists pointer
 * @line_number: times that line opcode happens
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub = 0, i = 0;

	if (tmp == 0)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == 0 || (*stack)->next == 0 || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sub;
}

/**
 * _mul - mul stack's top and second top
 * @stack: monty lists pointer
 * @line_number: times that line opcode happens
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (*stack == 0 || (*stack)->next == 0)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= aux;
	}
}

/**
 * _div - div stack's top and second top
 * @stack: monty lists pointer
 * @line_number: times that line opcode happens
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div = 0;

	if (*stack == 0 || (*stack)->next == 0)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
		
	}
	else
	{
		div = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n /= div;
	}
}

/**
 * _mod - mod stack's top and second top
 * @stack: monty lists pointer
 * @line_number: times that line opcode happens
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack == 0 || (*stack)->next == 0)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		fclose(var_global.file);
		free(var_global.buffer);
		exit(EXIT_FAILURE);
		free_dlistint(*stack);
	}
	else
	{
		mod = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n %= mod;
	}
}
