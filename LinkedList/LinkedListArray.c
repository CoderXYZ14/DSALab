#include <stdio.h>
#include <stdlib.h>

void traversal(int data[], int next[], int start) {
    int p = start;
    while (p != -1) {
        printf("%d ", data[p]);
        p = next[p];
    }
    printf("\n");
}

int insertAtFirst(int data[], int next[], int head, int newData, int freeIndex) {
    data[freeIndex] = newData;
    next[freeIndex] = head;
    return freeIndex;
}

int insertAtIndex(int data[], int next[], int head, int newData, int index, int freeIndex) {
    if (index == 0) {
        return insertAtFirst(data, next, head, newData, freeIndex);
    }
    
    int p = head;
    for (int i = 0; i < index - 1 && p != -1; i++) {
        p = next[p];
    }
    
    if (p == -1) {
        return head;
    }
    
    data[freeIndex] = newData;
    next[freeIndex] = next[p];
    next[p] = freeIndex;
    return head;
}

int insertAtEnd(int data[], int next[], int head, int newData, int freeIndex) {
    int p = head;
    while (next[p] != -1) {
        p = next[p];
    }
    
    next[p] = freeIndex;
    data[freeIndex] = newData;
    next[freeIndex] = -1;
    return head;
}

int deleteFirst(int data[], int next[], int head) {
    if (head == -1) {
        return -1;
    }
    
    int newHead = next[head];
    return newHead;
}

int deleteAtIndex(int data[], int next[], int head, int index) {
    if (index == 0) {
        return deleteFirst(data, next, head);
    }
    
    int p = head;
    for (int i = 0; i < index - 1 && p != -1; i++) {
        p = next[p];
    }
    
    if (p == -1 || next[p] == -1) {
        return head;
    }
    
    int q = next[p];
    next[p] = next[q];
    return head;
}

int deleteLast(int data[], int next[], int head) {
    if (head == -1) {
        return -1;
    }
    
    if (next[head] == -1) {
        return -1;
    }
    
    int p = head;
    while (next[next[p]] != -1) {
        p = next[p];
    }
    
    next[p] = -1;
    return head;
}

void search(int data[], int next[], int start, int num) {
    int ptr = start;
    int c = 0;
    int t = 0;
    while (ptr != -1) {
        if (data[ptr] == num) {
            printf("Element found at %d position\n", c);
            t++;
            break;
        } else {
            ptr = next[ptr];
            c++;
        }
    }
    if (t == 0) {
        printf("Element not found\n");
    }
}

int main() {
    printf("Enter the number of elements to be in the Linked List: ");
    int n;
    scanf("%d", &n);
    
    int data[n];
    int next[n];
    
    printf("\nEnter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        next[i] = (i == n - 1) ? -1 : i + 1;
    }
    
    int head = 0;
    int freeIndex = n;
    
    printf("\nLinked List traversal:\n");
    traversal(data, next, head);
    
    int choice;
    do {
        printf("Enter <1> for insertion\nEnter <2> for deletion\nEnter <3> for searching\nEnter <0> to exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("Enter <1> for insertion at the beginning\nEnter <2> for insertion at a given index\nEnter <3> for insertion at the end\n");
                int insertChoice;
                scanf("%d", &insertChoice);
                
                switch (insertChoice) {
                    case 1: {
                        printf("Enter the data to be inserted: ");
                        int newData;
                        scanf("%d", &newData);
                        head = insertAtFirst(data, next, head, newData, freeIndex);
                        freeIndex++;
                        printf("Linked List after insertion: ");
                        traversal(data, next, head);
                        break;
                    }
                    case 2: {
                        printf("Enter the data to be inserted: ");
                        int newData;
                        scanf("%d", &newData);
                        printf("Enter the position data is to be inserted: ");
                        int pos;
                        scanf("%d", &pos);
                        head = insertAtIndex(data, next, head, newData, pos, freeIndex);
                        freeIndex++;
                        printf("Linked List after insertion: ");
                        traversal(data, next, head);
                        break;
                    }
                    case 3: {
                        printf("Enter the data to be inserted: ");
                        int newData;
                        scanf("%d", &newData);
                        head = insertAtEnd(data, next, head, newData, freeIndex);
                        freeIndex++;
                        printf("Linked List after insertion: ");
                        traversal(data, next, head);
                        break;
                    }
                }
                break;
            }
            case 2: {
                printf("Enter <1> for deletion at the beginning\nEnter <2> for deletion at a given index\nEnter <3> for deletion at the end\n");
                int deleteChoice;
                scanf("%d", &deleteChoice);
                
                switch (deleteChoice) {
                    case 1: {
                        head = deleteFirst(data, next, head);
                        printf("Linked List after deletion: ");
                        traversal(data, next, head);
                        break;
                    }
                    case 2: {
                        printf("Enter the position to be deleted: ");
                        int pos;
                        scanf("%d", &pos);
                        head = deleteAtIndex(data, next, head, pos);
                        printf("Linked List after deletion: ");
                        traversal(data, next, head);
                        break;
                    }
                    case 3: {
                        head = deleteLast(data, next, head);
                        printf("Linked List after deletion: ");
                        traversal(data, next, head);
                        break;
                    }
                }
                break;
            }
            case 3: {
                printf("Enter the number to be searched: ");
                int num;
                scanf("%d", &num);
                search(data, next, head, num);
                break;
            }
            case 0: {
                printf("EXIT\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}


