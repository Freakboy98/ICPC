#include <stdio.h>
int main(void)
{
	int primitive[6] = { 1, 1, 2,2,2,8};
	int c_n[6]; // c_u = current number
	int res[6];
	int i;
	scanf("%d %d %d %d %d %d",&c_n[0],&c_n[1],&c_n[2],&c_n[3],&c_n[4],&c_n[5]);
	//
	for(i=0;i<6;i++)
	{
		if(0 <= c_n[i] && c_n[i] <= 10)
		{
			if(primitive[i] >= c_n[i])
			{
				res[i] = primitive[i] - c_n[i];
			}
			else
			{
				res[i] = -(c_n[i] - primitive[i]);
			}
			
		}
		else
		{ 
			printf("Error!");
		}
	}
	//for문으로 수정해보 
	//printf("%d %d %d %d %d %d",res[0],res[1],res[2],res[3],res[4],res[5]);
	for(i=0;i<6;i++)
	{
		printf("%d ",res[i]);
	}

	return 0;
}
