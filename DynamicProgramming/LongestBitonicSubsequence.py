
def longestBitonicLength(arr,n):

	# Create increasing Sequence
	incList = [1 for x in range(n)]	;	
	decList = [1 for x in range(n)]	;	
	bitonicList = [-1 for x in range(n)]

	for i in range(1,n):
		for j in range(i):
			incList[i] = max( incList[i], incList[j]+1) if (arr[i]>arr[j]) else incList[i]

	
	for i in reversed(range(n)):	
		for j in range(i+1,n):
			decList[i] = max( decList[i], decList[j]+1) if (arr[i]>arr[j]) else decList[i]
				

	for i in range(n):
		bitonicList[i] = incList[i]+decList[i]-1
					
	print("Increasing List")
	for i in range(n):
		print(incList[i],end="\t")

	print("\nDecreasing List")
	for i in range(n):
		print(decList[i],end="\t")	

	print("\nBitonic List")	
	for i in range(n):
		print(bitonicList[i],end="\t")		

	maxBitonic= -10000;
	for i in range(n):
		maxBitonic = bitonicList[i] if bitonicList[i]>maxBitonic else maxBitonic
	print()	
	 # (maxBitonic)	
	return(maxBitonic)

	# Create Decreasing Sequence






arr = [1,11,2,10,4,5,2,1]
bitonicLength = longestBitonicLength(arr,len(arr))
print("Longest bitonic Length in array = ",bitonicLength)