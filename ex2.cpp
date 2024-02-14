#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertSorted(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        return newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        return head;
    }
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insertSorted(head, 3);
    head = insertSorted(head, 1);
    head = insertSorted(head, 5);
    head = insertSorted(head, 2);
    head = insertSorted(head, 4);
    display(head);
    
    // Freeing memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
