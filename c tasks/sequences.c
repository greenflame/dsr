#include <string.h>
#include <stdlib.h>
#include <stdio.h>

float vals[1000];
int dp[1000];
int count = 0;

int dpsolve()
{
	int totalMax = 0;
	
	for (int i = 0; i < count; i++)
	{
		int mx = 0;
		for (int j = 0; j < i; j++)
		{
			if (vals[j] <= vals[i])
			{
				mx = (dp[j] > mx ? dp[j] : mx);
			}
		}
		dp[i] = mx + 1;
		
		totalMax = totalMax < dp[i] ? dp[i] : totalMax;
	}
	
	return totalMax;
}

void printdp()
{
	for (int i = 0; i < count; i++)
	{
		printf("%f : %d\n", vals[i], dp[i]);
	}
	printf("-------------\n");
}

int main()
{
	// Reading strings
	FILE* fin = fopen("sequences.txt", "r");

	
	while(!feof(fin))
	{
		float tmp;
		fscanf(fin, "%f", &tmp);
		
		vals[count] = tmp;
		dp[count] = 0;
		count++;
	}
	count--;
	
	fclose(fin);
	
	int up = dpsolve();
	printdp();
	
	// Revert array
	for (int i = 0; i < count / 2; i++)
	{
		float tmp = vals[i];
		vals[i] = vals[count - i - 1];
		vals[count - i - 1] = tmp;
	}
	
	int down = dpsolve();
	printdp();
	
	printf("res: %d\n", up < down ? count - down : count - up);

	return 0;
}