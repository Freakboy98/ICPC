#include <stdio.h>
#include "Intstack.h"

int Initialize(IntStack *s,int max)
{
	s->ptr=0;
	if((s->stk = calloc(max,sizeof(int)))==NULL)
	{
		s->max =0; // assignment fail;
		return -1;	
	}	
	s->max = max;
	return 0;
}
int Push(IntStack *s,int x)
{
	if(s->ptr >= s->max) // full
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}
int Pop(IntStack *s, int *x)
{
	if(s->ptr <=0 ) // hollow
		return -1;
	*x = s->stk[--s->ptr]; // x print, then del
	return 0;
}
int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0; // return True or False
}
int Peek(const IntStack *s,int *x)
{
	if(s->ptr <= 0) // hollow
		return -1;
	*x = s->stk[s->ptr-1]; // ptr = 0, so ptr-1 mean first index
	return 0;
} 
int Capacity(const IntStack *s)
{
	return s->ptr;
}
void Terminate(IntStack *s)
{
	if(s->stk != NULL)
		free(s->stk); //array delete
	s->max = s->ptr = 0;
}
//--- Àç±Í È£ÃâÀ» Á¦°ÅÇÑ recur ÇÔ¼ö ---/
void recur3(int n)
{
    int sw = 0;
    IntStack nstk, sstk;            // ìŠ¤íƒ

    Initialize(&nstk, 100);
    Initialize(&sstk, 100);

    while (1) {
        if (n > 0) {
            Push(&nstk, n);
            Push(&sstk, sw);
            if (sw == 0){
                n = n - 1;
            }
            else if (sw == 1) {
                n = n - 2;
                sw = 0;
            }
        
            continue;
        }
        do {
            Pop(&nstk, &n);
            Pop(&sstk, &sw);
            sw++;
            if (sw == 2) {
                printf("%d\n", n);
                if (IsEmpty(&nstk))
                    return;
            }
        } while (sw == 2);
    }

    Terminate(&nstk);
    Terminate(&sstk);
}

int main(void)
{
    int x;

    printf("recur3 number : ");
    scanf("%d", &x);

    recur3(x);

    return 0;
}
