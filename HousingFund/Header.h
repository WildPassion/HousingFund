#include <conio.h>
#include <stdio.h>
#include <Windows.h>

#define MAX_SIZE 20

struct Fund
{
	size_t number = NULL;
	char *name = nullptr;
	char *surname = nullptr;
	char *address = nullptr;
	char *phone = nullptr;
};

struct FundArray
{
	Fund array[MAX_SIZE];
	size_t size = NULL;
};