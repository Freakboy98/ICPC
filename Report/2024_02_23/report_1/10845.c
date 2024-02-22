#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int front;
    int rear;
    int max;
    int num;
    int *que;
} IntQueue;

// Initialize
int Initialize(IntQueue *q, int max) {
    q->front = q->rear = q->num = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

// Enqueue
int push(IntQueue *q, int x) {
    if (q->num >= q->max)
        return -1;
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

// Dequeue
int pop(IntQueue *q, int *x) {
    if (q->num <= 0)
        *x = -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
    }
    return 0;
}

// Size
int size(const IntQueue *q) {
    return q->num;
}

// Empty
int empty(const IntQueue *q) {
    return q->num <= 0 ? 1 : 0;
}

// Front
int front(const IntQueue *q) {
    return q->num <= 0 ? -1 : q->que[q->front];
}

// Back
int back(const IntQueue *q) {
    return q->num <= 0 ? -1 : q->que[q->rear - 1];
}

// Terminate
void Terminate(IntQueue *q) {
    if (q->que != NULL)
        free(q->que);
    q->max = q->front = q->rear = q->num = 0;
}

int main(void) {
    int x, num;
    scanf("%d", &x);
    IntQueue q;
    Initialize(&q, 10000);
    char cmd[6]; // action

    while (x > 0) {
        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0) {
            scanf("%d", &num);
            push(&q, num);
        } else if (strcmp(cmd, "pop") == 0) {
            pop(&q, &num);
            printf("%d\n", num);
        } else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size(&q));
        } else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", empty(&q));
        } else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", front(&q));
        } else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", back(&q));
        }
        x--;
    }

    Terminate(&q);
    return 0;
}

