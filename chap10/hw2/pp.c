#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (*tail == NULL) {
        *head = *tail = new_node;  
    } else {
        (*tail)->next = new_node;  
        *tail = new_node;          
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        return -1; 
    }

    struct node *temp = *head;
    int deleted_data = temp->data;
    *head = (*head)->next;  

    if (*head == NULL) {
        *tail = NULL;
    }

    free(temp);  
    return deleted_data;
}

void print_queue(struct node *head) {
    if (head == NULL) {
        return;
    }
    struct node *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL, *tail = NULL;  
    char input[100];
    int number;

    while (1) {
        fgets(input, sizeof(input), stdin);

        if (isdigit(input[0])) {
            if (sscanf(input, "%d\n", &number) == 1) {
                addq(&head, &tail, number);
            } else {
                printf("Invalid input!\n");
            }
        } else {
            print_queue(head);
        }
    }

    return 0;
}

