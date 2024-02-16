#include <stdio.h>
int search_idx(const int a[],int n, int key)
{
	int pl=0;
	int pr = n-1;
	int i,j=0;
	do
	{
		int pc = (pl + pr) /2;
		if(a[pc] == key)
			return pc;
		else if(a[pc] < key)
			pl = pc+1;
		else
			pr = pc-1;
	}while(pl<=pr);

	return -1;
}
int first_num(int idx,int key, int a[])
{
	int res = 0;
	while(1)
	{
		if(a[idx] == key)
			idx--;
		else
			return idx +1;
	}
}
int main(void)
{
	int nx,ky,i;
	printf("element number : ");
	scanf("%d",&nx);
	int *x = calloc(nx,sizeof(int));
	puts("\nsearch\n");
	printf("x[0] : ");
	scanf("%d",&x[0]);
	for(i=1;i<nx;i++)
		do
		{
			printf("x[%d] : ",i);
			scanf("%d",&x[i]);
		}while(x[i] < x[i-1]);
	//assignment done
	printf("key : ");
	scanf("%d",&ky);
	int idx = search_idx(x,nx, ky);
	int res = first_num(idx,ky, x);
	printf("key %d is located x[%d]",idx,res);
	free(x);
	
	return 0;
}
