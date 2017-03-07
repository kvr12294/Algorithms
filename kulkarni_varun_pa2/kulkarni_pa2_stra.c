#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define bool int

bool ispowerofTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}

void strassen(int n, int A[n][n], int B[n][n], int Result_matrix[n][n]) 
{

	if(n == 2)
	{
        int M1, M2, M3, M4, M5, M6, M7;
        M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
        M2 = (A[1][0] + A[1][1]) * B[0][0];
        M3 = A[0][0] * (B[0][1] - B[1][1]);
        M4 = A[1][1] * (B[1][0] - B[0][0]);
        M5 = (A[0][0] + A[0][1]) * B[1][1];
        M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
        M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

        Result_matrix[0][0] = M1 + M4 - M5 + M7;
        Result_matrix[0][1] = M3 + M5;
        Result_matrix[1][0] = M2 + M4;
        Result_matrix[1][1] = M1 + M3 - M2 + M6;

		return;
	}
	else
	{
		int a1[n/2][n/2], a2[n/2][n/2], a3[n/2][n/2], a4[n/2][n/2];
		int b1[n/2][n/2], b2[n/2][n/2], b3[n/2][n/2], b4[n/2][n/2];
		int i, j, m, q;

		for(i = 0, m = 0; i < n/2, m < n/2; i++, m++)
		{
			for(j = 0, q = 0; j < n/2, q < n/2; j++, q++)
		  	{
				a1[m][q] = A[i][j];
			}
		}

        for(i = 0, m = 0; i < n/2, m < n/2; i++, m++)
		{
            for(j = n/2, q = 0; j < n, q < n/2; j++, q++)
            {	
				a2[m][q] = A[i][j];
			}
		}

        for(i = n/2, m = 0; i < n, m < n/2; i++, m++)
        {
			for(j = 0, q = 0; j < n/2, q < n/2; j++, q++)
		        a3[m][q] = A[i][j];
		}
              
        for(i = n/2, m = 0; i < n, m < n/2; i++, m++)
        {
			for(j = n/2, q = 0; j < n, q < n/2; j++, q++)
                a4[m][q] = A[i][j];
		}
          
        for(i = 0, m = 0; i < n/2, m < n/2; i++, m++)
        {
			for(j = 0, q = 0; j < n/2, q < n/2; j++, q++)
                b1[m][q] = B[i][j];
		}

        for(i = 0, m = 0; i < n/2, m < n/2; i++, m++)
        {
			for(j = n/2, q = 0; j < n, q < n/2; j++, q++)
                b2[m][q] = B[i][j];
		}
                
        for(i = n/2, m = 0; i < n, m < n/2; i++, m++)
        {
			for(j = 0, q = 0; j < n/2, q < n/2; j++, q++)
                b3[m][q] = B[i][j];
		}

        for(i = n/2, m = 0; i < n, m < n/2; i++, m++)
        {
			for(j = n/2, q = 0; j < n, q < n/2; j++, q++)
                b4[m][q] = B[i][j];
		}

		int k = 0;
		int M11[n/2][n/2];
		int M12[n/2][n/2];
		int M21[n/2][n/2];
		int M32[n/2][n/2];
		int M42[n/2][n/2];
		int M51[n/2][n/2];
		int M61[n/2][n/2];
		int M62[n/2][n/2];
		int M71[n/2][n/2];
		int M72[n/2][n/2];

		for(i = 0; i < n/2; i++)
	 	{
			for(j = 0; j < n/2; j++)
	  			M11[i][j] = a1[i][j] + a4[i][j];
		}

        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
              	M12[i][j] = b1[i][j] + b4[i][j];
		}
            
        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
              	M21[i][j] = a3[i][j] + a4[i][j];
		}
            
        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
              	M32[i][j] = b2[i][j] - b4[i][j];
		}

        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
              	M42[i][j] = b3[i][j] - b1[i][j];
		}
            
        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
              	M51[i][j] = a1[i][j] + a2[i][j];
		}
            
        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
              	M61[i][j] = a3[i][j] - a1[i][j];
		}
            
        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
              	M62[i][j] = b1[i][j] + b2[i][j];
		}
            
        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
		        M71[i][j] = a2[i][j] - a4[i][j];
		}
            
        for(i = 0; i < n/2; i++)
        {
			for(j = 0; j < n/2; j++)
              	M72[i][j] = b3[i][j] + b4[i][j];	
		}

			int M1[n/2][n/2], M2[n/2][n/2], M3[n/2][n/2], M4[n/2][n/2], M5[n/2][n/2], M6[n/2][n/2], M7[n/2][n/2] ;
			int temp = 0;

	        for(i = 0; i < n/2; i++)
	            for(j = 0; j < n/2; j++)
	            {
	  				M1[i][j] = 0;
              		M2[i][j] = 0;
              		M3[i][j] = 0;
             		M4[i][j] = 0;
              		M5[i][j] = 0;
					M6[i][j] = 0;
					M7[i][j] = 0;
		 		}

            for(i = 0; i < n/2; i++)
                for(j = 0; j < n/2; j++)
		 		{
		  			for(k = 0; k < n/2; k++)
                   		temp += M11[i][k] * M12[k][j];
						M1[i][j] = temp;
						temp = 0;
				}

			temp = 0;
            for(i = 0; i < n/2; i++)
                for(j = 0; j < n/2; j++)
                {
		  			for(k = 0; k < n/2; k++)
		   				temp += M21[i][k] * b1[k][j];
		   				M2[i][j] = temp;
		   				temp= 0;
		  		}

			temp = 0;
            for(i = 0; i < n/2; i++)
                for(j = 0; j < n/2; j++)
			 	{
                  	for(k = 0; k < n/2; k++)
                   		temp += a1[i][k] * M32[k][j];
						M3[i][j] = temp;
						temp = 0;
		  		}

			temp = 0;
            for(i = 0; i < n/2; i++)
                for(j = 0; j < n/2; j++)
		 		{
                  	for(k = 0; k < n/2; k++)
                   		temp += a4[i][k] * M42[k][j];
						M4[i][j] = temp;
						temp = 0;
		  		}	

			temp = 0;
            for(i = 0; i < n/2; i++)
              	for(j = 0; j < n/2; j++)
				{
                  	for(k = 0; k < n/2; k++)
                   		temp += M51[i][k] * b4[k][j];
		   				M5[i][j] = temp;
		   				temp = 0;
		 	 	}	

			temp = 0;
            for(i = 0; i < n/2; i++)
                for(j = 0; j < n/2; j++)
		 		{
                  	for(k = 0; k < n/2; k++)
                   		temp += M61[i][k] * M62[k][j];
		   				M6[i][j] = temp;
		   				temp = 0;
		  		}

			temp = 0;
            for(i = 0; i < n/2; i++)
                for(j = 0; j < n/2; j++)
		 		{
                  	for(k = 0; k < n/2; k++)
		   			temp += M71[i][k] * M72[k][j];
		   			M7[i][j] = temp;
		   			temp = 0;
		  		}

			strassen(n/2, M11, M12, M1);
            strassen(n/2, M21, b1, M2);
            strassen(n/2, a1, M32, M3);
            strassen(n/2, a4, M42, M4);
	        strassen(n/2, M51, b4, M5);
	        strassen(n/2, M61, M62, M6);
	        strassen(n/2, M71, M72, M7);

            for(i = 0; i < n/2; i++)
			{
                for(j = 0; j < n/2; j++)
	        	{
					Result_matrix[i][j] = M1[i][j]+M4[i][j]-M5[i][j]+M7[i][j];
			 	}
			}

            for(i = 0, m = 0; i < n/2, m < n/2; i++, m++)
			{
                for(j = n/2, q = 0; j < n, q < n/2; j++, q++)
                { 
					Result_matrix[i][j] = M3[m][q]+M5[m][q];
				}
			}

            for(i = n/2, m = 0; i < n, m < n/2; i++, m++)
            { 
				Result_matrix[i][j] = M3[m][q]+M5[m][q];
				for(j = 0, q = 0; j < n/2, q < n/2; j++, q++)
				{
	                Result_matrix[i][j] = M2[m][q]+M4[m][q];
				}
			}

            for(i = n/2, m = 0; i < n, m < n/2; i++, m++)
            {
				for(j = n/2, q = 0; j < n, q < n/2; j++, q++)
				{
                  	Result_matrix[i][j] = M1[m][q]+M3[m][q]-M2[m][q]+M6[m][q];
				}
			}
	}
}
	


