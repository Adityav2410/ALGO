
def lis(arr):
	n = len(arr)
	list = [1]*n
	for i in range(1,n):
		for j in range(0,i):
			if arr[i]> arr[j] and list[i] < list[j]+1 :
				list[i] = list[j]+1


	maximum = 0

	for i in range(n):
		maximum=max(maximum,list[i])

	return maximum			



arr = [10,22,9,33,21,50,41,60,80]
length = lis(arr)
print( 'Maxmimum Length',length )