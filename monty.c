#include "monty.h"
global_var var_global;
/**
 * main - monty's driver function
 * @ab: int number of argument
 * @ac: opcode
 * Return: 0
 */
int main(int ab, char **ac)
{
	stack_t *stack;

	stack = NULL;
	if (ab != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(ac[1], &stack);
    /* recordar liberar memorias */
	free_dlistint(stack);
	return (0);
}
