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


//재귀함수 
int find_root(int A[][2],int start ,int size) 
{
	int i = start;
	int count =1 ;
	if(i> size)
	{
		return 0;
	}


    while (i <= size && A[start][1] > A[i][0]) {
        i++;
    }
	count += find_root(A,i,size);
\
	return count;
}



int main(void)
{
	int i,j,n;
	scanf("%d",&n);
	int A[n][2];
	int result; 
	for(i=0;i<n;i++) 
	{
		scanf("%d %d",&A[i][0],&A[i][1]);
	}

	//Quick sort
	quick(A,0,n-1);

	result = find_root(A,0,n-1);
	printf("%d",result);

	
	return 0;
}
