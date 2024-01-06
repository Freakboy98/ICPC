#include <stdio.h>
int main(void)
{
	int persons,i,sum=0;
	int times[5],res[5];
	int min=times[0];
	scanf("%d",&persons);
	scanf("%d %d %d %d %d",&times[0],&times[1],&times[2],&times[3],&times[4]);
	//오름차순으로 정렬 
	for(i=0;i<5;i++)
	{
		
		//크기비교 
	}
	//정렬된 배열 times[5]
	
	//각 사람들의 총 시간의 합계
	for(i=0;i<5;i++)
	{
		//i번째 사람의 기다리는 시간의 합
		//res[i] = times[0] + times[1] + ...times[i] 형태 		
	} 
	//모든 사람의 대기 시간의 총합
	for(i=0;i<5;i++)
	{
		sum+=res[i];
	} 
	printf("%d",sum);
	return 0;
	
}
