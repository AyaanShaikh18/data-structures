/*
                                -----Stack------

    ****************************************
    A very basic stack implementation, the below stack codes stores only integer data
    The stack has limitation it can only store 10 elements i didnt used malloc now
    ****************************************
 */
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

typedef struct stack {
    int top;
    int stack_arr[STACK_SIZE];
} stack;

void push(stack *stack_ptr, int data) {
    // update top first
    if(stack_ptr->top > STACK_SIZE) {
        fprintf(stderr,"stack overflow\n");
        exit(8);
    }
    stack_ptr->stack_arr[stack_ptr->top] = data;
    stack_ptr->top += 1;
}
void pop(stack *stack_ptr) {
    stack_ptr->top -= 1;

}
void print_stack(stack *stack_ptr) {
    int len = stack_ptr->top;
    for(int i = 0; i < len; i++) {
        printf(" %d", stack_ptr->stack_arr[i]);
    }
    printf("\n");
}
void instantiate_stack(stack *stack_ptr){
    stack_ptr->top = 0;
}


int main() {






    stack odds;
    stack *odds_ptr = &odds;
    instantiate_stack(odds_ptr);
    push(odds_ptr, 3);
    push(odds_ptr, 5);
    print_stack(odds_ptr);
    pop(odds_ptr);
    print_stack(odds_ptr);






    return (0);
}












