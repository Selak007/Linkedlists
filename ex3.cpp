#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of a linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

// Function to merge two ascending linked lists into one ascending linked list
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            if (mergedHead == NULL) {
                mergedHead = tail = head1;
            } else {
                tail->next = head1;
                tail = tail->next;
            }
            head1 = head1->next;
        } else {
            if (mergedHead == NULL) {
                mergedHead = tail = head2;
            } else {
                tail->next = head2;
                tail = tail->next;
            }
            head2 = head2->next;
        }
    }

    if (head1 != NULL) {
        if (tail == NULL) {
            mergedHead = head1;
        } else {
            tail->next = head1;
        }
    } else {
        if (tail == NULL) {
            mergedHead = head2;
        } else {
            tail->next = head2;
        }
    }

    return mergedHead;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 5);

    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 6);

    printf("First list: ");
    display(head1);
    printf("Second list: ");
    display(head2);

    struct Node* mergedHead = mergeLists(head1, head2);
    printf("Merged list: ");
    display(mergedHead);

    // Freeing memory
    struct Node* temp;
    while (mergedHead != NULL) {
        temp = mergedHead;
        mergedHead = mergedHead->next;
        free(temp);
    }

    return 0;
}
