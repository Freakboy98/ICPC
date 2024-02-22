#include <stdio.h>
#include <stdlib.h>
int set(int i,int n,int flag_a[],int flag_b[],int flag_c[],int pos[],int arr[])
{
	int j;
	for(j=0;j<n;j++)
	{
		if(!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+(n-1)]) // if flag[j] empty...
		{
			pos[i]= j;
			if(i==(n-1))
				arr[i] = 1;
			else{
				flag_a[j] = flag_b[i+j] = flag_c[i-j+(n-1)] = 1;
				set(i+1,n,flag_a,flag_b,flag_c,pos,arr);
				flag_a[j] = flag_b[i+j] = flag_c[i-j+(n-1)] = 0;
			}
		}
	}

	return arr;
}
int main(void)
{
	int n,i;
	scanf("%d",&n);
	int *flag_a = (int*)calloc(n,sizeof(int));
	int *flag_b = (int*)calloc(2*n-1,sizeof(int));
	int *flag_c = (int*)calloc(2*n-1,sizeof(int));
	int *pos = (int*)calloc(n,sizeof(int));

	int ptr = 0;
	int max;
	int arr[10001]={0,};
	
	for(i=0;i<n;i++)
	{
		pos[i] = flag_a[i] = 0;
		
	}
	for(i=0;i<2*n-1;i++)
	{
		flag_b[i] = flag_c[i] = 0;
		
	}
	int res = set(0,n,flag_a,flag_b,flag_c,pos,arr);
	printf("%d",res);
	int sum = 0;
	for(i=0;i<10001;i++)
		sum += arr[i];
	printf("%d",sum);
	free(flag_a);
	free(flag_b);
	free(flag_c);
	free(pos);
	return 0;
}
