#include "monty.h"
/**
 * _push - stack reveives an int
 * @stack: stack's monty linked list
 * @line_number: times opcode happens
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = 0;
	if (*stack != 0)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * _pall - to print function
 * @stack: linked list stack's pointer
 * @line_number: times opcode happens
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != 0)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - prints integer into the top pointer
 * @stack: linked list pointer
 * @line_number: times opcode happens
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - removes element from lists
 *@stack: first node's pointer
 *@line_number: int
 *Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == 0 || *stack == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != 0)
		(*stack)->prev = 0;
	free(nodo);
}

/**
 * free_dlistint - fereeing lists
 * @head: first node's pointer
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != 0)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
