#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int nelements = 0, capacity;
int * weights;
int * profit;
int * bitArray;
int maxweight = 0, val = 0;
int final_weight = 0;

int bruteforce(int * profit, int * weights, int nelements, int maxweight, int val)
{
    int i;
    int combinations = pow(2, nelements);
    for (i = 0; i < combinations ; i++) 
    {
        int j = nelements;
        int tempWeight = 0;
    	int tempProfit = 0;
        int k_elements;

       k_elements = 1;
        for (j = 0; j < nelements; j++) 
        {
            bitArray[j] += k_elements;
            k_elements = bitArray[j] / 2;
            bitArray[j] = bitArray[j] % 2;
        }
        
        if (k_elements) 
        	break;
        //bitArray[k_elements] == 1;
        for (k_elements = 0; k_elements < nelements; k_elements++) 
        {
            if (bitArray[k_elements] == 1) 
            {
                tempWeight = tempWeight + weights[k_elements];
                //printf("%d----\n", tempWeight );
                tempProfit = tempProfit + profit[k_elements];
            }
        }

        if (tempProfit > val && tempWeight <= maxweight) 
        {
        	final_weight = tempWeight;
            val = tempProfit;
        }
        
    }
    return val;
}

int main(int argc, char const *argv[])
{
	int i = 0;
	//int size = 500;
 	char buff[100], buff1[100];
 	char temp;
 	char * tokens;
  // int nelements = 0, capacity;
   weights = (int *) malloc (nelements * sizeof(int));
   profit = (int *) malloc (nelements * sizeof(int));
   bitArray = (int *) malloc (nelements * sizeof(int));
   	for(i = 0; i < nelements; i++)
    {
   		bitArray[i] = 0;
   	}
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
 		};

 		i = 0;
 		fgets(buff, 100, fp);
 		tokens = strtok(buff, ",");
 		while(tokens)
 		{
 			profit[i++] = atoi(tokens);
 			tokens = strtok(NULL, ",");	
 		}

 		fscanf(fp, "%d", &capacity);
 		if((ofp = fopen("brute_output.txt", "w")) == NULL) 
 		{
			printf("Error! can not open Output file\n");
			exit(1);
		}
 		int value = bruteforce(profit, weights, nelements, capacity, val);
 		fprintf(ofp, "%d\n", final_weight);
 		fprintf(ofp, "%d\n", value);


 		// for(i = 0; i < nelements; i++)
   //   	{
   //   		if(bitArray[i] == 1)
   //   		{
   //   			printf("%d\n", i);
   //   		}
   //   	}
 		fclose(fp);
 		fclose(ofp);
	}
	return 0;
}	