#include <stdio.h> // Include the standard input/output library

// Define the maximum size of the queue
#define MAX_SIZE 5

int main() {
    // Initialize an array to represent the queue
    int queue[MAX_SIZE];
    
    // Initialize variables to keep track of the front and rear of the queue
    int front = 0, rear = 0;
    
    // Initialize a variable to keep track of the number of elements in the queue
    int count = 0;
    
    // Enqueue elements into the queue
    for (int i = 1; i <= MAX_SIZE; i++) {
        // Check if the queue is full
        if (count == MAX_SIZE) {
            printf("Queue is full. Cannot enqueue more elements.\n");
            break;
        }
        
        // Enqueue the element
        queue[rear] = i;
        
        // Increment the rear pointer and the count
        rear = (rear + 1) % MAX_SIZE; // Use modulo to handle circular queue
        count++;
        
        // Print the enqueued element
        printf("Enqueued element: %d\n", i);
    }
    
    // Dequeue elements from the queue
    printf("\nDequeued elements:\n");
    for (int i = 0; i < count; i++) {
        // Print the dequeued element
        printf("%d ", queue[front]);
        
        // Increment the front pointer and decrement the count
        front = (front + 1) % MAX_SIZE; // Use modulo to handle circular queue
        count--;
    }
    
    return 0; // Return 0 to indicate successful execution
}
