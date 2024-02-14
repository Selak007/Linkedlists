#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

class LinkedList {
private:
    struct Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the beginning of the list
    void Insert_Beg_Node(int value) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = head;
        head = new_node;
    }

    // Function to insert a node at the end of the list
    void Insert_End_Node(int value) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            return;
        }
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // Function to insert a node at a specified position
    void Insert_Pos_Node(int value, int pos) {
        if (pos == 0) {
            Insert_Beg_Node(value);
            return;
        }
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        struct Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    // Function to delete a node from the beginning of the list
    int Delete_Beg_Node() {
        if (head == NULL) {
            return 0; // Indicates failure
        }
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return 1; // Indicates success
    }

    // Function to delete the last node (pop operation)
    int Pop_Node() {
        if (head == NULL) {
            return 0; // Indicates failure
        }
        if (head->next == NULL) {
            free(head);
            head = NULL;
            return 1; // Indicates success
        }
        struct Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return 1; // Indicates success
    }

    // Function to delete a node at a specified position
    int Delete_Pos_Node(int pos) {
        if (head == NULL) {
            return 0; // Indicates failure
        }
        struct Node* temp = head;
        if (pos == 0) {
            head = head->next;
            free(temp);
            return 1; // Indicates success
        }
        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            return 0; // Indicates failure
        }
        struct Node* next_node = temp->next->next;
        free(temp->next);
        temp->next = next_node;
        return 1; // Indicates success
    }

    // Function to search for a node with a given value
    int SearchNode(int var) {
        int pos = 0;
        struct Node* temp = head;
        while (temp != NULL) {
            if (temp->data == var) {
                return pos; // Indicates found
            }
            pos++;
            temp = temp->next;
        }
        return -1; // Indicates not found
    }

    // Function to display the list
    void Display() {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    // Function to display the list in reverse
    void Displayrev() {
        recursiveDisplay(head);
        printf("\n");
    }

private:
    // Helper function for recursive display
    void recursiveDisplay(struct Node* p) {
        if (p != NULL) {
            recursiveDisplay(p->next);
            printf("%d ", p->data);
        }
    }
};

int main() {
    LinkedList NewList;
    int choice, pos, var;
    while (1) {
        printf("\n\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Specified Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Pop (Delete Last Node)");
        printf("\n6. Delete from Specified Position");
        printf("\n7. Search for Element");
        printf("\n8. Display the List");
        printf("\n9. Display the List in Reverse");
        printf("\n10. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &var);
                NewList.Insert_Beg_Node(var);
                printf("\nInserted Successfully");
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &var);
                NewList.Insert_End_Node(var);
                printf("\nInserted Successfully");
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &var);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                NewList.Insert_Pos_Node(var, pos);
                break;
            case 4:
                if (NewList.Delete_Beg_Node() == 1) {
                    printf("\nDeleted Successfully");
                } else {
                    printf("\nList is Empty :(");
                }
                break;
            case 5:
                if (NewList.Pop_Node() == 1) {
                    printf("\nPopped Successfully");
                } else {
                    printf("\nList is Empty :(");
                }
                break;
            case 6:
                printf("Position to Remove :  ");
                scanf("%d", &pos);
                if (NewList.Delete_Pos_Node(pos) == 1) {
                    printf("\nDeleted Successfully");
                } else {
                    printf("\nList is Empty or Position is Invalid :(");
                }
                break;
            case 7:
                printf("Element to search :  ");
                scanf("%d", &var);
                pos = NewList.SearchNode(var);
                if (pos != -1) {
                    printf("\nFound Element at index: %d", pos);
                } else {
                    printf("\nElement Not Found in List");
                }
                break;
            case 8:
                printf("Values in List: ");
                NewList.Display();
                break;
            case 9:
                printf("Values inList in Reverse: ");
                NewList.Displayrev();
                break;
            case 10:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
        printf("\n\n(Press ENTER key to continue)");
        getchar();
        getchar();
    }
}
