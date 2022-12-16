# 0x19. C - Stacks, Queues - LIFO, FIFO

![Betty style](https://img.shields.io/badge/betty-style%20guide-purple?style=round-square)
> This projects covers concepts of Stacks, Queues, LIFO, FIFO implementation based on monty bytecode interpreter

## Monty Interpreter
> This interpreter was built in the C language. It reads Monty bytecode files of any extension (preferably .m although it doesn't matter), and interprets the opcodes contained. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument. Instruction starting with `#` will be assumed as a comment. Sample bytecodes can be found [here](https://github.com/bekalue/monty/tree/main/bytecodes)

> The interpreter can be run as either a stack (LIFO) or queue (FIFO). Mode can be switched mid-script. The interpreter can handle a variety of Monty opcodes, including printing, mathematical operations, and more - all handled opcodes are listed below.

### Supported Opcodes in Bytecode File

| Name | Description |
|:--:|:--|
| push | Pushes an element to the stack. Usage: `push integer` |
| pall | Prints all the values on the stack, starting from the top of the stack |
| pint | Prints the value at the top of the stack, followed by a new line |
| pop | Removes the top element of the stack |
| swap | Swaps the top two elements of the stack |
| add | Adds the top two elements of the stack |
| nop | Does nothing |
| sub | Subtracts the top element of the stack from the second top element of the stack |
| div | Divides the second top element of the stack by the top element of the stack |
| mul | Multiplies the second top element of the stack with the top element of the stack |
| mod | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| pchar | Prints the char at the top of the stack, followed by a new line |
| pstr | Prints the string starting at the top of the stack, followed by a new line |
| rotl | Rotates the stack to the top |
| rotr | Rotates the stack to the bottom |
| stack | Sets the format of the data to a stack (LIFO). This is the default behavior of the program |
| queue| Sets the format of the data to a queue (FIFO) |
