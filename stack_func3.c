#include "monty.h"

/**
 * _pstr - mod top and second top of stack
 * @stack: monty stack's pointer into lists
 * @line_number: times that opcode happens
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int char = 0;

	(void)line_number;


	while (tmp)
	{
		c = tmp->n;
		if (char == 0 || _isalpha(char) == 0)
			break;
		putchar(char);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - mod top and second top of stack
 * @stack: monty stack's pointer into lists
 * @line_number: times that opcode happens
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;


	int au1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	au1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = au1;
}

/**
 * _rotr - mod top and second top of stack
 * @stack: monty stack's pointer into lists
 * @line_number: times that opcode happens
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int au1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	au1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = au1;
}
