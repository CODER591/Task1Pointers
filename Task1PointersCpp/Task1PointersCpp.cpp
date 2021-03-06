// Task1 Pointers Cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

using namespace std;

#define PTR_SIZE sizeof(void*)
typedef unsigned usint;
//(*(node + 0))
//(*(node + 1))

void StringListInit(char** list)
{
	*list = NULL;
}


void StringListAdd(char** list, const char* str)
{
	if (*list!=NULL)	
	{
		usint* node = (usint*)*list;

		while ((*(node + 0)) != NULL)
			node = (usint*)(*(node + 0));

		usint* newNode = (usint*)malloc(PTR_SIZE * 2);
		if (newNode)
		{
			if ((*(newNode + 1)) = (usint)malloc(strlen(str) + 1))
			{
				strcpy((char*)(*(newNode + 1)), str);
				(*(newNode + 0)) = NULL;
				(*(node + 0)) = (usint)newNode;
			}
		}
	}
	else
	{
		usint* newNode = (usint*)malloc(PTR_SIZE * 2);
		if (newNode)
		{
			if ((*(newNode + 1)) = (usint)malloc(strlen(str) + 1))
			{
				strcpy((char*)(*(newNode + 1)), str);
				(*(newNode + 0)) = NULL;
			}
		}
		*list = (char*)newNode;
	}
}

void ListOut(char** list)
{
	printf("----------------\n");
	usint* node = (usint*)(*list);

	while (node != NULL)
	{
		char* str = (char*)(*(node + 1));
		printf("%s\n", str);
		printf("----------------\n");
		node = (usint*)(*(node + 0));
	}
	printf("\n");
}

usint StringListSize(char** list)
{
	usint* node = (usint*)(*list);
	usint count = 0;

	while (node != NULL)
	{
		++count;
		node = (usint*)(*(node + 0));
	}
	return count;
}

usint StringListIndexOf(char** list, const char* str)
{
	usint* node = (usint*)*list;
	usint count = 0;

	while (node != NULL)
	{
		if (strcmp((char*)(*(node + 1)), str) == 0)
			break;
		else
			count++;

		node = (usint*)(*(node + 0));
	}
	return (count == StringListSize(list)) ? -1 : count;
}


void StringListSort(char** list)		
{
	//vibir sorting
	usint tmp = 0;
	for (usint* node = (usint*)*list; (*(node + 0)) != NULL; node = (usint*)(*(node + 0)))
	{
		usint* node_min_element = node;
		for (usint* iter_node = (usint*)(*(node + 0)); iter_node != NULL; iter_node = (usint*)(*(iter_node + 0)))
		{
			if (strcmp((char*)(*(iter_node + 1)), (char*)(*(node_min_element + 1))) < 0)
				node_min_element = iter_node;
		}
		//swap of two strings
		tmp = (*(node + 1));
		(*(node + 1)) = (*(node_min_element + 1));
		(*(node_min_element + 1)) = tmp;
	}
}


void StringListReplaceInStrings(char** list, const char* before, const char* after)
{
	for (usint* node = (usint*)*list; node != NULL; node = (usint*)(*(node + 0)))
	{
		if (strcmp((char*)(*(node + 1)), before) == 0)
		{
			if ((*(node + 1)) = (usint)realloc((void*)(*(node + 1)), strlen(after) + 1))
				strcpy((char*)(*(node + 1)), after);
		}
	}
}

//+
void StringListDestroy(char** list)
{
	for (usint* node = (usint*)*list; node != NULL; node = (usint*)*list)
	{
		*list = (char*)(*(node + 0));

		free((void*)(*(node + 1)));
		free((void*)node);
	}
}


int main()
{
	char* List;
	StringListInit(&List);

	StringListAdd(&List, "a");
	StringListAdd(&List, "b");
	StringListAdd(&List, "c");
	StringListSort(&List);
	StringListReplaceInStrings(&List, "c", "lol");
	ListOut(&List);

	return 0;
}


