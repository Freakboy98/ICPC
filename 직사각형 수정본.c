#include <stdio.h>

int main(void)
{
	//�ʱ�ȭ
	int x,y,w,h,d1,d2,min;
	scanf("%d %d %d %d",&x,&y,&w,&h);
	
	//��������
 	/*(1<=w && w<=1000)
 	(1<=h && h<=1000)
	(1<=x && x<=w-1)
	(1<=y && y<=h-1)*/
	
	// ����� ��
	//������ 4���� ��ǥ�߿��� ��輱���� �Ÿ� ��

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
