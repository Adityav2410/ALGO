
def checkPartition(list,N,numElements):
	checkSum = [ [0 for x in range(N+1)] for x in range(numElements+1) ]
	for i in range(numElements+1):
		checkSum[i][0]=1

	for i in range(1,numElements+1):
		for j in range(1,N+1):
			flag1 = checkSum[i-1][j]		# the number at ith location is not present in the sum List
			flag2 = 1 if( list[i-1]<=j and checkSum[i-1][j-list[i-1]]==1 ) else 0
			checkSum[i][j]=1 if(flag1 + flag2>0) else 0

	for i in range(0,numElements+1):
		for j in range(0,N+1):
			print(checkSum[i][j],end="\t")
		print()	

	return(checkSum[numElements][N])	







list = [3,1,1,2,2,1]
sumList = sum(list)
if( sumList%2 == 0):
	partitionPossible = checkPartition(list,int(sumList/2), len(list))
	if(partitionPossible):
		print("Partition is possible")
	else:
		print("Partition is not possible")


else:
	print("List cannot be partitioned into two sublist with equal sum")



