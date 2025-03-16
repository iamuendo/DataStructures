/*
 Author - Muendo Isaac Maingi
 Admission no - BSE-01-0024/2025
*/

// Add the standard input and output library
#include <stdio.h>

// Define a function named bsearch to perform binary search
int bsearch(int ages[], int value, int size) {
    // Initialize the low variable to the first index of the array (0)
    int low = 0;
    // Initialize the high variable to the last index of the array (size - 1)
    int high = size - 1;

    // Start a while loop that continues as long as low is less than or equal to high
    while (low <= high) {
        // Calculate the middle index (mid) using the formula low + (high - low) / 2
        int mid = low + (high - low) / 2;

        // Check if the value at the mid index is equal to the target value
        if (ages[mid] == value) {
            // If the value is found, return the mid index
            return mid; // Value found, return index
        }

        // If the value at the mid index is less than the target value
        if (ages[mid] < value) {
            // Move the low pointer to the right of mid (mid + 1) to search the right half
            low = mid + 1;
        }

        // If the value at the mid index is greater than the target value (else condition)
        else {
            // Move the high pointer to the left of mid (mid - 1) to search the left half
            high = mid - 1;
        }
    }

    // If the loop ends without finding the value, return -1 to indicate not found
    return -1; // Value not found
}

// Define the main function where program execution begins
int main() {
    // Declare an array of integers named ages with initial values
    int ages[] = {18, 21, 25, 30, 35, 40, 45};
    // Calculate the size of the ages array by dividing its total size by the size of one element
    int size = sizeof(ages) / sizeof(ages[0]);

    // Display the array to the user
    printf("Array: ");
    // Start a for loop to iterate over each element in the ages array
    for (int i = 0; i < size; i++) {
        // Print each element of the array followed by a space
        printf("%d ", ages[i]);
    }
    // Print a newline character to move to the next line
    printf("\n");

    // Declare an integer variable named value to store user input
    int value;
    // Prompt the user to enter the value they want to search for
    printf("Enter the value you want to search for: ");
    // Read the user's input and store it in the value variable
    scanf("%d", &value);

    // Call the bsearch function with the ages array, user's value, and array size
    int result = bsearch(ages, value, size);

    // Check if the result is not equal to -1 (value found)
    if (result != -1) {
        // Print a message indicating the value was found along with its index
        printf("Value %d found at index %d\n", value, result);
    } else {
        // Print a message indicating the value was not found
        printf("Value %d not found in the array\n", value);
    }

    // Return 0 to indicate successful program execution
    return 0;
}

