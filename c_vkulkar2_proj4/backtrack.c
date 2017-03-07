#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int maxprofit = 0;
int num = 0;

void sort(int nelements, int * weights, int * profit, int * index_of_ele)
{
	int temp, temp1, temp3;
	int i, j;
	float * units = (float *) malloc (nelements * sizeof(float));
	float temp2;
	for(i = 1; i <= nelements ; i++)
	{
		units[i] = (float)profit[i] / (float)weights[i];
	}

	//Sort elements according to (profits / weights)
	for(i = 1; i <= nelements - 1; i++)
	{
		for(j = i + 1; j <= nelements; j++)
		{
			if(units[i] < units[j])
			{
				temp2 = units[i];
				units[i] = units[j];
				units[j] = temp2;


				temp1 = profit[i];
				profit[i] = profit[j];
				profit[j] = temp1;

				temp = weights[i];
				weights[i] =weights[j];
				weights[j] = temp;

				temp3 = index_of_ele[i];
				index_of_ele[i] = index_of_ele[j];
				index_of_ele[j] = temp3;
			}
		}
	}
}

int KWF2(int i, int weight, int p, int * weights, int * profit, int capacity, int nelements)
{
	int bound;
	bound = p;
	int j;
	int * x = (int *) malloc (nelements * sizeof(int));
	for(j = i; j < nelements; j++)
	{
		x[j] = 0;
	}
	while(weight < capacity && i <= nelements)
	{
		if(weight + weights[i] <= capacity)
		{
			x[i] = 1;
			weight = weight + weights[i];
			bound = bound + profit[i];
		}
		else
		{
			x[i] = (capacity - weight) / weights[i];
			weight = capacity;
			bound = bound + profit[i] * x[i];
		}
		i++;
	}
	return bound;
}

void copyArray(int * bestset, int * include, int nelements)
{
	int i;
	for (i = 1; i <= nelements; ++i)
	{
		bestset[i] = include[i];
	}
}

int promising(int i, int weight, int p, int * weights, int * profit, int capacity, int nelements)
{
	//bound;
	if(weight >= capacity)
	{	
		return 0;
	}
	else
	{
		int upperbound = KWF2(i + 1, weight, p, weights, profit, capacity, nelements);
		return (upperbound > maxprofit);
	}
}

void knapsack(int i, int weight, int p, int * weights, int * profit, int capacity, int nelements, int * include, int * bestset)
{
	if(weight <= capacity && p > maxprofit)
	{
		maxprofit = p;
		num = i;
		copyArray(bestset, include, nelements);
	}
	if(promising(i, weight, p, weights, profit, capacity, nelements))
	{
		include[i + 1] = 1;
		knapsack(i + 1, weight + weights[i + 1], p + profit[i + 1], weights, profit, capacity, nelements, include, bestset);
		include[i + 1] = 0;
		knapsack(i + 1, weight, p, weights, profit, capacity, nelements, include, bestset);
	}
}

int main(int argc, char const *argv[])
{
	int i = 1;
	//int weight = 0;
	//int size = 500;
	int count = 0;
 	char buff[100], buff1[100];
 	char temp;
 	char * tokens;
    int nelements = 0, capacity;
    int * weights = (int *) malloc (nelements * sizeof(int));
    int * profit = (int *) malloc (nelements * sizeof(int));
    int * include = (int *) calloc (nelements, sizeof(int));
    int * bestset = (int *) calloc (nelements, sizeof(int));
    int * index_of_ele = (int *) malloc (nelements * sizeof(int));

	if (argc != 2) {
		printf("Please provide an input file!\n");
		exit(1);
	}
	FILE *fp, *ofp;
	if((fp = fopen(argv[1], "r")) == NULL) {
		printf("Error! Please try again\n");
		exit(1);
	}
	else
	{
 		fscanf(fp, "%d", &nelements);
 		fgets(buff, 100, fp);
 		
 		fgets(buff, 100, fp);
 		tokens = strtok(buff, ",");
 		while(tokens)
 		{
 			weights[i++] = atoi(tokens);
 			tokens = strtok(NULL, ",");
 		}

 		i = 1;
 		fgets(buff, 100, fp);
 		tokens = strtok(buff, ",");
 		while(tokens)
 		{
 			profit[i++] = atoi(tokens);
 			tokens = strtok(NULL, ",");	
 		}

 		fscanf(fp, "%d", &capacity);
 		for(i = 1; i <= nelements; i++)
   		{
   			index_of_ele[i] = i;
    	}

    	if((ofp = fopen("backtrack_output.txt", "w")) == NULL) 
 		{
			printf("Error! Opening\n");
			exit(1);
		}

 		sort(nelements, weights, profit, index_of_ele);
 		knapsack(0, 0, 0, weights, profit, capacity, nelements, include, bestset);
 		
 		

 		//fprintf(ofp, "%d\n", maxprofit);
 		int w;
 		for(i = 1; i <= num; i++)
 		{
 			if(bestset[i] == 1)
 			{
 		  		//fprintf(ofp, "%d\n", index_of_ele[i] - 1);
 		  		w = w + weights[i];
 		  		count++;
 		  	}
 		}
 		// printf("%d\n", count);
 		fprintf(ofp, "%d\n", w);
 		fprintf(ofp, "%d\n", maxprofit);
 		for(i = 1; i <= num; i++)
 		{
 			if(bestset[i] == 1)
 			{
 		  		fprintf(ofp, "%d", index_of_ele[i] - 1);
 		  		count--;
 		  		if(count != 0)
 		  		{
 		  			fprintf(ofp, ", " );
 		  		}
 		  		//w = w + weights[i];
 		  	}
 		  	//fprintf(ofp, ", ");
 		}
 		//fprintf(ofp, "YO" );
 		fclose(fp);
 		fclose(ofp);
	}
	return 0;
}	