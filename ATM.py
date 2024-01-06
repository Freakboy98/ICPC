persons=int(input())
times=input()
list_each_time=times.rstrip().split(" ")
sum = 0
res = 0
sum_list=[]
if persons == len(list_each_time):
    if (1 <= persons <= 1000) :
        for i in range(len(list_each_time)):
            list_each_time[i] = int(list_each_time[i])
        list_each_time.sort()
        for i in range(len(list_each_time)):
            sum = sum + list_each_time[i]
            sum_list.append(sum)
        for itr in sum_list:
            res += itr
        print(res)

    else:
        print("Error!!")
else:
    print("Error!")



#출력 : 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 출력한다.
 