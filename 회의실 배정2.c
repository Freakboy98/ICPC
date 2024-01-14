#include <stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a=*b;
	*b=temp;
}
//����Լ� 
int find_root(int *start, int *end, int *index, int a, int n) 
{
	int count = 1; // ���� �Լ� ȣ���� ������ count �ʱ�ȭ
	int i=a+1;
    if (i > n) 
	{
        return 0; // ��� ���� ����
    }

    int start_val = start[a];
    int end_val = end[index[a]];

    while (end_val > start[i]) {
        i++;
    }
    count += find_root(start, end, index, i, n); // ��� ȣ��
    return count;
}
//�ִ밪 ���ϴ� �Լ�
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
	//�����Ʈ
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
		//start�κ�
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
	//���������� 
	int val;
	val = max(res,n);
	printf("%d",val); 

	return 0;
}
