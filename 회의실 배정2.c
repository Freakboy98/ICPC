#include <stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a=*b;
	*b=temp;
}
//재귀함수 
int find_root(int *start, int *end, int *index, int a, int n) 
{
	int count = 1; // 현재 함수 호출을 포함한 count 초기화
	int i=a+1;
    if (i > n) 
	{
        return 0; // 재귀 종료 조건
    }

    int start_val = start[a];
    int end_val = end[index[a]];

    while (end_val > start[i]) {
        i++;
    }
    count += find_root(start, end, index, i, n); // 재귀 호출
    return count;
}
//최대값 구하는 함수
int max(int *res,int size) 
{
	int i;
	int max=0;
	for(i=0;i<size ; i++)
	{
		if(max < res[i])
		{
			max = res[i];
		}
	}
	return max;
}
int main(void)
{
	//버블소트
	int i,j,n;
	scanf("%d",&n);
	int start[n],end[n],index[n];
	int res[n];
	for(i=0;i<n;i++) 
	{
		scanf("%d %d",&start[i],&end[i]);
		index[i]=i;
	}
		
	/*
	printf("before sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",start[i],index[i]);
	}*/
	//Bouble sort
	for(i=0;i<n-1;i++)
	{
		//start부분
		for(j=0;j<n-i-1;j++)
		{
			if(start[j] > start[j+1])
			{
				swap(&start[j],&start[j+1]);
				swap(&index[j],&index[j+1]);		
			}	
		} 
	}
	/*printf("after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",start[i],end[index[i]]);
	}
	*/
	for(i=0;i<n;i++)
	{
    	res[i] = find_root(start, end, index, i, n);
	}
	//최종결과출력 
	int val;
	val = max(res,n);
	printf("%d",val); 

	return 0;
}
