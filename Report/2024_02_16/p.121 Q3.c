#include <stdio.h>
#include <stdlib.h>
int search(int a[],int n, int key, int idx[])
{
	int i;
	int count = 0;
	a[n] = key;


	for(i=0;i<n+1;i++)
	{
		if(i==n)
			break;
		if(a[i] == key)
		{
			idx[count] = i;
			count++;
		}
	}

	for(i=0;i<count;i++)
	{
		printf("idx[%d] : %d \n",i,idx[i]);
	}

	return count ;
}
int main(void)
{
	int nx,ky;
	
	printf("search\n");
	printf("element number : ");
	scanf("%d",&nx);
	int idx[nx] ;
	//make array
	int *x = calloc(nx+1,sizeof(int)); //because of sentinel method
	int i;
	for(i=0;i<nx;i++)
	{
		printf("x[%d] : ",i);
		scanf("%d",&x[i]);
	}

	//input key
	printf("\nkey : ");
	scanf("%d",&ky);
	
	int res = search(x,nx,ky,&idx);
	printf("key : %d in the list %d times",ky, res);
	free(x);
	free(idx);
	
	return 0;
}