void matmul(int n,int A[n][n],int B[n][n],int C[n][n])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(k=0,C[i][k]=0;k<n;k++)
		{
			for(j=0;i<n;j++)
			{
				C[i][k]=C[i][k]+(A[k][j]*B[j][k]);
			}
		}
	}
}

int main()
{
	int size;
	srand(time(NULL));
	printf("\nEnter a Number to generate matrices:-");
	scanf("%d",&size);
	if(ispowerofTwo(size))
	{
		int flag = 0;
		int matrix_size = 1;
			while (matrix_size < size) matrix_size*=2;

		int i, j, k, n = matrix_size;
		
		int A[n][n], B[n][n], C[n][n], Result_matrix[n][n],Res1[n][n];

		
		for(i = 0; i < n; i++)
		{
		 	for(j = 0; j < n; j++)
		 	{
				A[i][j] = rand() % (10 - (-10) + 1) + (-10);
		 	}
		}
		
		for(i = 0; i < n; i++)
		{
		 	for(j = 0; j < n; j++)
			 {
				B[i][j] = rand() % (10 - (-10) + 1) + (-10);
		 	}
		}
		for(i = 0; i < n; i++)
		{
		 	for(j = 0; j < n; j++)
			 {
				C[i][j] = 0;
				Result_matrix[i][j] = 0;
		 	}
		}

		int temp = 0;
		for(i = 0; i < n; i++)
		{
		 	for(j = 0; j < n; j++)
		 	{
		 		 for(k = 0; k < n; k++)
		  		{
					temp += A[i][k] * B[k][j];
		  		}
				C[i][j] = temp;
				temp = 0;
		 	}
		}

		if(n == 1)
	        {
	            int temp = 0;
	            for(i = 0; i < n; i++)
	            {
	             	for(j = 0; j < n; j++)
	             	{
	              		for(k = 0; k < n; k++)
	              		{
	                    		temp += A[i][k] * B[k][j];
	              		}
	                    	Result_matrix[i][j] = temp;
	                    	temp = 0;
	             	}
	            }
	        }
		else
		{
			strassen(n, A, B, Result_matrix);
		}

		printf("\nMatrix 1\n");
		for(i = 0; i < n; i++)
		{
		 	for(j = 0; j < n; j++)
		 	{
				printf("%d\t", A[i][j]);
		 	}
		 	printf("\n");
		}

		printf("\nMatrix 2\n");
		for(i = 0; i < n; i++)
		{
		 	for(j = 0; j < n; j++)
		 	{
				printf("%d\t", B[i][j]);
		 	}
		 	printf("\n");
		}

		flag = 0;
		for(i = 0; i < n; i++)
			{
		 		for(j = 0; j < n; j++)
		 		{
		  			for(k = 0; k < n; k++)
		  			{
						if(C[i][j] != Result_matrix[i][j])
			 			flag = 1;
		  			}
		 		}
			}

		if(flag == 1)
		{
			printf("\nMatrices are not matching:-\n");
			exit(-1);
		}

		printf("\n********Strassen's Matrix Multiplication********\n");
		for(i = 0; i < n; i++)
		{
		 	for(j = 0; j < n; j++)
		 	{
		  		printf("%d\t", Result_matrix[i][j]);
		 	}
		 	printf("\n");
		}

		//matmul(n, A, B, Result_matrix);

		printf("\n********Simple Matrix Multiplication************\n");
		for(i = 0; i < n; i++)
			{
		 		for(j = 0; j < n; j++)
		 		{
		  			printf("%d\t", C[i][j]);
		 		}
		 		printf("\n");
			}
		return 0;
	}
	else
	{
		printf("Enter Valid Input:(Should be power of two)\n");
		exit(0);
	}	
}

