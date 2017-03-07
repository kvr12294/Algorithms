#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b) 
{
    if(a > b) 
    	return a;
    else 
    	return b;
}

void lcs(char *x, char *y, int m, int n)
{
	int i,j;
	int L[m+1][n+1];
	for (i=0; i<=m; i++)
    {
    	for (j=0; j<=n; j++)
     	{
     		if (i == 0 || j == 0)
        		L[i][j] = 0;
       		else if (x[i-1] == y[j-1])
        		L[i][j] = L[i-1][j-1] + 1;
       		else
         		L[i][j] = max(L[i-1][j], L[i][j-1]);
     	}
   	}
   	int LCS = L[m][n];
   	char lcs[LCS + 1];
   	lcs[LCS] = '\0';

   	int first = m, second = n;
   	while (first > 0 && second > 0)
   	{
   		if(x[first - 1] == y[second - 1])
   		{
   			lcs[LCS - 1] = x[first - 1];
   			first--;
   			second--;
   			LCS--;
   		}
   		else if(L[first - 1][second] > L[first][second - 1])
   		{
   			first--;
   		}
   		else
   		{
   			second--;
   		}
   	}

    int length = strlen(lcs);
   	printf("LCS of x and y is %s and length of LCS is %d\n", lcs, length);
}

int main(int argc, char const *argv[])
{

  int i;
  int size = 500;
  char buff[255], buffer[200];
  char x[100], y[100], string1[100], string2[100];
  // int * string1 = malloc(size*sizeof(char));
  // int * string2 = malloc(size*sizeof(char));
  FILE *inputFile;

  if ((inputFile=fopen(argv[1],"r"))==NULL)
  {
    printf("Error! opening file");
    exit(1);         
  }

  else
  {
    while (fscanf(inputFile,"%s %s",string1, string2) != EOF)
      printf("First String Is:\n%s\n",string1);
      printf("Second String Is:\n%s\n",string2);
      strcpy(x, string1);  
      strcpy(y, string2);
      int m = strlen(x);
      int n = strlen(y);
    lcs(x, y, m, n);
    return 0;
  }
}