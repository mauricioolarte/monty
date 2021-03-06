#ifndef __MONTY__
#define __MONTY__
/* macros */


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *push_to_stack(stack_t **head, const int n);
size_t print_stack(const stack_t *h);
int is_integer(char *str);
size_t print_pint(const stack_t *h, int line_number);
void free_stack(stack_t *head);
stack_t *delete_dnodeint_at_index(stack_t **head, unsigned int index,
				  int line_number);
void add_stack(stack_t **head, int line_number);
stack_t *swap_stack(stack_t **head, int line_number);
void sub_stack(stack_t **head, int line_number);
void div_stack(stack_t **head, int line_number);
void mul_stack(stack_t **head, int line_number);
void mod_stack(stack_t **head, int line_number);
int is_coment(char *s);
int pchar_stack(stack_t **head, int line_number);
int pstr_stack(stack_t **head);

#endif
