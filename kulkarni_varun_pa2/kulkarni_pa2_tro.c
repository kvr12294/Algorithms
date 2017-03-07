#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tromino[100][100];
int current_tile;
int actual_board_size;

void tromino_tiling(int size, int x_coordinate, int y_coordinate) 
{
	if (size == 2) {
		int i,j;
			
		for (i=0; i<size; i++) 
			for (j=0; j<size; j++)
				if (tromino[x_coordinate+i][y_coordinate+j] == 0)
					tromino[x_coordinate+i][y_coordinate+j] = current_tile;
		current_tile++;
	}
	else 
	{
		int x_tile = x_coordinate, y_tile=y_coordinate;
		int x,y;
		for (x=x_coordinate; x<x_coordinate+size; x++) 
			for (y=y_coordinate; y<y_coordinate+size; y++)
				if (tromino[x][y] != 0) 
				{
					x_tile = x;
					y_tile = y;
				}		
		if (x_tile < x_coordinate + size/2 && y_tile < y_coordinate + size/2) 
		{
			
			tromino_tiling(size/2, x_coordinate, y_coordinate);
			
			tromino[x_coordinate+size/2][y_coordinate+size/2-1] = current_tile;
			tromino[x_coordinate+size/2][y_coordinate+size/2] = current_tile;
			tromino[x_coordinate+size/2-1][y_coordinate+size/2] = current_tile;

			current_tile++;
			
			tromino_tiling(size/2, x_coordinate, y_coordinate+size/2);
			tromino_tiling(size/2, x_coordinate+size/2, y_coordinate);
			tromino_tiling(size/2, x_coordinate+size/2, y_coordinate+size/2);
			
		}
		
		else if (x_tile < x_coordinate + size/2 && y_tile >= y_coordinate + size/2) 
		{
			tromino_tiling(size/2, x_coordinate, y_coordinate+size/2);
			
			tromino[x_coordinate+size/2][y_coordinate+size/2-1] = current_tile;
			tromino[x_coordinate+size/2][y_coordinate+size/2] = current_tile;
			tromino[x_coordinate+size/2-1][y_coordinate+size/2-1] = current_tile;
			
			current_tile++;
			
			tromino_tiling(size/2, x_coordinate, y_coordinate);
			tromino_tiling(size/2, x_coordinate+size/2, y_coordinate);
			tromino_tiling(size/2, x_coordinate+size/2, y_coordinate+size/2);
			
		}
		
		else if (x_tile >= x_coordinate + size/2 && y_tile < y_coordinate + size/2) 
		{			
			tromino_tiling(size/2, x_coordinate+size/2, y_coordinate);
		
			tromino[x_coordinate+size/2-1][y_coordinate+size/2] = current_tile;
			tromino[x_coordinate+size/2][y_coordinate+size/2] = current_tile;
			tromino[x_coordinate+size/2-1][y_coordinate+size/2-1] = current_tile;
			
			current_tile++;
		
			tromino_tiling(size/2, x_coordinate, y_coordinate);
			tromino_tiling(size/2, x_coordinate, y_coordinate+size/2);
			tromino_tiling(size/2, x_coordinate+size/2, y_coordinate+size/2);
		}
		else
		{			
			tromino_tiling(size/2, x_coordinate+size/2, y_coordinate+size/2);
			
			tromino[x_coordinate+size/2-1][y_coordinate+size/2] = current_tile;
			tromino[x_coordinate+size/2][y_coordinate+size/2-1] = current_tile;
			tromino[x_coordinate+size/2-1][y_coordinate+size/2-1] = current_tile;
			
			current_tile++;
			
			tromino_tiling(size/2, x_coordinate+size/2, y_coordinate);
			tromino_tiling(size/2, x_coordinate, y_coordinate+size/2);
			tromino_tiling(size/2, x_coordinate, y_coordinate);
		}	
	}		
} 
	
void print() 
{
	int i,j;
	for (i=0; i<actual_board_size; i++) 
	{
		for (j=0; j<actual_board_size; j++)
		{
			printf("%d\t",tromino[i][j]);
		}
		printf("\n");
	}
}
	
int main() 
{
	int x,y,size;
	srand(time(NULL));
	printf("Enter a number to build a tromino grid:(Number should be a power of 2):");
	scanf("%d",&size);
	
	printf("co-ordinates of the missing tile are:");
	x = rand() % size;
	y = rand() % size;
	printf("\nx-coordinate:%d\ny-coordinate%d\n",x,y);
	actual_board_size = 1;
	while (actual_board_size < size) actual_board_size*=2;
	
	current_tile = 1;
	int i,j;
	for (i=0; i<actual_board_size; i++) 
	{
		for (j=0; j<actual_board_size; j++)
		{
			tromino[i][j] = 0;
		}
	}
	tromino[x][y] = -1;

	tromino_tiling(actual_board_size, 0, 0);
	printf("Missing tile is represented by -1:\n");
	printf("Final tromino grid is as follows:\n");
	print();
	return 0;
}
