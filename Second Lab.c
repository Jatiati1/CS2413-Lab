/*Implement Stack using Queues*/

#define MAX_SIZE 100

// Simple queue structure
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Initialize queue
void queueInit(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

// Check if queue is empty
bool queueEmpty(Queue *q) {
    return (q->size == 0);
}

// Enqueue (push to back)
void enqueue(Queue *q, int val) {
    if (q->size < MAX_SIZE) {
        q->data[q->rear] = val;
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->size++;
    }
}

// Dequeue (pop from front)
int dequeue(Queue *q) {
    if (!queueEmpty(q)) {
        int val = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
        return val;
    }
    return -1; // Indicate an error if needed
}

// Get front of queue
int queueFront(Queue *q) {
    if (!queueEmpty(q)) {
        return q->data[q->front];
    }
    return -1; // Indicate an error if needed
}

// Stack structure using one queue
typedef struct {
    Queue q;
} MyStack;

// Create and initialize stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    queueInit(&stack->q);
    return stack;
}

// Push element onto stack
void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q, x);
    // Rotate the queue so the new element is at the front
    for (int i = 0; i < obj->q.size - 1; i++) {
        enqueue(&obj->q, dequeue(&obj->q));
    }
}

// Removes the element on top of the stack and returns it
int myStackPop(MyStack* obj) {
    return dequeue(&obj->q);
}

// Get the top element
int myStackTop(MyStack* obj) {
    return queueFront(&obj->q);
}

// Returns true if the stack is empty, false otherwise
bool myStackEmpty(MyStack* obj) {
    return queueEmpty(&obj->q);
}

// Free the stack
void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */


/*Implement Queue using Stacks*/

#define MAX_SIZE 100

// Simple stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void stackInit(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
bool stackEmpty(Stack *s) {
    return (s->top == -1);
}

// Push element to stack
void stackPush(Stack *s, int val) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++s->top] = val;
    }
}

// Pop element from stack
int stackPop(Stack *s) {
    if (!stackEmpty(s)) {
        return s->data[s->top--];
    }
    return -1; // Indicate an error if needed
}

// Peek top element of stack
int stackPeek(Stack *s) {
    if (!stackEmpty(s)) {
        return s->data[s->top];
    }
    return -1; // Indicate an error if needed
}

// Queue structure using two stacks
typedef struct {
    Stack inStack;
    Stack outStack;
} MyQueue;

// Create and initialize queue
MyQueue* myQueueCreate() {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    stackInit(&q->inStack);
    stackInit(&q->outStack);
    return q;
}

// Push element to queue
void myQueuePush(MyQueue* obj, int x) {
    stackPush(&obj->inStack, x);
}

// Pop element from queue
int myQueuePop(MyQueue* obj) {
    if (stackEmpty(&obj->outStack)) {
        while (!stackEmpty(&obj->inStack)) {
            stackPush(&obj->outStack, stackPop(&obj->inStack));
        }
    }
    return stackPop(&obj->outStack);
}

// Get the front element
int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(&obj->outStack)) {
        while (!stackEmpty(&obj->inStack)) {
            stackPush(&obj->outStack, stackPop(&obj->inStack));
        }
    }
    return stackPeek(&obj->outStack);
}

// Returns true if the queue is empty, false otherwise
bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&obj->inStack) && stackEmpty(&obj->outStack);
}

// Free the queue
void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */


