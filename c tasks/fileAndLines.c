#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "strset.h"

int main()
{
	strset_t strset;
	strset_init(&strset);
	
	// Reading file 1
	FILE* file1 = fopen("fileAndLines1.txt", "r");	
	
	char buf[100];
	while (fgets(buf, sizeof(buf), file1) != NULL)
	{
		*strchr(buf, '\n') = '\0';
		strset_insert(&strset, buf);
	}
	
	fclose(file1);
	
	// Checking file 2
	FILE* file2 = fopen("fileAndLines2.txt", "r");
	
	int allFine = 1;
	while (fgets(buf, 100, file2) != NULL)
	{
		*strchr(buf, '\n') = '\0';
		if (!strset_contains(&strset, buf))
		{
			allFine = 0;
			break;
		}
	}
	
	fclose(file2);
	
	// Showing answer
	if (allFine)
	{
		printf("Yes. File 2 can be cunstructed from lines of first.\n");
	}
	else
	{
		printf("No. File 2 cann't be cunstructed from lines of first file.\n");		
	}
	
	return 0;
}
