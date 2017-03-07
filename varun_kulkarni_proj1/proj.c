#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*int * generateRandomNumbers(int n){
int i;	
int random_number[n];	

	for (i = 0; i < n; ++i)
	{
		random_number[i] = rand(); 
		printf("Array[%d] -> %d\t",i,random_number[i]);
	}	
	return random_number;
}
*/
/********************************* Randomized Quick Sort **************************************************************/
void swap1(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partion1(int r_number[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
    int pivot;
    int i = p - 1;
    int j,k,l;
    pivot = r_number[pivotIndex];
    swap1(&r_number[pivotIndex], &r_number[r]);
    for (j = p; j < r; j++)
    {
        if (r_number[j] < pivot)
        {
            i++;
            swap1(&r_number[i], &r_number[j]);
        }
 
    }
    swap1(&r_number[i+1], &r_number[r]);
   /* for(k = 0; k < r; k++){
			for(l = 0; l < r_number[k]; l++){
				printf("*");
			}
			printf("\n");	
		}
	printf("\n");*/
    return i + 1;
}
 
void randomQuick_sort1(int r_number[], int p, int q)
{
    int i,j,k,l;
    if (p < q)
    {
        j = partion1(r_number, p, q);
        randomQuick_sort1(r_number, p, j-1);
         for(k = 0; k < q; k++){
			for(l = 0; l < r_number[k]; l++){
				printf("*");
			}
			printf("\n");	
		}
	printf("\n");
        randomQuick_sort1(r_number, j+1, q);
         for(k = 0; k < q; k++){
			for(l = 0; l < r_number[k]; l++){
				printf("*");
			}
			printf("\n");	
		}
	printf("\n");
        /*for(i = 0; i < q; i++){
			for(j = 0; j < r_number[i]; j++){
				printf("*");
			}
			printf("\n");	
		}
	printf("\n");	*/
    }
}


void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int r_number[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
    int pivot;
    int i = p - 1;
    int j;
    pivot = r_number[pivotIndex];
    swap(&r_number[pivotIndex], &r_number[r]);
    for (j = p; j < r; j++)
    {
        if (r_number[j] < pivot)
        {
            i++;
            swap(&r_number[i], &r_number[j]);
        }
 
    }
    swap(&r_number[i+1], &r_number[r]);
    return i + 1;
}
 
void randomQuick_sort(int r_number[], int p, int q)
{
    int j;
    if (p < q)
    {
        j = partion(r_number, p, q);
        randomQuick_sort(r_number, p, j-1);
        randomQuick_sort(r_number, j+1, q);
    }
}
/***************************************************************************************************************/
/************************************************* Insertion Sort **************************************************/
void insertionsort(int n){
	int i, j, k, l;
	int random_number[n];	
	printf("This is Insertion Sort\n");
	//int *randnum = generateRandomNumbers(n);
	//int i;
	/*for (i = 0; i < n; i++)
	{
		/* code */
		//printf(" \n ---%d -- %d\n",i, randnum[i] );	//}
	if(n < 20){
			printf("\nGenerating %d random numbers:-\n", n);
			for (i = 0; i < n; ++i)
			{
				random_number[i] = rand() % 15; 
				printf("%d\t", random_number[i]);
			}
			printf("\n");

			for(i = 0; i < n; i++){
				for(j = 0; j < random_number[i]; j++){
					printf("*");
				}
				printf("\n");	
			}
			printf("\n");
			printf("Sorting:-\n");

			for (i = 1; i <= n - 1; i++)
			{
				j = i;
				while(j > 0 && random_number[j] < random_number[j-1]){
				int temp = random_number[j];
				random_number[j] = random_number[j-1];
				random_number[j-1] = temp;
				j--;
				for(k = 0; k < n; k++){
					for(l = 0; l < random_number[k]; l++){
						printf("*");
					}
					printf("\n");	
				}
				printf("\n");
				}
			}
			printf("\nFinal Sorted Elements Are:-\n");
			for (i = 0; i < n; i++)
			{
				printf("%d\t", random_number[i]);  /* code */
			}
			printf("\nFinal Sorted Elements Are:-\n");
			for(k = 0; k < n; k++){
					for(l = 0; l < random_number[k]; l++){
						printf("*");
					}
					printf("\n");	
				}
				printf("\n");

	}
	else{
			printf("\nGenerating %d random numbers:-\n", n);
			for (i = 0; i < n; ++i)
			{
				random_number[i] = rand(); 
				printf("%d\t", random_number[i]);
			}	

			for (i = 1; i <= n; i++)
			{
				j = i;
				while(j > 0 && random_number[j] < random_number[j-1]){
				int temp = random_number[j];
				random_number[j] = random_number[j-1];
				random_number[j-1] = temp;
				j--;
				}
			}

		printf("\nFinal Sorted Elements Are:-\n");
		for (i = 1; i <= n; ++i)
		{
			printf("%d\t", random_number[i]); /* code */
		}
	}
}
/*****************************************************************************************************************/

/********************************************Merge Sort **********************************************************/
void merge1(int *mergeRandom_number, int *l, int left, int *r, int right){
	int i = 0;
	int j = 0;
	int k = 0;
		while(i < left && j < right){
			if (l[i] < r[j])
				mergeRandom_number[k++] = l[i++];
			else
				mergeRandom_number[k++] = r[j++];
		}
	while(i < left)
		mergeRandom_number[k++] = l[i++];
	while(j < right)
		mergeRandom_number[k++] = r[j++];		
}

void mergesort1(int *mergeRandom_number, int n){
	int i, mid;
	int *l, *r;	
	int k,m;
	if(n < 2)  
		return;
	else
		mid = n / 2;

	l = (int *) malloc (mid * sizeof(int));
	r = (int *) malloc ((n - mid) * sizeof(int));

	for (i = 0; i < mid; i++)
	{
		l[i] = mergeRandom_number[i];
	}
	for (i = mid; i < n; i++)
	{
		r[i - mid] = mergeRandom_number[i];
	}

	mergesort1(l, mid);
	for(k = 0; k < n; k++){
					for(m = 0; m < mergeRandom_number[k]; m++){
						printf("*");
					}
					printf("\n");	
				}
				printf("\n");
	mergesort1(r, n - mid);	
	for(k = 0; k < n; k++){
					for(m = 0; m < mergeRandom_number[k]; m++){
						printf("*");
					}
					printf("\n");	
				}
				printf("\n");
	merge1(mergeRandom_number, l, mid, r, n - mid);
	for(k = 0; k < n; k++){
					for(m = 0; m < mergeRandom_number[k]; m++){
						printf("*");
					}
					printf("\n");	
				}
				printf("\n");
	//free(l);
	//free(r);
}

void merge(int *mergeRandom_number, int *l, int left, int *r, int right){
	int i = 0;
	int j = 0;
	int k = 0;
		while(i < left && j < right){
			if (l[i] < r[j])
				mergeRandom_number[k++] = l[i++];
			else
				mergeRandom_number[k++] = r[j++];
		}
	while(i < left)
		mergeRandom_number[k++] = l[i++];
	while(j < right)
		mergeRandom_number[k++] = r[j++];		

}

void mergesort(int *mergeRandom_number, int n){
	int i, mid;
	int *l, *r;	
	if(n < 2)  
		return;
	else
		mid = n / 2;

	l = (int *) malloc (mid * sizeof(int));
	r = (int *) malloc ((n - mid) * sizeof(int));

	for (i = 0; i < mid; i++)
	{
		l[i] = mergeRandom_number[i];
	}
	for (i = mid; i < n; i++)
	{
		r[i - mid] = mergeRandom_number[i];
	}

	mergesort(l, mid);
	mergesort(r, n - mid);	
	merge(mergeRandom_number, l, mid, r, n - mid);
	//free(l);
	//free(r);
}
/*************************************************************************************************************************/

/**************************************************Count Sort***********************************************************/
void countsort(int n){
	int i, j, m, l;
	int q = 1;
	int k = 100;
	int random_number[n];
	int count_array[k];	

	if(n < 20){
		printf("\nGenerating %d random numbers:-\n", n);
			for (i = 0; i < n; ++i)
			{
				random_number[i] = rand() % 15; 
				printf("%d\t", random_number[i]);
			}
			printf("\n");

			for(i = 0; i < n; i++){
				for(j = 0; j < random_number[i]; j++){
					printf("*");
				}
				printf("\n");	
			}
			printf("\n");
			printf("Sorting:-\n");

		for (i = 0; i < k; i++)
		{
			count_array[i] = 0;  // initialize count array to 0
		}		

		for (j = 0; j < n; j++)
		{
			count_array[random_number[j]] = count_array[random_number[j]] + 1;  // keeps the count 
		}

		for (j = 0; j < k; j++)
		{
			while(count_array[j] > 0){
				random_number[q] = j;
				//printf("*****%d\n", random_number[q]);
				//printf("%d\t", random_number[q]);
				count_array[j]  = count_array[j] - 1;
        	    q = q + 1;             
			}
			for(m = 0; m < n; m++){
					for(l = 0; l < random_number[m]; l++){
						printf("*");
					}
					printf("\n");	
				}
				printf("\n");
		}
		printf("\nFinal Sorted Elements Are:-\n");	
		for (i = 1; i <= n; i++)
		{	
			printf("%d\t", random_number[i]); 
		}
		printf("\nFinal Sorted Elements Are:-\n");
			for(k = 1; k <= n; k++){
					for(l = 1; l <= random_number[k]; l++){
						printf("*");
					}
					printf("\n");	
				}
				printf("\n");	
	}
	else{
		for (i = 0; i < n; ++i)
		{
			random_number[i] = rand() % 100; 
			printf("%d\t", random_number[i]);
		}
		printf("\n");
		for (i = 0; i < k; i++)
		{
			count_array[i] = 0;
		}		

		for (j = 0; j < n; j++)
		{
			count_array[random_number[j]] = count_array[random_number[j]] + 1; 
		}

		for (j = 0; j < k; j++)
		{
			while(count_array[j] > 0){
				random_number[q] = j;
				//printf("*****%d\n", random_number[q]);
				//printf("%d\t", random_number[q]);
				count_array[j]  = count_array[j] - 1;
        	    printf("%d\t", random_number[q]);             
        	    q = q + 1;
        	  //  printf("%d\t", random_number[q]);             
			}
		}

	/*printf("\nSorted Elements Are:-\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", random_number[i]); 
	}*/
	}
}
/*********************************************************************************************************************/
void main()
{
	srand ( time(NULL) );
  int ch, choice;
  //int random_number[n];
  int n,i,j,k,l;
  int p = 1;


 	printf("\nEnter Number of Elements to be Sorted:-");
	scanf("%d",&n);
	int r_number[n];
	int mergeRandom_number[n];
	int randomVal = n;
	if (n < 1 || n > 1000)
	{
		printf("Please Enter Valid Input\n");
		printf("Exiting ...\n");
		exit(0);
	}
	else{
		do
		{
	   		printf("\n--------- Sorting Algorithms -----------");
	   		//printf("\n\n\t\t\t1.  Refresh ");
	   		printf("\n 1.  Insertion Sort ");
	   		printf("\n 2.  Counting Sort ");
	   		printf("\n 3.  Merge Sort ");
	   		printf("\n 4.  Randomized Quick Sort");
	   		printf("\n Please Select Any One:");
	   		scanf("%d",&ch);

	   		switch(ch)
	   		{	

	    		case 1:
						insertionsort(n);
						break;
			    case 2:
						countsort(n);
						break;
			    case 3:
			    		printf("This is Merge Sort\n");
			    		if(n < 20){
			    			printf("\nGenerating %d random numbers:-\n", n);
							for (i = 0; i < n; ++i)
								{
									mergeRandom_number[i] = rand() % 15; 
									printf("%d\t", mergeRandom_number[i]);
								}
								printf("\n");
								for(k = 0; k < n; k++){
									for(l = 0; l < mergeRandom_number[k]; l++){
										printf("*");
									}
									printf("\n");	
								}
								//printf("\n");
								printf("\n");
							mergesort1(mergeRandom_number, n);
							printf("\nFinal Sorted Elements Are:-\n");
							for (i = 0; i < n; i++)
							{
								printf("%d\t", mergeRandom_number[i]);  /* code */
							}
							printf("\n");
							for(k = 0; k < n; k++){
								for(l = 0; l < mergeRandom_number[k]; l++){
									printf("*");
								}
								printf("\n");	
							}
							printf("\n");	
			    		}
			    		else{	
							printf("\nGenerating %d random numbers:-\n", n);
							for (i = 0; i < n; ++i)
								{
									mergeRandom_number[i] = rand(); 
									printf("%d\t", mergeRandom_number[i]);
								}
							mergesort(mergeRandom_number, n);
							printf("\nFinal Sorted Elements Are:-\n");
							for (i = 0; i < n; i++)
							{
								printf("%d\t", mergeRandom_number[i]);  /* code */
							}
						}	
						break;
	    		case 4:
	    				if(n < 20){

	    					printf("\nGenerating %d random numbers:-\n", n);
							for (i = 0; i < n; ++i)
							{
								r_number[i] = rand() % 15; 
								printf("%d\t", r_number[i]);
							}
							printf("\n");
	    						for(i = 0; i < n; i++){
									for(j = 0; j < r_number[i]; j++){
										printf("*");
									}
									printf("\n");	
								}
								printf("\n");
								printf("Sorting:-\n");	

							randomQuick_sort1(r_number, 0, n - 1);
							printf("\nFinal Sorted Elements Are:-\n");
							for (i = 0; i < n; i++)
							{
								printf("%d\t", r_number[i]);  /* code */
							}
							printf("\nFinal Sorted Elements Are:-\n");
							for(i = 0; i < n; i++){
									for(j = 0; j < r_number[i]; j++){
										printf("*");
									}
									printf("\n");	
								}
								printf("\n");								
	    				}
	    				else{	
	    						printf("\nGenerating %d random numbers:-\n", n);
									for (i = 0; i < n; i++)
									{
										r_number[i] = rand(); 
										printf("%d\t", r_number[i]);
									}	
									randomQuick_sort(r_number, 0, n - 1);
						//R_QUICKSORT(r_number, p, randomVal);
	    				//rquicksort(r_number, p, randomVal);
	    							printf("\nFinal Sorted Elements Are:-\n");
									for (i = 0; i < n; i++)
									{
										printf("%d\t", r_number[i]);  
									}
						}
						break;
		
				default : 
						printf("Please Enter Correct Choice:-\n");		
	   		}

	   	printf("\nIf you want to continue press 1 else press 0:-");
		scanf("%d",&choice);

		}while(choice == 1);
	}	
}
