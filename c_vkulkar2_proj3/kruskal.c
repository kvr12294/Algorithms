#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int edgesinGraph(FILE * fptr)
{
	int ch, count = 0;
	while (!feof(fptr))
		if ((ch = fgetc(fptr)) == '\n')
			count++;
	return count + 1;
}

int find3(int x, int * set)
{
	int root, node, parent, i;

	root = x;

	while(root != set[root]) {
		root = set[root];
		node = x;
		while(node != root) {
			parent = set[node];
			set[node] = root;
			node = parent;
		}
	}
	return root;
}

int union3(int x, int y, int val, int * set)
{
	

	int height[val];
	if (height[x] == height[y]) {
		height[x]++;
		set[y] = x;
	} else {
		if (height[x] > height[y])
			set[y] = x;
		else
			set[x] = y;
	}
}

void randomQuicksort(int list[], int l, int h) 
{ 
	int p;
	/* index of partition */ 
	int j=h; 
	int v=h-l; 
	if (v > 0) 
	{ 
		p = partition(list, l, h); 
		randomQuicksort(list, l, p-1); 
		randomQuicksort(list, p + 1, h);
	}
}

int partition(int list[], int l, int h) 
{ 
	int i,x; 
	int p; 
	int high; 
	p = l + (rand() % (h - l)+ 1); // randomly selects pivot 
	x=list[p]; 
	list[p]=list[h]; 
	list[h]=x; 
	high = l; 
	i=l; 
	while(i < h) 
	{ 
		if(list[i] < list[h])
		{ 
			x=list[i]; 
			list[i]=list[high]; 
			list[high]=x; 
			high++;
		}
		i++;
	}
	x=list[h]; 
	list[h]=list[high]; 
	list[high]=x; 
	return high;
}

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		printf("Please provide an input file!\n");
		exit(1);
	}
	FILE *fp;
	if((fp = fopen(argv[1], "r")) == NULL) {
		printf("Error! Please try again\n");
		exit(1);
	}

	char line[100];
	char * tokens;
	int numEdges = 0, i, j, k;
	numEdges = edgesinGraph(fp);
	rewind(fp);

	int ** graph = (int **) malloc (numEdges * sizeof(int *));
	for (i = 0; i < numEdges; i++)
		graph[i] = (int *) malloc (numEdges * sizeof(int));

	int * temp_array = (int *) malloc (numEdges * numEdges * sizeof(int));
	int * set = (int *) malloc (numEdges * sizeof(int));

	i = 0;
	while (fgets(line, 100, fp) != NULL) {
		tokens = strtok(line, ",");
		while (tokens) {
			temp_array[i++] = atoi(tokens);
			tokens = strtok(NULL, ",");
		}
	}
	for (i = 0, k = 0; i < numEdges; ++i) {
		for (j = 0; j < numEdges; ++j, k++) {
			graph[i][j] = temp_array[k];
		}
	}

	printf("Input graph read from file is:\n");
	for (i = 0; i < numEdges; i++) {
		for (j = 0; j < numEdges; j++)
			printf("%4d ", graph[i][j]);
		printf("\n");
	}


	int n = numEdges;
	int noOfEdges = (n*(n-1))/2;
	 
	 // printf("\nNo of edges are: %d\n",noOfEdges);
 
	 int ne,a,b,c,ucomp,vcomp,ned=0; 
	 int edges[noOfEdges][3],min[n][n],X[noOfEdges][3],list[noOfEdges];
	 
	 ne=0; 
	for(i=0;i<n;i++) 
	{ 
		for(j=0;j<n;j++) 
		{
			if(j>i) 
			{ 
				edges[ne][0] = i;
				edges[ne][1] = j; 
				edges[ne][2] = graph[i][j]; 
				ne++;
			}
		}
	}
	 	 
	for(i=0;i<noOfEdges;i++)
	{
		list[i]=edges[i][2];
	}

	randomQuicksort(list,0,noOfEdges-1); 

	for(i=0;i<noOfEdges;i++) 
	{
		int s = list[i];
		for(j=0;j<noOfEdges;j++)
		{
			if(s==edges[j][2])
			{
				X[i][0]=edges[j][0];
				X[i][1]=edges[j][1];
				X[i][2]=edges[j][2];
				edges[j][0]=100;
				edges[j][1]=100;
				edges[j][2]=100;
				break;
			}
		}
	} 

	for (i=0;i<n-1;i++)
	{
		for (j=0;j<3;j++)
		{ 
			min[i][j]=-1;
		}
	}      

	for(i=0;i<n;i++)
	{
		set[i]=i;
	}  

	int nedges=0,u=0,v=0,p=0,weight=0;
	while(nedges<n-1)
	{
		u=X[p][0];
		v=X[p][1];
		ucomp=find3(u,set);
		vcomp=find3(v,set);
	 
		if(ucomp!=vcomp)
		{
			union3(ucomp,vcomp,n,set);
			min[nedges][0]=X[p][0];
			min[nedges][1]=X[p][1];
			min[nedges][2]=X[p][2];
			nedges++;
		}
		 p++;
	}
	printf("Assume Vertices of graph(MST) start from 0:\n\n");
	printf("\nThe edges in MST are:\n");
	printf("{");
	for(i=0;i<n-1;i++)
	{
		printf("(%d,%d)",min[i][0],min[i][1]);
		if(i<n-2)
			printf(",");
			weight=weight+min[i][2];
	}
	printf("}\nTotal weight of all edges from MST is: %d\n",weight);
	return 0;
}