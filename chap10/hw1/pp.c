#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = *top;  
    *top = new_node;  
}

int pop(struct node **top) {
    if (*top == NULL) {
        return -1;  
    }

    struct node *temp = *top;
    int popped_data = temp->data;
    *top = temp->next;  
    free(temp); 

    return popped_data;
}

void print_stack(struct node *top) {
    if (top == NULL) {
        return;
    }
    struct node *current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL;
    char input[100];
    int number;

    while (1) {
        fgets(input, sizeof(input), stdin);

        if (isdigit(input[0])) {
            if (sscanf(input, "%d\n", &number) == 1) {
                push(&top, number);
            } else {
                printf("Invalid input!\n");
            }
        } else {
            print_stack(top);
        }
    }

    return 0;
}

