#include <stdio.h>
#include <stdlib.h>
#include "Intstack.h"

//initializec
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
int Pop(IntStack *s, int *x)
{
	if(s->ptr <=0 ) // hollow
		return -1;
	*x = s->stk[--s->ptr]; // x print, then del
	return 0;
}
//peek
int Peek(const IntStack *s,int *x)
{
	if(s->ptr <= 0) // hollow
		return -1;
	*x = s->stk[s->ptr-1]; // ptr = 0, so ptr-1 mean first index
		return 0;
} 
//clear
void Clear(IntStack *s)
{
	s->ptr = 0;
}
//capacity(const Intstack *s)
int Capacity(const IntStack *s)
{
	return s->ptr;
}
//isempty
int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0; // return True or False
}
//isfull
int Isfull(const IntStack *s)
{
	return s->ptr >= s->max; // return True or False
}
//searching
int Search(const IntStack *s,int x)
{
	int i;
	for(i=s->ptr-1;i>=0;i--) // top -> bottom
		if(s->stk[i] == x)
			return i;
	return -1; //fail
}

//print all data
void Print(const IntStack *s)
{
	int i;
	for(i=0;i<s->ptr;i++)
		print("%d",s->stk[i]);
	print("\n");
}
//end
void Terminate(IntStack *s)
{
	if(s->stk != NULL)
		free(s->stk); //array delete
	s->max = s->ptr = 0;
}
