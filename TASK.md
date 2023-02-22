# 0x19. C - Stacks, Queues - LIFO, FIFO
> project done in 3 days.

![Betty style](https://img.shields.io/badge/betty-style%20guide-purple?style=round-square)

## Learning Objectives
> to be [explained](https://fs.blog/feynman-learning-technique/) after project
* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

## The monty program
   + Usage: monty file
      + where file is the path to the file containing Monty byte code
   + If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
   + If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
      + where <file> is the name of the file
   + If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
      + where is the line number where the instruction appears.
      + Line numbers always start at 1
   + The monty program runs the bytecodes line by line and stop if either:
      + it executed properly every line of the file
      + it finds an error in the file
      + an error occured
   + If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
   + You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
   + Your code will be compiled this way:
   `$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
   + Any output must be printed on stdout
   + Any error message must be printed on stderr
      + [Here is a link to a GitHub repository](https://github.com/sickill/stderred) that could help you making sure your errors are printed on stderr
## Tasks
