#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int max; //stack capacity
	int ptr; // stack pointer
	int *stk; // stack first pointer
}IntStack; 

int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL)
    {
        s->max = 0; // assignment fail;
        return -1;
    }
    else
        s->max = max;
    return 0;
}

int Push(IntStack *s, int x)
{
    if (s->ptr >= s->max) // full
        return -1;
    else
        s->stk[s->ptr++] = x;

    return 0;
}

int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0; // return True or False
}
int Size(const IntStack *s)
{
    return s->ptr;
}
int Pop(IntStack *s, int *x)
{
    if (s->ptr <= 0)
    	*x = -1 ;
	else
		*x = s->stk[--s->ptr]; // x print, then del
	return 0;
}


int Top(const IntStack *s)
{
    if (IsEmpty(s))
        return -1;
    else
        return s->stk[s->ptr - 1];
}

void Terminate(IntStack *s)
{
    if (s->stk != NULL)
        free(s->stk); // array delete
    s->max = s->ptr = 0;
}

int main(void)
{
    // ÃÊ±âÈ­
    int x;
    scanf("%d", &x); // looping limit
    int i = 0, num,y;

    IntStack stk;
    Initialize(&stk, 10000);

    char st[10]; // action

    while (x > 0)
    {
        scanf("%s", st);
        if (strcmp(st, "push") == 0)
        {
            scanf("%d", &num);
            Push(&stk, num);
        }
        else if (strcmp(st, "pop") == 0)
        {
            Pop(&stk, &y);
            printf("%d\n",y);	
        }
        else if (strcmp(st, "size") == 0)
        {
            printf("%d\n", Size(&stk));
        }
        else if (strcmp(st, "empty") == 0)
        {
            printf("%d\n", IsEmpty(&stk));
        }
        else if (strcmp(st, "top") == 0)
        {
            printf("%d\n", Top(&stk));
        }

        x--;
    }

    Terminate(&stk);

    return 0;
}

