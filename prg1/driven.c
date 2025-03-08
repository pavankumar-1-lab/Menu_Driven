#include <stdio.h> // Standard input-output library

#define MAX 100 // Maximum size of the array

// Function declarations
void insert(int[], int*, int, int), delete(int[], int*, int), display(int[], int);

int main() {
    int arr[MAX], size = 0, choice, element, pos;

    // Prompt user for initial array size
    printf("Enter the number of elements (max %d, min 0): ", MAX);
    scanf("%d", &size);

    if (size > MAX || size < 0) {
        printf("Invalid size!\n");
        return 1;
    }

    // If user chooses to input elements initially
    if (size > 0) {
        printf("Enter %d elements: ", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }

    while (1) {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Insert at:\n1. Beginning\n2. End\n3. Given Position\nChoose: ");
                scanf("%d", &pos);
                printf("Enter element: ");
                scanf("%d", &element);
                if (pos == 1) insert(arr, &size, 1, element);
                else if (pos == 2) insert(arr, &size, size + 1, element);
                else {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    insert(arr, &size, pos, element);
                }
                break;
            case 2: // Delete
                printf("Delete from:\n1. Beginning\n2. End\n3. Given Position\nChoose: ");
                scanf("%d", &pos);
                if (pos == 1) delete(arr, &size, 1);
                else if (pos == 2) delete(arr, &size, size);
                else {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    delete(arr, &size, pos);
                }
                break;
            case 3: // Display array
                display(arr, size);
                break;
            case 4: // Exit program
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to insert an element at a specific position
void insert(int arr[], int *size, int pos, int element) {
    if (*size >= MAX || pos < 1 || pos > *size + 1) {
        printf("Invalid position or array full!\n");
        return;
    }
    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    (*size)++;
    printf("Inserted successfully!\n");
}

// Function to delete an element from a specific position
void delete(int arr[], int *size, int pos) {
    if (*size == 0 || pos < 1 || pos > *size) {
        printf("Invalid position or array empty!\n");
        return;
    }
    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Deleted successfully!\n");
}

// Function to display array elements
void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}