/*
 Author - Muendo Isaac Maingi
 Admission no - BSE-01-0024/2025
*/

#include <stdio.h>  // Includes the standard input/output library for functions
#include <stdlib.h> // Includes the standard library for general-purpose functions like malloc (memory allocation)

// Define the structure for a binary tree node
typedef struct Node { // Defines a structure named 'Node' to represent a node in the binary tree
    int data;  // initializes a variable to store the integer value of the node
    struct Node* left;  // this is a pointer to the left child node
    struct Node* right; // this is a pointer to the right child node
} Node; // 'Node' is the alias for this structure, making it easier to use

// Function to create a new node
Node* createNode(int data) { // Defines a function 'createNode' that takes an integer 'data' as input
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocates memory dynamically for a new 'Node' and casts the pointer to 'Node*'
    newNode->data = data; // Assigns the input 'data' to the 'data' field of the newly created node
    newNode->left = NULL; // Initializes the 'left' pointer of the new node to NULL (no left child)
    newNode->right = NULL; // Initializes the 'right' pointer of the new node to NULL (no right child)
    return newNode; // Returns the pointer to the newly created node
}

// Traversal functions
void inorder(Node* root) { // Defines the 'in order' traversal function, taking the root of the tree as input
    if (root) { // Checks if the current node ('root') is not NULL
        inorder(root->left); // Recursively calls 'in order' on the left child of the current node
        printf("%d ", root->data); // Prints the data of the current node followed by a space
        inorder(root->right); // Recursively calls 'in order' on the right child of the current node
    }
}

void preorder(Node* root) { // Defines the 'pre-order' traversal function, taking the root of the tree as input.
    if (root) {             // Checks if the current node ('root') is not NULL.
        printf("%d ", root->data); // Prints the data of the current node followed by a space.
        preorder(root->left); // Recursively calls 'pre-order' on the left child of the current node.
        preorder(root->right); // Recursively calls 'pre-order' on the right child of the current node.
    }
}

void postorder(Node* root) { // Defines the 'post order' traversal function, taking the root of the tree as input.
    if (root) {
        postorder(root->left); // Recursively calls 'post order' on the left child of the current node.
        postorder(root->right); // Recursively calls 'post order' on the right child of the current node.
        printf("%d ", root->data); // Prints the data of the current node followed by a space.
    }
}

int main() { // The main function where the program execution begins.
    // Create a simple binary tree manually
    Node* root = createNode(1); // Creates the root node with data 1.
    root->left = createNode(2); // Creates the left child of the root node with data 2.
    root->right = createNode(3); // Creates the right child of the root node with data 3.
    root->left->left = createNode(4); // Creates the left child of the left child (grandchild) with data 4.
    root->left->right = createNode(5); // Creates the right child of the left child (grandchild) with data 5.

    printf("In order traversal = "); // Prints a message indicating the start of the in-order traversal.
    inorder(root); // Calls the 'in order' function to traverse the tree in in-order.
    printf("\n");  // Prints a newline character to move the cursor to the next line.

    printf("Pre-order traversal = "); // Prints a message indicating the start of the pre-order traversal.
    preorder(root); // Calls the 'pre-order' function to traverse the tree in pre-order.
    printf("\n");   // Prints a newline character to move the cursor to the next line.

    printf("Post order traversal = "); // Prints a message indicating the start of the post-order traversal.
    postorder(root); // Calls the 'post order' function to traverse the tree in post-order.
    printf("\n");  // Prints a newline character to move the cursor to the next line.

    return 0; // Returns 0 to indicate successful program execution.
}
