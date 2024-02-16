#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int max;    
    int num;    
    int front;  
    int rear;   
    int* que;   
} IntQueue;
int Initialize(IntQueue* q, int max)
{
    q->num = q->rear = 0;
    q->front = 1;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                             // 배열 생성에 실패
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- 큐에 데이터를 인큐 ---*/
int Enque(IntQueue* q, int x)
{
    if (q->num >= q->max)
        return -1;                              // 큐가 가득 참
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}
int Search2(const IntQueue* q, int x)
{
	int i;
    for (i = 0; i < q->num; i++) {
        if (q->que[(i + q->front) % q->max] == x)
            return i;       // 검색 성공
    }
    return -1;              // 검색 실패
}
void Print(const IntQueue* q)
{
	int i;
    for (i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}
void Terminate(IntQueue* q)
{
    if (q->que != NULL)
        free(q->que);                           // 배열을 해제
    q->max = q->num = q->front = q->rear = 0;
}
int main(void)
{
    IntQueue que;
    int nx;
	
	printf("Queue size : ");
    scanf("%d", &nx);
    
    if (Initialize(&que, nx) == -1) {
        printf("Initialization error!\n");
        return 1;
    }

    int i, x;
    
    printf("Enque\n");
    for (i = 0; i < nx; i++) {
        do {
            printf("data : ");
            scanf("%d", &x);
            
            if (Enque(&que, x) == -1) {
                puts("Queue is full. Retry.\n");
            } else {
                break;
            }
        } while (1);
    }
    Print(&que);
    int sv;
    printf("search value : ");
    scanf("%d",&sv);
    int res = Search2(&que,sv);
    printf("relative position : %d",res);
    Terminate(&que);
    return 0;
}

