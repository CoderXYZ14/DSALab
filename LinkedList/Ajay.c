#include <stdio.h>

void initialise_address_array (int* add[], int Max_size) {
    for (int i = 0; i<Max_size ; i++) {
        add[i] = NULL;
    }
    return;
}

int searching (int* add [], int node) {
    int i = 0;
    while (add[i] != NULL) {
        if ((*add [i]) == node) {
            return i;
        }
        i++;
    }
    return (-1);
}

void traversal (int* add[], int info[], int n) {
    int i = 0;
    printf ("\nLinked list:\n");
    while (add[i] != NULL) {
        printf ("%d", *add[i]);
        i++;
        if (add[i] != NULL) {
            printf (" --> ");
        }
    }
    printf ("\n\n");
    printf ("Original array:\n");
    for (int j = 0; j<n ; j++) {
        printf ("%d", info[j]);
        if (j < (n-1)) {
            printf (" --> ");
        }
    }
    printf ("\n\n");
}

void deletion (int* add []) {
    int node;
    printf ("Enter data point you want to delete:\n");
    scanf ("%d", &node);
    int index = searching (add, node);
    if (index == -1) {
        printf ("\n%d is not present in linked list.\n", node);
    }
    else {
        while (add[index+1] != NULL) {
            add [index] = add [index+1];
            index = index+1;
        }
        add [index] = NULL;
    }
    return;
}
void node_insertion (int info[], int* add[], int n, int* arr_last_element) {
    int i = 0;
    while (add[i] != NULL) {
        i++;
    }
    printf ("Enter %d data element:\n", n);
    for (int j = 0; j<n ; j++) {
        scanf ("%d", &info[j+(*arr_last_element)]);
    }
    if (i == 0) {
        for (int j = 0; j<n ; j++) {
            add[j] = &info[j];
        }
    }
    else {
        int choice, index;
        printf ("\nEnter 1 for insertion in beginning\n");
        printf ("Otherwise any number\n\n");
        scanf ("%d", &choice);
        if (choice == 1) {
            index = -1;
        }
        else {
            int node;
            printf ("Enter node after which you want to insert the data:");
            scanf ("%d", &node);
            index = searching (add, node);

            if (index == -1) {
                printf ("\n%d is not present in linked list.\n\n", node);

                return;
            }
        }

        int k;
        for (k = i-1 ; k>index ; k--) {
            add[k+n] = add[k];
        }
        for (k = 0 ; k < n ; k++) {
            add [k+index+1] = &info[(*arr_last_element)+k];
        }
    }
    (*arr_last_element) = (*arr_last_element) + n;
    return;
}


int main() {
    int p;
    int info [100];
    int* add[100];
    int arr_last_element = 0;
    initialise_address_array (add,100);
    while (1) {
        printf("enter 1 for insertion\n");
        printf("enter 2 for deletion\n");
        printf("enter 3 for searching\n");
        printf("enter 4 for traversal\n");
        printf("enter 0 for exit\n");
        printf ("\nEnter your choice:\n");
        scanf("%d",&p);
        if(p==1) {
            int n;
            printf ("Enter number of elements you want to insert:\n");
            scanf ("%d", &n);
            node_insertion (info, add, n, &arr_last_element);
        }
        else if (p==2) {
            if (add[0] == NULL) {
                printf ("\nLinked list is empty\n\n");
            }
            else {
                deletion (add);
            }

        }
        else if(p==3) {
            if (add[0] == NULL) {
                printf ("\nLinked list is empty\n\n");
            }
            else {
                int node;
                printf ("Enter data point you want to search:\n");
                scanf ("%d", &node);
                int index = searching (add, node);
                if (index == -1) {
                    printf ("Entered data point is not present in linked list.");
                }
                else {
                    printf ("%d is present in linked list at index : %d\n\n", node, index);
                }
            }
        }
        else if (p==4) {
            if (add[0] == NULL) {
                printf ("\nLinked list is empty\n\n");
            }
            else {
                traversal (add, info, arr_last_element);
            }
        }


        else if(p==0) {
            break;
        }
        else {
            printf("invalid input\n");
        }
    }
    return 0;
}
