#include <stdio.h>

int main(void)
{
	//초기화
	int x,y,w,h,d1,d2,min;
	scanf("%d %d %d %d",&x,&y,&w,&h);
	
	//제한조건
 	/*(1<=w && w<=1000)
 	(1<=h && h<=1000)
	(1<=x && x<=w-1)
	(1<=y && y<=h-1)*/
	
	// 경우의 수
	//꼭지점 4개의 좌표중에서 경계선과의 거리 차

	if((1<=w && w<=1000) && (1<=h && h<=1000) && (1<=x && x<=w-1) && (1<=y && y<=h-1))
	{	
		if(x-0 > w-x)
		{
	 		d1 = w-x;
		}
		else if(x-0 == w-x)
		{
			d1 = x;
		}		

		else if(y-0 > h-y)
		{
			d2 = h-y;
		}
		else
		{
			d2 = y;
		}

	}
	else
	{
		printf("Error!");
	
	}
	
	if(d1 > d2)
	{
		min=d2;
	}
	else
	{
		min = d1;
	}	
	printf("%d",min);

	
	return 0;
	
}
