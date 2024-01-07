#include <stdio.h>
int main(void)
{
	int persons,i,j,k,temp,sum=0;
	scanf("%d",&persons);
	int times[persons],res[persons];
	for(i=0;i<persons;i++)
	{
		scanf("%d",&times[i]);
	}
//배열 형이 고정되어 있어서 길이가 달라지면 틀리게 된다.
 
	//오름차순으로 정렬 
	for(i=0;i<persons-1;i++)
	{
		for(j=i+1;j<persons;j++)
		{
			if(times[i] > times[j])
			{
				temp = times[j];
				times[j] = times[i];
				times[i] = temp;
			}
		}

		}
	/*for(i=0;i<persons;i++)
	{
		printf("%d ",times[i]);
	}*/ 
	
	//정렬된 배열 times[5]

	//각 사람들의 총 시간의 합계
	//i번째 사람의 기다리는 시간의 합
	//res[i] = times[0] + times[1] + ...times[i] 형태 	
	for(i=0;i<persons;i++)
	{
		sum += times[i];
		res[i] = sum;
		//printf("%d번째 사람의 시간은 %d입니다.\n", i+1,res[i]);
	} 
	//sum 변수 초기화 
	sum=0;
	//모든 사람의 대기 시간의 총합
	for(i=0;i<persons;i++)
	{
		sum+=res[i];
		//printf("%d\n", sum);
	} 
	printf("%d",sum);
	return 0;
	
}
