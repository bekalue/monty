#include "monty.h"

/**
 * opcode_add - Adds the top two elements of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	char error = TRUE;
	stack_t *top0 = NULL, *top1 = NULL;
	int result = 0;

	if (stack != NULL && (*stack != NULL))
	{
		top0 = get_top_element(stack);
		top1 = top0->prev;
		if (top1 != NULL)
		{
			result = top0->n + top1->n;
			pop(stack);
			top0 = get_top_element(stack);
			top0->n = result;
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		clean_program();
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_nop - Does nothing
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * opcode_sub - Subtracts the top element of the stack from
 *			the second top element of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	char error = TRUE;
	stack_t *top0 = NULL, *top1 = NULL;
	int result = 0;

	if (stack != NULL && (*stack != NULL))
	{
		top0 = get_top_element(stack);
		top1 = top0->prev;
		if (top1 != NULL)
		{
			result = top1->n - top0->n;
			pop(stack);
			top0 = get_top_element(stack);
			top0->n = result;
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		clean_program();
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_div - Divides the second top element of the stack
 *			by the top element of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	char error = TRUE;
	stack_t *top0 = NULL, *top1 = NULL;
	int result = 0;

	if (stack != NULL && (*stack != NULL))
	{
		top0 = get_top_element(stack);
		top1 = top0->prev;
		if (top1 != NULL)
		{
			if (top0->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_number);
				clean_program();
				exit(EXIT_FAILURE);
			}
			result = top1->n / top0->n;
			pop(stack);
			top0 = get_top_element(stack);
			top0->n = result;
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		clean_program();
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_mul - Multiplies the second top element of the stack
 *			with the top element of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	char error = TRUE;
	stack_t *top0 = NULL, *top1 = NULL;
	int result = 0;

	if (stack != NULL && (*stack != NULL))
	{
		top0 = get_top_element(stack);
		top1 = top0->prev;
		if (top1 != NULL)
		{
			result = top0->n * top1->n;
			pop(stack);
			top0 = get_top_element(stack);
			top0->n = result;
			error = FALSE;
		}
	}
	if (error)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		clean_program();
		exit(EXIT_FAILURE);
	}
}
