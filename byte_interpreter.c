#include "monty.h"
/**
 * get_opcode_handlers - Retrieves an array of supported instructions
 *
 * Return: An array of instructions supported by this program.
 */
instruction_t *get_opcode_handlers(void)
{
	static instruction_t handlers[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{"mul", opcode_mul},
		{"mod", opcode_mod},
		{"pchar", opcode_pchar},
		{"pstr", opcode_pstr},
		{"rotl", opcode_rotl},
		{"rotr", opcode_rotr},
		{"stack", opcode_stack},
		{"queue", opcode_queue},
		{NULL, NULL},
	};
	return (handlers);
}
/**
 * interpret - Executes a line of code.
 * @line: the line to execute.
 * @line_num: the line number of the line being executed.
 * @stack: a pointer to the stack values.
 */
void interpret(char *line, int line_num, stack_t **stack)
{
	instruction_t *opcode_handlers = get_opcode_handlers();
	int o = 0, i;
	char *opcode = read_command(line, &o);

	if (opcode)
	{
		if (opcode[0] != '#' && opcode[0] != '\0')
		{
			for (i = 0; opcode_handlers[i].opcode; i++)
			{
				if (strcmp(opcode, opcode_handlers[i].opcode) == 0)
				{
					free(opcode);
					opcode_handlers[i].f(stack, line_num);
					return;
				}
			}
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
			free(opcode);
			clean_program();
			exit(EXIT_FAILURE);
		}
		free(opcode);
	}
}
