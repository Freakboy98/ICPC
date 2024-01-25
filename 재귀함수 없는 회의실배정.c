#include <stdio.h>

void swap(int A[][2], int row1, int row2) {
    int temp,col;
    for (col = 0; col < 2; col++) {
        temp = A[row1][col];
        A[row1][col] = A[row2][col];
        A[row2][col] = temp;
    }
}

//quick sort

int partition(int A[][2], int start, int end);
void quick(int A[][2],int start, int end)
{
	int index;
	if(start<end)
	{
		index = partition(A, start, end); //pivot위치를 특정지어라.
		//그리고 pivot을ㄹ 기준으로 왼쪽 
		quick(A,start,index-1);
		//pivot을 기준으로 오른쪽
		quick(A,index+1,end); 
	}
	else
	{
		return ;
	}
}

int partition(int A[][2],int start,int end)
{
	int pivot = A[end][1];
	int temp;
	int i;
	int index = start;
	for(i=start;i<end;i++)
	{
		if(A[i][1]<pivot)
		{
			swap(A, i, index);
			index++;	
		}
	}
	swap(A, end, index);
	return index;
}
/*int compare(const void *a,const void *b)
{
	return (*(int*)a - *(int*)b);
}*/

int main(void)
{
	int i,n,temp;
	scanf("%d",&n);
	int A[n][2];
	for(i=0;i<n;i++) 
	{
		scanf("%d %d",&A[i][0],&A[i][1]);
	}

	//Quick sort
	quick(A,0,n-1);

		
	temp = A[0][1];
	int count =1 ;
	for(i=0;i<n;i++)
	{
		if(temp <= A[i][0])
		{
			temp = A[i][1];
			count++; 
		}
	}

	printf("%d",count);
	
	return 0;
}
