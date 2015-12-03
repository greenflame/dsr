#ifndef STRSET_H
#define STRSET_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct strset_s
{
	char data[100][100];
	int count;
} strset_t;

void strset_init(strset_t* set);
void strset_insert(strset_t* set, char* str);
void strset_print(strset_t* set);
int strset_contains(strset_t* set, char* str);

#endif