#ifndef MONTY_H
#define MONTY_H
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef BUFSIZE
#define BUFSIZE 1024
#endif

/**
 * enum Date_Format_Modes - The data format modes for this program.
 * @DF_LIFO: The data format code for a LIFO structure (like a stack)
 * @DF_FIFO: The data format code for a FIFO structure (like a queue)
 */
enum Date_Format_Modes
{
	/* The data format code for a LIFO structure (like a stack) */
	DF_LIFO,
	/* The data format code for a FIFO structure (like a queue) */
	DF_FIFO
};

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: The integer stored at the node
 * @prev: A pointer to the previous element of the stack (or queue)
 * @next: A Pointer to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	/* The integer stored at the node */
	int n;
	/* A pointer to the previous element of the stack (or queue) */
	struct stack_s *prev;
	/* A Pointer to the next element of the stack (or queue) */
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Represents an opcode and its function
 * @opcode: The opcode name
 * @f: The function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	/* The opcode name */
	char *opcode;
	/* The function to handle the opcode */
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main_monty.c functions */

char *get_data_mode(void);
char **get_lines(void);
void clean_program(void);

/* Opcode handlers */

void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);
void opcode_add(stack_t **stack, unsigned int line_number);
void opcode_nop(stack_t **stack, unsigned int line_number);
void opcode_sub(stack_t **stack, unsigned int line_number);
void opcode_div(stack_t **stack, unsigned int line_number);
void opcode_mul(stack_t **stack, unsigned int line_number);
void opcode_mod(stack_t **stack, unsigned int line_number);
void opcode_pchar(stack_t **stack, unsigned int line_number);
void opcode_pstr(stack_t **stack, unsigned int line_number);
void opcode_rotl(stack_t **stack, unsigned int line_number);
void opcode_rotr(stack_t **stack, unsigned int line_number);
void opcode_stack(stack_t **stack, unsigned int line_number);
void opcode_queue(stack_t **stack, unsigned int line_number);

/* Reading helpers from the file - main_monty.c */

char **file_reader(char *path, int *lines_count);
char *read_command(char *str, int *offset);

/* Executor of each line - interpreter.c */

instruction_t *get_opcode_handlers(void);
void interpret(char *line, int line_num, stack_t **stack_values);

/* Stack helpers - stack_stuff.c*/

void push(stack_t **stack, int n);
int pop(stack_t **stack);
void enqueue(stack_t **stack, int n);
stack_t *get_top_element(stack_t **stack);
stack_t *get_bottom_element(stack_t **stack);

/* Memory helpers - memory_stuff.c*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int n, char c);

/* String utilities - string_stuff.c*/

int str_len(const char *str);
char *_strcat(char *left, char *right);
char **str_split(char *str, char c, int *len_out);

/* Data validators - validator_functions.c*/

char is_integer(char *str);
char is_ascii_char(int c);
char is_whitespace(char c);

#endif
