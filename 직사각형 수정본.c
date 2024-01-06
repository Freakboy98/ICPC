#include <stdio.h>

int main(void)
{
	//initailize
	int x,y,w,h,d1,d2,min;
	scanf("%d %d %d %d",&x,&y,&w,&h);
	//initial condition
	if((1<=w && w<=1000) && (1<=h && h<=1000))
	{
		if((1<=x && x<=w-1) && (1<=y && y<=h-1))	
		{
			d1 = x > w-x ? w-x : x;
			d2 = y > h-y ? h-y : y;
		}
		else
		{
			printf("Error!");
		}	
		min = d1 > d2 ? d2 : d1;
		printf("%d",min);
	}
	else
	{
		printf("Error!");
	}
	return 0;
}
