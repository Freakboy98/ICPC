#include <stdio.h>
#include <string.h>
#define max 10000
int stk[max];
int stk_ptr = 0;

void push(int n)
{
	if(stk_ptr < max)
	{
		stk[stk_ptr] = n;
		stk_ptr++;
	}
}
int empty(void)
{
	if(stk_ptr == 0)
		return 1;
	else
		return 0;
}
int pop(void)
{
	if(empty())
		return -1;
	else{
		stk_ptr--;
		return stk[stk_ptr];
	}

}

int top(void)
{
	if(empty())
		return -1;
	else
		return stk[stk_ptr-1];	
}

int main(void)
{
	//ÃÊ±âÈ­ 
	int x;
	scanf("%d",&x); //looping limit
	int i=0,num;
	
	char st[5]; //action 
	
	while(x>0)
	{
		scanf("%s",&st);
		if(strcmp(st,"push") == 0){
			scanf("%d",&num);
			push(num);
		}
		else if(strcmp(st,"pop") == 0){
			printf("%d\n",pop());
		
		}
		else if(strcmp(st,"size") == 0){
			printf("%d\n",stk_ptr);
		}
		else if(strcmp(st,"empty") == 0){
			printf("%d\n",empty());

		}
		else if(strcmp(st,"top") == 0){
			printf("%d\n",top());

		}

		x--;	
	}
	return 0;
}
