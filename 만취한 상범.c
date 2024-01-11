#include <stdio.h>
//swicth function
int find_val(int a)
{
	int i,j,k,sum=0;
	//initialized array
	int init_arr[a];
	for(i=0;i<a;i++)
	{
		init_arr[i] = 1;	// init_arr = {1,1,1,1,....} => open
	}
	for(i=2;i<=a;i++)
	{
		for(j=1;j<=a;j++)
		{
			k = j %i ;
			if(k == 0)
			{
				if(init_arr[j-1]==1)
				{
					init_arr[j-1] = 0;					
				}
				else
				{
					init_arr[j-1] = 1;
				}
			}
		}
	}
	for(i=0;i<a;i++)
	{
		sum = sum + init_arr[i];
	}
	return sum;
}

int main(void)
{
	int i,T;
	scanf("%d",&T);
	int *pnt;
	int room_size[T],res[T];
	for(i=0;i<T;i++)
	{
		scanf("%d",&room_size[i]);
	}
	pnt = &room_size[0];
	//check each room
	for(i=0;i<T;i++)
	{
		//call the function
		res[i]=find_val(*(pnt+i));
		printf("%d\n",res[i]); 
	} 
	return 0;
}
