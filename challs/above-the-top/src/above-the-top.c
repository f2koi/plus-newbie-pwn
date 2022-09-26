#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STACK_SIZE 20

struct stack {
    int storage[MAX_STACK_SIZE];
    int top;
};

struct stack stack;

void init_stack() {
    memset(stack.storage, 0, MAX_STACK_SIZE);
    stack.top = 0;
}

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void print_menu() {
    puts("");
    puts("0. Push");
    puts("1. Pop");
    puts("2. Top");
    puts("3. Exit");
    puts(">> ");
}

int get_input() {
    int menu;
    fflush(stdin);
    scanf("%d", &menu);
    return menu;
}

/* Pushes an integer k onto the top of the stack */
void push(int k) {
    if (stack.top < MAX_STACK_SIZE) {
        stack.top++;
        stack.storage[stack.top - 1] = k;
    }
}

/* Removes the item at the top of the stack */
void pop() { stack.top--; }

/* Returns the element at the top of the stack */
int top() { return stack.storage[stack.top - 1]; }

void win() { system("/bin/sh"); }

int main() {
    int menu, input;

    setup();
    init_stack();

    while (1) {
        print_menu();
        menu = get_input();

        switch (menu) {
        case 0:
            puts("Enter a value to PUSH: ");
            input = get_input();
            push(input);
            break;
        case 1:
            pop();
            break;
        case 2:
            printf("Top of the stack: %d\n", top());
            break;
        case 3:
            puts("Bye");
            exit(0);
        default:
            continue;
        }
    }

    return 0;
}