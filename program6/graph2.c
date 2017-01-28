/********************************************
Name:   		Isaias Delgado, Alex Hollis
Course: 		CSCE 3110.002
Assignment:     Program 6, Dijkstra's Algorithm
Due Date:       May 01, 2015 at 11:55PM
********************************************/

#include <stdio.h>
#include <time.h>
#define infinity 998
#define MAX 25

int prev[25];

void printPath(int index)
{
	if (prev[index] > 0)
	{
		printPath(prev[index]);
	}
	if(prev[index] == 0 || prev[index] == -1)
		printf("1 ");
		

	printf("%d ", index+1);
}

void lowestCost(int nodes, int startN, int cost[MAX][MAX], int *distance) //Dijkstra's Algorithm Function
{
	int i,j,count,k,flag[MAX],min;
	
/////////////////////////////
	clock_t start, end, start2, end2;		// time clocks
	clock_t times[MAX];		//store times
		
//////////////////////////////

	start2 = clock();
	
	for(i = 0; i < nodes; i++)
		distance[i] = infinity;		//initialize all nodes to infinity.
	start = clock();				// start timer
	for(i=0;i<nodes;i++)
	{
		flag[i] = 0;
		distance[i] = cost[startN][i]; //fill in initial known distances from start node to neighbors.
		if(distance[i] != infinity)		//valid edge found, take time
		{
			end = clock();
			times[i] = (end - start);		// save time in array
			start = clock();
			
		}

	}
	count = 0;
	while(count<=nodes)
	{
		min=999;
		
		for(j=0;j<nodes;j++)
		{
			if(distance[j]<min && !flag[j])
			    min=distance[j],k=j;			// set smallest edge to current node
		}
		
		flag[k]=1;
		count++;
		
		for(j=0;j<nodes;j++)
		{
			if(((distance[k]+cost[k][j]<distance[j])) && !flag[j]) //new route found, shorter distance calculated.
			{
				distance[j]=distance[k]+cost[k][j];		//new path set
				prev[j] = k;	//update path
				end = clock();
				times[j] = (end - start);			// save time
				start = clock();
			}
		}
	}

//////////// 	PRINT	///////////////
	end2 = clock();
	end = clock();
	int z;
	
	for(z = 1; z < nodes; z++)
	{
		if(distance[z] != infinity)
		{
			if(times[z] > 0) 			//check in case no time was recorded
			{
		printf(" %-2dc %.12fs ", (int)times[z], (times[z] /(double)CLOCKS_PER_SEC));
		printPath(z);
		printf("\n");
			}
			else					// default to total algoirthm time if none calculated.
			{
			printf(" %-2dc %.12fs ", (int)(end2 - start2), ((end2 - start2) /(double)CLOCKS_PER_SEC));
			printPath(z);
			printf("\n");	
			}
		}
		else
		{
			printf(" No path to Node %d\n",z+1);
		}
	}
//////////////////////////////////////
}

int main( )
{
	int nodes, startN, i, j, cost[MAX][MAX], distance[MAX];
	nodes = 25;
	

	for(i=0; i< nodes; i++)		// scan in cost matrix
	{
		for(j=0; j<nodes; j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j] == 0) 
				cost[i][j] = infinity;
		}
	}
	
	for(i = 0; i < nodes; i++)
		prev[i] = -1;
	
	startN = 0;
	
	lowestCost(nodes, startN, cost, distance);		// run Dijkstra's Algorithm



	return 0;
}