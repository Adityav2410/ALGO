INF = float('inf')


def minPathCost(graph,V):
	minCost = graph.copy() #[ [0 for x in range(V)] for x in range(V) ]

	for k in range(V):
		for i in range(V):
			for j in range(V):
				minCost[i][j] = min( minCost[i][j], minCost[i][k]+minCost[k][j] )

		for l in range(V):
			for m in range(V):
				if( minCost[l][m] == INF):
					print("INF\t\t",end="")
				else:
					print(minCost[l][m],end="\t\t")
			print()			

		print("\n\n\n\n")	
			



	for i in range(V):
		for j in range(V):
			if( minCost[i][j] == INF):
				print("INF\t\t",end="")
			else:
				print(minCost[i][j],end="\t\t")
		print()	

					


graph = [ 	[0,		5,		INF,	10],
			[INF, 	0,		3,		INF],
			[INF,	INF,	0,		1],
			[INF,	INF,	INF,	0]
		]			

minPathCost(graph,len(graph))