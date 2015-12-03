#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float map[100][100];
int n;

void printmap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			printf("%f ", map[i][j]);
		}
		printf("\n");
	}
}

void lineMult(int line, float k)
{
	for (int i = 0; i < n + 1; i++)
	{
		map[line][i] *= k;
	}
}

void lineSub(int from, int what)
{
	for (int i = 0; i < n + 1; i++)
	{
		map[from][i] -= map[what][i];
	}
}

int main()
{
	FILE* fin = fopen("slau.txt", "r");
	
	fscanf(fin, "%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			float tmp;
			fscanf(fin, "%f", &tmp);
			map[i][j] = tmp;
		}
	}
	
	fclose(fin);
	
	// lineMult(0, 1.0/3.0);
	// lineSub(0, 1);
	// printmap();
	
	
	
	for (int i = n - 1; i >=0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			lineMult(j, 1.0 / map[j][i]);
		}
		
		for (int j = 0; j < i; j++)
		{
			lineSub(j, i);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			lineMult(j, 1.0 / map[j][i]);
		}
		
		for (int j = i + 1; j < n; j++)
		{
			lineSub(j, i);
		}
	}
	
	printmap();

	for (int i = 0; i < n; i++)
	{
		printf("x%d: %f\n", i + 1, map[i][n]);
	}

	return 0;
}
