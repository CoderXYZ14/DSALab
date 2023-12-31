#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 50

// Hash function: k mod 47
int hashFunction(int key) {
    return key % 47;
}

// Linear probing function
int linearProbe(int index, int probeNumber) {
    return (index + probeNumber) % TABLE_SIZE;
}

// Function to insert a number into the hash table
void insert(int hashTable[], int number) {
    int hashIndex = hashFunction(number);
    int probes = 0;

    while (hashTable[hashIndex] != 0) {
        if (hashTable[hashIndex] == number) {
            printf("Number %d is already present in the hash table.\n", number);
            return;
        }
        probes++;
        hashIndex = linearProbe(hashIndex, probes);
    }

    hashTable[hashIndex] = number;
    printf("Inserted %d at index %d with %d probe(s)\n", number, hashIndex, probes);
}

// Function to delete a number from the hash table
void delete(int hashTable[], int number) {
    int hashIndex = hashFunction(number);
    int probes = 0;

    while (hashTable[hashIndex] != 0 && probes < TABLE_SIZE) {
        if (hashTable[hashIndex] == number) {
            hashTable[hashIndex] = 0;
            printf("Deleted %d from index %d\n", number, hashIndex);
            return;
        }
        probes++;
        hashIndex = linearProbe(hashIndex, probes);
    }

    printf("Number %d not present in the hash table.\n", number);
}

// Function to search for a number in the hash table
int search(int hashTable[], int number) {
    int hashIndex = hashFunction(number);
    int probes = 0;

    while (hashTable[hashIndex] != 0 && probes < TABLE_SIZE) {
        if (hashTable[hashIndex] == number) {
            return hashIndex;
        }
        probes++;
        hashIndex = linearProbe(hashIndex, probes);
    }

    return -1; // Number not found
}

// Function to display the hash table
void displayHashTable(int hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != 0) {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
    printf("\n");
}

int main() {
    int hashTable[TABLE_SIZE] = {0}; // Initialize hash table with 0

    time_t t;
    srand((unsigned) time(&t)); // Seed the random number generator with current time

    printf("Welcome to the Hash Table program!\n");

    int numInsertions;

    // Prompt the user to enter the number of initial insertions
    printf("Enter the number of initial insertions: ");
    scanf("%d", &numInsertions);

    // Perform initial insertions with random numbers
    for (int i = 0; i < numInsertions; i++) {
        int randomNum = rand() % 1000; // Generate a random number in the range 0-999
        insert(hashTable, randomNum);
    }

    printf("Initial insertions completed.\n");

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
                insert(hashTable, n1);
                break;

            case 2:
                printf("Enter the number to be deleted from the hash table: ");
                int n2;
                scanf("%d", &n2);
                delete(hashTable, n2);
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

