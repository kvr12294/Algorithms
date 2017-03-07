#include <stdio.h>
#include <string.h>
int n1,n2;
/*int min(int a,int b) 
{
	if(a<b)
	  return(a); 
	else
	  return(b);
}*/

void floyds(int w[100][100][100], int p[100][100]) 
{
	int i,j,k;
	//printf("*************\n%d\n********",n1 );
	//printf("-------------%d\n",w[2][1]);
	/*printf("Shortest path Matrix is:-\n");
		for (i = 1; i <= n1; i++)
		{
			for (j = 1; j <= n1; j++)
			{
				printf("%d \t", w[i][j]);
			}
			printf("\n");
		}*/
		//w[2][1] =1000;
	for (k=1;k<=n1;k++)
	{
		for (i=1;i<=n1;i++)
		{
		   	for (j=1;j<=n1;j++)
		   	{
	    		if(w[k-1][i][j] > w[k-1][i][k] + w[k-1][k][j]  && ( w[k-1][k][j] != 500 && w[k-1][i][k] != 500 ))
	    		{
	    			//if( i != k && j != k)
	    				//printf("%s\n", "changing w cell");
	     				w[k][i][j] = w[k-1][i][k] + w[k-1][k][j]; 
	    				p[i][j] = k;
	    		}
	    		else
	    		{
	    			w[k][i][j] = w[k-1][i][j];
	    		}
				//else
				//{
					//w[i][j] = w[i][j];
				//}		
			}	
	  	}
		/*printf("Shortest path Matrix is:-\n");
		for (i = 1; i <= n1; i++)
		{
			for (j = 1; j <= n1; j++)
			{
				printf("%d \t", p[i][j]);
			}
			printf("\n");
		}*/
	}

	printf("Shortest path Matrix D is:-\n");
	for (i = 1; i <= n1; i++)
	{
		for (j = 1; j <= n1; j++)
		{
			printf("%d \t", w[3][i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatrix P is\n");
	for (i = 1; i <= n1; i++)
	{
		for (j = 1; j <= n1; j++)
		{
			printf("%d \t", p[i][j]);
		}
		printf("\n");
	}	
}

void main()
{
	FILE * fp;
	char buff[255];
	int i,j;
	int w[100][100][100];
	int p[100][100] = {{0}};
	/*for (i = 0; i < 50; ++i)
	{
		for (j = 0; j < 50; ++j)
		{
			w[i][j] = 500;
		}
	}*/
	fp = fopen("input.txt","r");
	//printf("File \n");
	int row = 1;
   int col = 1;
	while(!feof(fp))
	{
		fgets(buff, 255, (FILE*)fp);
		//printf("%s\n",buff );x
			if(buff[0] != '\0')
				{
			   		const char s[2] = ",";
			   		char *token;
			   
				   /* get the first token */
				   token = strtok(buff, s);
				   
				   /* walk through other tokens */
				   while( token != NULL ) 
				   {
				      //printf( "---------------- %s\n", token );
				       w[0][row][col] = atoi(token);	
				       col++;

				      token = strtok(NULL, s);
				      //printf("***************%d\n",col);
				   }
				   n2 = col - 1;
				   row++;
				   col = 1;
				}
			else
				continue;		   
		//	printf("%s\n", buff );
	}
	n1 = row - 1;
	//printf(" rowcount is %d and columncount is %d\n", n1, n2);
	//floyds(w);
	
	//printf("%dsdhaksjdhsaf\n",w[0][2][1]);
	printf("\nInitial Adjacency Matrix is:-\n");
	for (i = 1; i <= n1; i++)
	{
		for (j = 1; j <= n1; j++)
		{
			printf("%d \t", w[0][i][j]);
		}
		printf("\n");
	}
	floyds(w, p);
	fclose(fp);

		
	// printf("\n The shortest paths are:\n");
	// for (i = 1; i < n1 ; i++)
	//   for (j = 1; j < n1; j++) {
	// 	if(i!=j)
	// 	    printf("\n <%d,%d>=%d",i,j,w[i][j]);
	// }
	// printf("\n");
	//inst[i].dest = strtok(NULL , " ");
}