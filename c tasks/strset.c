#include "strset.h"

void strset_init(strset_t* set)
{
	set->count = 0;
}

void strset_insert(strset_t* set, char* str)
{
	for (int i = 0; i < set->count; i++)
	{
		if (strcmp(set->data[i], str) == 0)
		{
			return;
		}
	}
	strcpy(set->data[set->count], str);
	set->count++;
}

void strset_print(strset_t* set)
{
	for (int i = 0; i < set->count; i++)
	{
		printf("%s\n", set->data[i]);
	}
}

int strset_contains(strset_t* set, char* str)
{
	for (int i = 0; i < set->count; i++)
	{
		if (strcmp(set->data[i], str) == 0)
		{
			return 1;
		}
	}
	return 0;
}