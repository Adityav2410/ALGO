INT_MIN = -32767

def cutRod(price,n):
	val = [0 for x in range(n+1)]
	val[0] = 0;

	for i in range(1,n+1):
		for j in reversed(range(i+1)):
			val[i] = max(val[i], price[j] + val[i-j])

	for i in range(n+1):
		print(val[i],end=" ")
	print()	
	return( val[n])
	

arr = [0,1,5,8,9,10,17,17,20]
size = len(arr)-1;
b = cutRod(arr,size)
print("Maximum obtainable length =" + str(b))



