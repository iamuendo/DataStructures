/*
 Author - Muendo Isaac Maingi
 Admission no - BSE-01-0084/2025
*/

// 1. Import the standard input and output library
#include <stdio.h>

//2. 
void insert(int arr[], int n, int value) {
    arr[n] = value;
    printf("Book with ID %d added successfully.\n", value);
}

int delete_last(int arr[], int n) {
    if (n == 0) {
        printf("Library is empty. No books to delete.\n");
        return n;
    }
    printf("Book with ID %d removed successfully.\n", arr[n - 1]);
    return n - 1;
}

void traverse(int arr[], int n) {
    if (n == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Books in the library: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int max_size;

    // Get maximum size from user
    printf("Enter the maximum number of books in the library: ");
    scanf("%d", &max_size);

    // Declare array then let user input the size
    int books[max_size]; 
    int n = 0; // Current number of books

    while (1) {
        int choice, book_id;

        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Remove Last Book\n");
        printf("3. View Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n < max_size) { // Check if there's space
                    printf("Enter Book ID to add: ");
                    scanf("%d", &book_id);
                    insert(books, n, book_id);
                    n++; // Increment book count
                } else {
                    printf("Library is full. Cannot add more books.\n");
                }
                break;
            case 2:
                n = delete_last(books, n); // Update book count after deletion
                break;
            case 3:
                traverse(books, n);
                break;
            case 4:
                printf("Exiting Library System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

