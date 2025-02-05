/*
 Author - Muendo Isaac Maingi
 Admission no - BSE-01-0084/2025
*/

#include <stdio.h>  // Include a standard input and output library
#include <string.h> // Include string library for string operations

// Function to insert a book into the library
void insert(char names[][50], int ids[], int n, char name[], int id) {
    strcpy(names[n], name); // Copy the book name into the names array
    ids[n] = id; // Store the book ID in the ids array
    printf("Book '%s' with ID %d added successfully.\n", name, id); // Confirmation message
}

// Function to checkout a book based on its ID
int checkout_one_book(char names[][50], int ids[], int n, int id) {
    for (int i = 0; i < n; i++) { // Loop through all books
        if (ids[i] == id) { // Check if the current ID matches the one to delete
            printf("Book '%s' with ID %d removed successfully.\n", names[i], id); // Confirmation message

            // Shift remaining elements to fill the gap after deletion
            for (int j = i; j < n - 1; j++) {
                //Shift the any available books after checking one out
                ids[j] = ids[j + 1];
                strcpy(names[j], names[j + 1]);
            }
            return n - 1; // Return updated count of books after deletion
        }
    }
    printf("Book with ID %d not found.\n", id); // Inform user if ID is not found
    return n; // Return current count of books if no deletion occurred
}

// Function to display all books in the library
void traverse(char names[][50], int ids[], int n) {
    if (n == 0) { // Check if there are no books in the library
        printf("No books in the library.\n");
        return;
    }
    printf("Books in the library:\n");
    for (int i = 0; i < n; i++) { // Loop through all books
        printf("ID: %d, Name: %s\n", ids[i], names[i]); // Print each book's ID and name
    }
}

// Main function where execution starts
int main() {
    int max_size;

    // Get maximum size from user for the number of books in the library
    printf("Enter the maximum number of books in the library: ");
    scanf("%d", &max_size);

    // Declare arrays to hold book names and their corresponding IDs
    char books[max_size][50];
    int ids[max_size];
    int n = 0; // Current number of books

    while (1) { // Infinite loop for menu interaction
        int choice;
        char book_name[50]; // Variable to store a book's name temporarily
        int book_id; // Variable to store a book's ID temporarily

        // Display menu options to user
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Remove Book by ID\n");
        printf("3. View Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user's choice

        switch (choice) {
            case 1: // Add a new book
                if (n < max_size) { // Check if there's space in the library
                    printf("Enter Book Name: ");
                    scanf("%s", book_name); // Get book name from user

                    printf("Enter Book ID: ");
                    scanf("%d", &book_id); // Get book ID from user

                    insert(books, ids, n, book_name, book_id); // Call insert function to add a new book
                    n++; // Increment current count of books after adding a new one
                } else {
                    printf("Library is full. Cannot add more books.\n"); // Inform user if library is full
                }
                break;
            case 2: // Remove a book by its ID
                printf("Enter Book ID to remove: ");
                scanf("%d", &book_id); // Get the ID of the book to remove

                n = checkout_one_book(books, ids, n, book_id); // Call checkout book by id function and update count of books

                break;
            case 3: // View all books in the library
                traverse(books, ids, n); // Call traverse function to display all books

                break;
            case 4: // Exit the program
                printf("Exiting Library System. Goodbye!\n");
                return 0; // Exit program successfully

            default:
                printf("Invalid choice. Please try again.\n"); // Handle invalid input from user
        }
    }
}
