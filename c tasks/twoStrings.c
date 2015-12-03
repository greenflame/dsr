#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "strset.h"

strset_t split_str(char* str)
{
	strset_t set;
	strset_init(&set);
	
	char* pch = strtok(str," ,.-");
	while (pch != NULL)
	{
		strset_insert(&set, pch);
		pch = strtok(NULL, " ,.-");
	}
	
	return set;
}

int go(char* toConstruct, strset_t* constrSet, char curState[1024])
{
	if (strcmp(toConstruct, curState) == 0)
	{
		return 1;
	}
	
	if (strlen(curState) > strlen(toConstruct))
	{
		return 0;
	}
	
	int canConstruct = 0;
	for (int i = 0; i < constrSet->count; i++)
	{
		char tmp[1024];
		strcpy(tmp, curState);
		strcat(tmp, constrSet->data[i]);
		if (go(toConstruct, constrSet, tmp))
		{
			canConstruct = 1;
			break;
		}
	}
	
	return canConstruct;
}

int main()
{
	// Reading strings
	FILE* fin = fopen("twoStrings.txt", "r");
	
	char str1[512], str2[512];
	fgets(str1, sizeof(str1), fin);
	fgets(str2, sizeof(str2), fin);
	*strchr(str1, '\n') = '\0'; 
	*strchr(str2, '\n') = '\0'; 
	
	fclose(fin);
	
	// Spliting
	strset_t set1 = split_str(str1);
	strset_t set2 = split_str(str2);
	
	char initState[1024];
	memset(initState, '\0', sizeof(initState));
	
	for (int i = 0; i < set2.count; i++)
	{
		printf("%d\n", go(set2.data[i], &set1, initState));
	}
	
	return 0;
}