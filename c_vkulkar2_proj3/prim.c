#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **InputGraph, *visited, *distance, *previous;
int v;

int deleteminEdge()
{
	int i,index, min =999;
   for (i=0;i<v;i++)
    if(visited[i] == 0 && distance[i] < min)			
	{
        min = distance[i];
		index = i;
	}
   return index;
}

void prims()
{
    int i,j,u,weight=0;
    for (i=0;i<v;i++)								 
	{
        distance[i] = 999;
		visited[i] = 0;
	}
     previous[0] = -1;
	 distance[0] = 0;										
    									
 
    for (i=0;i<(v-1);i++)
    {
        u = deleteminEdge();				
        visited[u] = 1;
 
        for (j=0;j<v;j++)									
		{													
		if (InputGraph[j][u] < distance[j] && visited[j] == 0)
		  {
		  	distance[j] = InputGraph[j][u];
            previous[j]  = u;
		  }
		}
    }

    printf("MST Is....\n");
	
   	for (i=1;i<v;i++)
	{
		weight = weight + InputGraph[i][previous[i]];
		printf("Vertices are %d and %d \t cost is %d \n", previous[i]+1, i+1, InputGraph[previous[i]][i]);
	}

	printf("\nTotal weight of all edges from MST is: %d\n",weight);
}

int main(int argc, char* argv[])
{
	int i,j,noofedges;
	FILE *fp;
	  char buffer[512];
	  char* token=(char*)malloc(sizeof(char));
	if(argc != 2)														
	{
		printf("\nPlease provide an Input file:\n");
		return -1;
	}
	char *input_file = argv[1];
    fp=fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("\nError..Please try again!!\n ");
        return -1;
    }

	InputGraph = (int **)malloc(100 * sizeof(int *));				
	for (i=0;i<100;i++)
		InputGraph[i] = (int *)malloc(100 * sizeof(int));

	j=0; v=0;
    while(fgets(buffer,512,fp)!=NULL)
    {
        token=strtok(buffer,",");

        while(token!=NULL)
        {
            InputGraph[v][j]=atoi(token);
            j++;
            token=strtok(NULL,",");
        }
        v++;
        j=0;
    }
    fclose(fp); 
    
	visited = (int *)malloc(v * sizeof(int));
	distance = (int *)malloc(v * sizeof(int));						
	previous = (int *)malloc(v * sizeof(int));
	
	
	printf("\nMatrix given by user is:(Input Graph)\n");
	for(i=0;i<v;i++)
	  {
		 for(j=0;j<v;j++)
		     printf("%d\t",InputGraph[i][j]);							
		 printf("\n");
	  }
    prims();	
	
	free(InputGraph);
	free(distance);														
	free(visited);
	free(previous); 
    return 0;
}