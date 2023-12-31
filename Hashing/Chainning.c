#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 50

struct Node {
    int value;
    struct Node* next;
};

// Hash function: k mod 47
int hashFunction(int key) {
    return key % 47;
}

void displayHashTable(struct Node* hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Index %d:", i);
            struct Node* current = hashTable[i];
            while (current != NULL) {
                printf(" %d", current->value);
                current = current->next;
            }
            printf("\n");
        }
    }
}

void insert(struct Node* hashTable[], int number) {
    int index = hashFunction(number);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = number;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        // No collision, first element at this index
        hashTable[index] = newNode;
    } else {
        // Collision, append to the end of the linked list
        struct Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Inserted %d at index %d\n", number, index);
}

void delete (struct Node* hashTable[], int number) {
    int index = hashFunction(number);

    struct Node* current = hashTable[index];
    struct Node* prev = NULL;

    while (current != NULL && current->value != number) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Number %d not present in the hash table.\n", number);
        return;
    }

    if (prev == NULL) {
        // Deleting the first node in the linked list
        hashTable[index] = current->next;
    } else {
        // Deleting a node that's not the first in the linked list
        prev->next = current->next;
    }

    free(current);
    printf("Deleted %d from index %d\n", number, index);
}

int search(struct Node* hashTable[], int number) {
    int index = hashFunction(number);

    struct Node* current = hashTable[index];
    while (current != NULL) {
        if (current->value == number) {
            return index;
        }
        current = current->next;
    }

    return -1; // Number not found
}

int main() {
    struct Node* hashTable[TABLE_SIZE] = {NULL}; // Initialize hash table with NULL

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Separate Chaining Hash Table program!\n");

    // Automatically perform 40 insertions with random numbers
    for (int i = 0; i < 40; i++) {
        int number = rand() % 1000; // Generate a random number in the range 0-999
        insert(hashTable, number);
    }

    displayHashTable(hashTable);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a number\n");
        printf("2. Delete a number\n");
        printf("3. Search for a number\n");
        printf("4. Display the hash table\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to be inserted in the hash table: ");
                int n1;
                scanf("%d", &n1);

                // Check if the number is already present before inserting
                int index = search(hashTable, n1);
                if (index != -1) {
                    printf("Number %d is already present in the hash table.\n", n1);
                } else {
                    insert(hashTable, n1);
                }
                displayHashTable(hashTable);
                break;
            case 2:
                printf("Enter the number to be deleted from the hash table: ");
                int n2;
                scanf("%d", &n2);
                delete (hashTable, n2);
                displayHashTable(hashTable);
                break;
            case 3:
                printf("Enter the number to be searched in the hash table: ");
                int n3;
                scanf("%d", &n3);
                int searchResult = search(hashTable, n3);
                if (searchResult != -1) {
                    printf("Number %d found at index %d\n", n3, searchResult);
                } else {
                    printf("Number %d not found in the hash table\n", n3);
                }
                break;
            case 4:
                displayHashTable(hashTable);
                break;
            case 0:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

