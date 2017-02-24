



list = [0,1,101,2,3,100,4,5]
cost=[0 for x in range(len(list))]

for i in range(1,len(list)):
	for j in range(i):
		if( list[j] < list[i]):
			cost[i] = max(cost[i],cost[j]+list[i])


for i in range(1,len(cost)):
	print(cost[i],end=" ")
print();	
