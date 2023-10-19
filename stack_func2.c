#include "monty.h"
/**
 * _swap - swap the top and second top of pointer
 * @stack: monty stack's pointer
 * @line_number: times opcode happens
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == 0 || runner->next == 0)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * _add - add the top and second top of pointer
 * @stack: monty stack's pointer
 * @line_number: times opcode happens
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == 0)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == 0 || (*stack)->next == 0 || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * _nop - nop the top and second top of pointer
 * @stack: monty stack's pointer
 * @line_number: times opcode happens
 */

void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * _pchar - givesascii value for numbers
 * @stack: top of stack's pointer
 * @line_number: number of current line
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == 0 || *stack == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * _isalpha - sees weather an int is an alphabet or not
 * @char: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int char)
{
	if ((char >= 97 && char <= 122) || (char >= 65 && char <= 90))
		return (1);
	else
		return (0);
}
