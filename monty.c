#include "monty.h"
global_var var_global;
/**
 * main - drives function for the program of monty
 * @zb: int num of arguments
 * @za: opcode file
 * Return: 0
 */
int main(int zb, char **za)
{
	stack_t *stack;

	stack = NULL;
	if (zb != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(za[1], &stack);
	free_dlistint(stack);
	return (0);
}
