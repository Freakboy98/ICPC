#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int max; //stack capacity
	int ptr; // stack pointer
	int *stk; // stack first pointer
}IntStack;
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
//data push
int Push(IntStack *s,int x)
{
	if(s->ptr >= s->max) // full
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}
int Size(const IntStack *s)
{
	return s->ptr;
}
void Terminate(IntStack *s)
{
	if(s->stk != NULL)
		free(s->stk); //array delete
	s->max = s->ptr = 0;
}


int set(int i,int n,int flag_a[],int flag_b[],int flag_c[],int pos[])
{
	IntStack s;
	Initialize(&s,n);
	
	int j;
	for(j=0;j<(2*n-1);j++)
	{
		if(!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+(n-1)]) // if flag[j] empty...
		{
			pos[i]= j;
			if(i==(n-1))
				Push(&s,2);
			else{
				flag_a[j] = flag_b[i+j] = flag_c[i-j+(n-1)] = 1;
				set(i+1,n,flag_a,flag_b,flag_c,pos);
				flag_a[j] = flag_b[i+j] = flag_c[i-j+(n-1)] = 0;
			}
		}
	}

	Terminate(&s);
	return ;
}
int main(void)
{
	//assignment
	int x;
	int i;
	scanf("%d",&x);
	
	int *flag_a = calloc(x,sizeof(int));  // 각 행에 퀸을 배치했는지 확인  
	int *flag_b= calloc(2*x -1 ,sizeof(int)); //대각선 / 방향으로 배치했는지 확인 
	int *flag_c= calloc(2*x -1 ,sizeof(int));  //대각선 \ 방향으로 배치했는지 확인 
	int *pos = calloc(x,sizeof(int)); 
	
	
	for(i=0;i<x;i++)
		flag_a[i] = 0;
		printf("a\n");
	for(i=0;i<(2*x-1);i++)
		flag_b[i] = flag_c[i] = 0;
		printf("b\n");
		
	
	
	printf("%d",set(0,x,flag_a,flag_b,flag_c,pos));
	
	free(flag_a);
	free(flag_b);
	free(flag_c);
	free(pos);
	
	return 0;
}
 
