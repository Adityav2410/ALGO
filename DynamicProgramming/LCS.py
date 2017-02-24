

def computeMinEditDistance(s1,s2,l1,l2):
	editDistance = [ [0 for x in range(l1+1)] for x in range(l2+1)]

	for i in range(l1+1):
		for j in range(l2+1):
			if i==0:
				editDistance[i][j] = j
			elif j==0:
				editDistance[i][j] = i				
			else:
				if s1[i-1] == s2[j-1] :
					editDistance[i][j] = editDistance[i-1][j-1]
				else:
					editDistance[i][j] = 1 + 	min( editDistance[i-1][j-1],		#replace
													 editDistance[i][j-1], 		#insert
													 editDistance[i-1][j]		#delete
													)
	return editDistance[l1+1][l2+1]






s1 = "SUNDAY"
s2 = "SATURDAY"
minEditDistance = computeMinEditDistance(s1,s2,len(s1),len(s2))
print("Min Edit Distance between two words = ",minEditDistance)