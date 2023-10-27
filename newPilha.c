#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

/* function to create a stack of given capacity; initializes size as 0 */
Stack *createStack(unsigned capacity, Matriz *matrix)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    /* unused so far */
    stack->top = -1;
    stack->array = (Matriz **)malloc((stack->capacity) * sizeof(Matriz *));
    // stack->capacity = stack->capacity / 4;
    for (int i = 0; i < stack->capacity; i++)
    {
        stack->array[i] = iniciarMatrix(matrix, stack->array[i]);
    }

    return stack;
}

/* Stack is full when top is equal to the last index */
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

/* Stack is empty when top is equal to -1 */
int isEmpty_dfs(Stack *stack)
{
    return stack->top == -1;
}

/* Function to add an item to stack.  It increases top by 1 */
void push_dfs(Stack *stack, Matriz *matrix)
{
    /* cannot add if it is full */

    /*if (isFull(stack))
    {
        for (int i = stack->capacity; i < stack->capacity * 2; i++)
        {
            stack->array[i] = iniciarMatrix(matrix, stack->array[i]);
        }
        stack->capacity = stack->capacity * 2;
    }*/

    int i = ++stack->top;
    matrix = copyMatrix(matrix, stack->array[i]);

    return;
}

/* Function to remove an item from stack.  It decreases top by 1 */
Matriz *pop_dfs(Stack *stack, Matriz *matrix)
{

    /* nothing to return if it is empty */
    if (isEmpty_dfs(stack))
        return NULL;
    int i = stack->top--;
    matrix = copyMatrix(stack->array[i], matrix);

    return matrix;
}

/* Function to return the top from stack without removing it */
/*Item peek(Stack *stack)
{
    if (isEmpty_dfs(stack))
        return NULL;

    return stack->array[stack->top];
}*/

/* function to delete all elements form stack */
void deleteStack(Stack *stack)
{
    /* note it does not delete the elements, just the stack itself */
    for (int i = 0; i < stack->capacity; i++)
    {
        freeMatriz(stack->array[i]);
    }
    free(stack->array);
    free(stack);

    return;
}