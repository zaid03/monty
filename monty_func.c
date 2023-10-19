#include "monty.h"
/**
 * read_file - bytecode reading and cmds running
 * @filename: file path
 * @stock: top of the stack pointer
 */
void read_file(char *filename, stock_t **stock)
{
	char *lignes;
	size_t i = 0;
	int count_ligne = 1;
	instruct_func s;
	int cheking;
	int reading;


	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((reading = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		lignes = parse_line(var_global.buffer, stack, count_ligne);
		if (lignes == NULL || lignes[0] == '#')
		{
			count_ligne++;
			continue;
		}
		s = get_op_func(lignes);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count_ligne, lignes);
			exit(EXIT_FAILURE);
		}
		s(stack, count_ligne);
		count_ligne++;
	}
	free(var_global.buffer);
	cheking = fclose(var_global.file);
	if (cheking == -1)
		exit(-1);
}

/**
 * get_op_function -  opcode cheking and returns the right function
 * @str: opcode
 * Return: returns a functions or NULL when fails
 */
instruct_func get_op_function(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * is_nombre - checks weathers strings are numbers
 * @str: string being passed
 * Return: returns 1 if string is a number else 0
 */
int is_nombre(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_line - parses a line for opcodes and arguments
 * @lina: the line to parse
 * @stack: head of the stack pointer
 * @ligne_nombre: the current line number
 * Return: returns opcode or null when fails
 */
char *parse_line(char *lina, stock_t **stock, unsigned int ligne_nombre)
{
	char *opcode, *push, *arg;
	(void)stack;

	push = "push";
	opcode = strtok(lina, "\n ");
	if (opcode == NULL)
		return (NULL);

	if (strcmp(opcode, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", ligne_nombre);
			exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}
