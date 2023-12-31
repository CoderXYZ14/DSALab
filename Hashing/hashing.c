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

int linearProbe(int index, int probeNumber) {
    return (index + probeNumber) % TABLE_SIZE;
}

int hash1(int key) {
    return key % 47;
}

int hash2(int key) {
    return 7 - (key % 7);
}

int doubleHash(int key, int i) {
    return (hash1(key) + i * hash2(key)) % TABLE_SIZE;
}

int quadraticProbe(int index, int probeNumber) {
    return (index + probeNumber * probeNumber) % TABLE_SIZE;
}

void displayHashTable(int hashTable[], int useChaining) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != 0) {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }

    if (useChaining) {
        printf("\nHash Table (Separate Chaining):\n");
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (hashTable[i] != 0) {
                printf("Index %d:", i);
                struct Node* current = ((struct Node*)hashTable[i]);
                while (current != NULL) {
                    printf(" %d", current->value);
                    current = current->next;
                }
                printf("\n");
            }
        }
    }
}

int insert(int hashTable[], int number, int useChaining) {
    int hashIndex = hashFunction(number);
    int probes = 0;

    if (useChaining) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = number;
        newNode->next = NULL;

        if (hashTable[hashIndex] == 0) {
            // No collision, first element at this index
            hashTable[hashIndex] = (int)newNode;
        } else {
            // Collision, append to the end of the linked list
            struct Node* current = ((struct Node*)hashTable[hashIndex]);
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    } else {
        while (hashTable[hashIndex] != 0) {
            if (hashTable[hashIndex] == number) {
                printf("Number %d is already present in the hash table.\n", number);
                return probes;
            }
            probes++;
            hashIndex = linearProbe(hashIndex, probes);
        }

        hashTable[hashIndex] = number;
    }

    printf("Inserted %d at index %d with %d probe(s)\n", number, hashIndex, probes);
    return probes;
}

int delete (int hashTable[], int number, int useChaining) {
    int hashIndex = hashFunction(number);
    int probes = 0;

    if (useChaining) {
        struct Node* current = ((struct Node*)hashTable[hashIndex]);
        struct Node* prev = NULL;

        while (current != NULL && current->value != number) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            printf("Number %d not present in the hash table.\n", number);
            return -1;
        }

        if (prev == NULL) {
            // Deleting the first node in the linked list
            hashTable[hashIndex] = (int)current->next;
        } else {
            // Deleting a node that's not the first in the linked list
            prev->next = current->next;
        }

        free(current);
    } else {
        while (hashTable[hashIndex] != 0 && probes < TABLE_SIZE) {
            if (hashTable[hashIndex] == number) {
                hashTable[hashIndex] = 0;
                printf("Deleted %d from index %d\n", number, hashIndex);
                return probes;
            }
            probes++;
            hashIndex = linearProbe(hashIndex, probes);
        }

        printf("Number %d not present in the hash table.\n", number);
        return -1;
    }

    printf("Deleted %d from index %d\n", number, hashIndex);
    return probes;
}

int search(int hashTable[], int number, int useChaining) {
    int hashIndex = hashFunction(number);
    int probes = 0;

    if (useChaining) {
        struct Node* current = ((struct Node*)hashTable[hashIndex]);

        while (current != NULL) {
            if (current->value == number) {
                return probes;
            }
            probes++;
            current = current->next;
        }
    } else {
        while (hashTable[hashIndex] != 0 && probes < TABLE_SIZE) {
            if (hashTable[hashIndex] == number) {
                return probes;
            }
            probes++;
            hashIndex = linearProbe(hashIndex, probes);
        }
    }

    return -1; // Number not found
}

int main() {
    int hashTable[TABLE_SIZE] = {0}; // Initialize hash table with 0
    int useChaining = 0;

    srand(time(NULL)); // Seed the random number generator with current time

    printf("Welcome to the Hash Table program!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Select Collision Resolution Technique\n");
        printf("2. Insert a number\n");
        printf("3. Delete a number\n");
        printf("4. Search for a number\n");
        printf("5. Display the hash table\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select Collision Resolution Technique:\n");
                printf("1. Linear Probing\n");
                printf("2. Separate Chaining\n");
                printf("Enter your choice: ");
                int collisionChoice;
                scanf("%d", &collisionChoice);
                useChaining = (collisionChoice == 2);
                printf("Collision resolution technique set to %s\n", useChaining ? "Separate Chaining" : "Linear Probing");
                break;

            case 2:
                printf("Enter the number to be inserted in the hash table: ");
                int n1;
                scanf("%d", &n1);
                int probes1 = insert(hashTable, n1, useChaining);
                printf("Insertion completed with %d probe(s).\n", probes1);
                break;

            case 3:
                printf("Enter the number to be deleted from the hash table: ");
                int n2;
                scanf("%d", &n2);
                int probes2 = delete(hashTable, n2, useChaining);
                if (probes2 != -1) {
                    printf("Deletion completed with %d probe(s).\n", probes2);
                }
                break;

            case 4:
                printf("Enter the number to be searched in the hash table: ");
                int n3;
                scanf("%d", &n3);
                int probes3 = search(hashTable, n3, useChaining);

                if (probes3 != -1) {
                    printf("Number %d found with %d probe(s)\n", n3, probes3);
                } else {
                    printf("Number %d not found in the hash table\n", n3);
                }
                break;

            case 5:
                displayHashTable(hashTable, useChaining);
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

