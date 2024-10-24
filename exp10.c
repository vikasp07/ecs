#include <stdio.h>

#define MAX 10 // Maximum number of vertices

int queue[MAX], front = -1, rear = -1;
int graph[MAX][MAX], visited[MAX], totalVertices;

// Function to enqueue an element into the queue
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) // Set front to 0 if it's the first element
        front = 0;
    queue[++rear] = vertex; // Add the element to the rear of the queue
}

// Function to dequeue an element from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front++]; // Remove the element from the front of the queue
}

// BFS function to traverse the graph
void BFS(int startVertex) {
    int i;
    visited[startVertex] = 1; // Mark the start vertex as visited
    enqueue(startVertex);
    
    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (front <= rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Traverse all adjacent vertices
        for (i = 0; i < totalVertices; i++) {
            // If there's an edge and the vertex is not visited
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark the vertex as visited
                enqueue(i); // Enqueue the adjacent vertex
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, startVertex;

    printf("Enter the total number of vertices: ");
    scanf("%d", &totalVertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", totalVertices, totalVertices);
    for (i = 0; i < totalVertices; i++) {
        for (j = 0; j < totalVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize all vertices as unvisited
    for (i = 0; i < totalVertices; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting vertex (0-%d): ", totalVertices - 1); // Input the starting vertex
    scanf("%d", &startVertex);

    if (startVertex >= 0 && startVertex < totalVertices) {
        BFS(startVertex); // Perform BFS traversal
    } else {
        printf("Invalid starting vertex!\n");
    }

    return 0;
}














#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Max number of vertices in the graph

struct Stack { // Stack structure
    int top;
    int items[MAX];
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push element into the stack
void push(struct Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->items[++(stack->top)] = value; // Increment the top and add the value to the stack
    } else {
        printf("Stack overflow! Cannot push %d\n", value);
    }
}

// Pop element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[(stack->top)--];
    }
    return -1; // Return -1 if stack is empty
}

// DFS function using stack
void DFS(int graph[MAX][MAX], int start, int numVertices) {
    struct Stack stack;
    initStack(&stack);
    int visited[MAX] = {0}; // Visited array to mark visited nodes

    push(&stack, start);
    visited[start] = 1; // Mark the starting vertex as visited

    printf("DFS Traversal starting from vertex %d: ", start);
    while (!isEmpty(&stack)) {
        int currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        // Explore adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                push(&stack, i); // Push the adjacent vertex onto the stack
                visited[i] = 1; // Mark the vertex as visited
            }
        }
    }
    printf("\n");
}

int main() {
    int numVertices, startVertex;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    int graph[MAX][MAX];

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Validate starting vertex
    if (startVertex >= 0 && startVertex < numVertices) {
        DFS(graph, startVertex, numVertices);
    } else {
        printf("Invalid starting vertex!\n");
    }

    return 0;
}
